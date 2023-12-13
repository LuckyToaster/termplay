#include <stdio.h>
#include <stdlib.h>
#include <glob.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <ncurses.h>

typedef struct {
    unsigned int w, h, size, micros;
    size_t frame_n;
    unsigned char fps;
    char* video_path;
    char* frame_buf;
    size_t buf_size;
} term_video;


void extract_frames(term_video* restrict v);
void load_frame(term_video* restrict v, char* frame_path);
void exec_frame(term_video* restrict v);
bool exists(char* path);
void rmrf(char* path);
void make_frames_dir();
int get_frame_count();
char get_rand_char();
void make_frame_path(char* buf, size_t i);
void load_and_exec_frames(term_video* v, char *path, size_t idx);


int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <vidPath> <framerate> <width> <height>\n", argv[0]);
        return 1;
    }

    term_video v;
    v.video_path = argv[1];
    v.fps = atoi(argv[2]);
    v.w = atoi(argv[3]);
    v.h = atoi(argv[4]);
    v.size = v.w * v.h;
    v.buf_size = v.w * v.h + v.h;
    v.micros = (1000 / v.fps) * 1000; 
    char frame_buf_buf[v.buf_size];
    v.frame_buf = frame_buf_buf; 

    if (exists("build/temp.mp4")) remove("build/temp.mp4");
    rmrf("frames");
    make_frames_dir();
    extract_frames(&v);
    v.frame_n = get_frame_count();

    initscr();
    char path[20];
    load_and_exec_frames(&v, path, 1);
    endwin();

    return 0;
}


void load_and_exec_frames(term_video* v, char *path, size_t idx) {
    if (idx > v->frame_n) return;
    make_frame_path(path, idx);
    load_frame(v, path);
    exec_frame(v);
    load_and_exec_frames(v, path, ++idx);
}


void make_frame_path(char* buf, size_t i) {
    if (i < 10) sprintf(buf, "frames/00%d.png\0", i);
    else if (i < 100 && i > 9) sprintf(buf, "frames/0%d.png\0", i);
    else sprintf(buf, "frames/%d.png\0", i);
}


void load_frame(term_video* restrict v, char* restrict frame_path) {
    int w, h, channels;
    unsigned char* img = stbi_load(frame_path, &w, &h, &channels, STBI_rgb_alpha);
    if (img == NULL) fprintf(stderr, "Could not load frame '%s'", frame_path);

    size_t buf_idx = 0;
    for (int i = 0; i < v->size; i++) {
        if (i % v->w == 0 && i != 0) 
            v->frame_buf[buf_idx++] = '\n';
        if (img[i*4] <= 50 && img[i*4+1] <= 50 && img[i*4+2] <= 50) 
            v->frame_buf[buf_idx++] = '0'; // if i use get_rand_char() it shits the bed
        else v->frame_buf[buf_idx++] = 32;
    }

    v->frame_buf[buf_idx++] = '\n';
    v->frame_buf[buf_idx] = '\0';
    stbi_image_free(img);
}


void exec_frame(term_video* restrict v) {
    erase();
    printw(v->frame_buf);
    refresh();
    usleep(v->micros);
}


// fix the range or find out why this doesn't work
char get_rand_char() {
    return (char) (rand() % (159 - 33 + 1)) + 33;
}


void extract_frames(term_video* restrict v) {
    char command[100];
    sprintf(command, "ffmpeg -i %s -vf \"fps=%d, scale=%d:%d\" ./frames/%%03d.png", v->video_path, v->fps, v->w, v->h);
    if (system(command) == -1)
        fprintf(stderr, "Could not extract the frames with the desired characteristics");
}


void make_frames_dir() {
    if (system("mkdir -p frames") == -1) 
        fprintf(stderr, "Cannot make frames directory");
}


void rmrf(char* path) {
    char command[100];
    sprintf(command, "rm -rf %s", path);
    if (system(command) == -1)
        fprintf(stderr, "Could not remove '%s'", path);
}


int get_frame_count() {
    glob_t glob_result;
    int result = glob("./frames/*.png", 0, NULL, &glob_result);
    if (result != 0) {
        printf("Error in glob\n");
        return 1;
    }
    int res = glob_result.gl_pathc;
    globfree(&glob_result);
    return res;
}


bool exists(char* path) {
    if (access(path, F_OK) != -1) return true;
    else return false;
}


