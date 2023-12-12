#include <stdio.h>
#include <stdlib.h>
#include <glob.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

typedef struct {
    unsigned int w, h, size, micros;
    size_t frame_n;
    unsigned char fps;
    char* video_path;
    char* frame_buf;
    size_t buf_size;
} term_video;


void extract_frames(term_video* tv);
void exec_frame(term_video* tv);
bool exists(char* path);
void rmrf(char* path);
void make_frames_dir();
int get_frame_count();
char get_rand_char();
void load_frame(term_video* tv, char* frame_path);
void make_frame_path(char* buf, size_t i);

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <vidPath> <framerate> <width> <height>\n", argv[0]);
        return 1;
    }

    term_video tv;
    tv.video_path = argv[1];
    tv.fps = atoi(argv[2]);
    tv.w = atoi(argv[3]);
    tv.h = atoi(argv[4]);
    tv.size = tv.w * tv.h;
    tv.buf_size = tv.w * tv.h + tv.h;
    tv.micros = (1000 / tv.fps) * 1000; 
    char frame_buf_buf[tv.buf_size];
    tv.frame_buf = frame_buf_buf; 


    if (exists("build/temp.mp4")) remove("build/temp.mp4");
    remove("frames");
    make_frames_dir();
    extract_frames(&tv);
    tv.frame_n = get_frame_count();

    /*
    char* frame = "frames/140.png";
    char* frame2 = "frames/141.png";
    char* frame3 = "frames/142.png";
    char* frame4 = "frames/143.png";
    char* frame5 = "frames/144.png";
    char* frame6 = "frames/145.png";
    char* frame7 = "frames/146.png";
    char* frame8 = "frames/147.png";
    char* frame9 = "frames/148.png";
    char* frame10 = "frames/149.png";
    char* frame11 = "frames/150.png";
    char* frame12 = "frames/151.png";
    char* frame13 = "frames/152.png";
    char* frame14 = "frames/153.png";
    char* frame15 = "frames/154.png";
    char* frame16 = "frames/155.png";
    char* frame17 = "frames/156.png";
    char* frame18 = "frames/157.png";
    char* frame19 = "frames/158.png";
    char* frame20 = "frames/159.png";
    char* frame21 = "frames/160.png";
    char* frame22 = "frames/161.png";
    char* frame23 = "frames/162.png";
    char* frame24 = "frames/163.png";
    char* frame25 = "frames/164.png";
    char* frame26 = "frames/165.png";
    char* frame27 = "frames/166.png";
    char* frame28 = "frames/167.png";
    char* frame29 = "frames/168.png";
    char* frame30 = "frames/169.png";
    char* frame31 = "frames/170.png";
    char* frame32 = "frames/171.png";
    char* frame33 = "frames/172.png";
    char* frame34 = "frames/173.png";

    load_frame(&tv, frame);
    exec_frame(&tv);
    
    load_frame(&tv, frame2);
    exec_frame(&tv);

    load_frame(&tv, frame3);
    exec_frame(&tv);
    
    load_frame(&tv, frame4);
    exec_frame(&tv);

    load_frame(&tv, frame5);
    exec_frame(&tv);
    
    load_frame(&tv, frame6);
    exec_frame(&tv);

    load_frame(&tv, frame7);
    exec_frame(&tv);
    
    load_frame(&tv, frame8);
    exec_frame(&tv);

    load_frame(&tv, frame9);
    exec_frame(&tv);

    load_frame(&tv, frame10);
    exec_frame(&tv);

    load_frame(&tv, frame11);
    exec_frame(&tv);
    
    load_frame(&tv, frame12);
    exec_frame(&tv);

    load_frame(&tv, frame13);
    exec_frame(&tv);
    
    load_frame(&tv, frame14);
    exec_frame(&tv);

    load_frame(&tv, frame15);
    exec_frame(&tv);
    
    load_frame(&tv, frame16);
    exec_frame(&tv);

    load_frame(&tv, frame17);
    exec_frame(&tv);

    load_frame(&tv, frame18);
    exec_frame(&tv);

    load_frame(&tv, frame19);
    exec_frame(&tv);
    
    load_frame(&tv, frame20);
    exec_frame(&tv);

    load_frame(&tv, frame21);
    exec_frame(&tv);
    
    load_frame(&tv, frame22);
    exec_frame(&tv);

    load_frame(&tv, frame23);
    exec_frame(&tv);
    
    load_frame(&tv, frame24);
    exec_frame(&tv);

    load_frame(&tv, frame25);
    exec_frame(&tv);

    load_frame(&tv, frame26);
    exec_frame(&tv);

    load_frame(&tv, frame27);
    exec_frame(&tv);
    
    load_frame(&tv, frame28);
    exec_frame(&tv);

    load_frame(&tv, frame29);
    exec_frame(&tv);
    
    load_frame(&tv, frame30);
    exec_frame(&tv);

    load_frame(&tv, frame31);
    exec_frame(&tv);

    load_frame(&tv, frame32);
    exec_frame(&tv);

    load_frame(&tv, frame33);
    exec_frame(&tv);

    load_frame(&tv, frame34);
    exec_frame(&tv);
    */

    char path[12];
    for (int i = 1; i < tv.frame_n; i++) {
        make_frame_path(path, i);
        printf("\nFRAME PATH: %s\n", path);
        load_frame(&tv, path);
        exec_frame(&tv);
    }

    return 0;
}


void make_frame_path(char* buf, size_t i) {
    if (i < 10) sprintf(buf, "frames/00%d.png", i);
    else if (i < 100 && i > 9) sprintf(buf, "frames/0%d.png", i);
    else sprintf(buf, "frames/%d.png", i);
}


void load_frame(term_video* tv, char* frame_path) {
    int w, h, channels;
    unsigned char* img = stbi_load(frame_path, &w, &h, &channels, STBI_rgb_alpha);
    if (img == NULL) fprintf(stderr, "Could not load frame '%s'", frame_path);

    size_t buf_idx = 0;

    for (int i = 0; i < tv->size; i++) {
        if (i % tv->w == 0 && i != 0) 
            tv->frame_buf[buf_idx++] = '\n';
        if (img[i*4] <= 50 && img[i*4+1] <= 50 && img[i*4+2] <= 50) 
            tv->frame_buf[buf_idx++] = get_rand_char();
        else tv->frame_buf[buf_idx++] = 32;
    }

    tv->frame_buf[buf_idx++] = '\n';
    tv->frame_buf[buf_idx] = '\0';
    stbi_image_free(img);
}


void exec_frame(term_video* tv) {
    system("clear");
    fwrite(tv->frame_buf, sizeof(char), strlen(tv->frame_buf), stdout);
    fflush(stdout);
    sleep(3);
    //usleep(tv->micros);
}


char get_rand_char() {
    return (char) (rand() % (159 - 33 + 1)) + 33;
}


void extract_frames(term_video* tv) {
    char command[100];
    sprintf(command, "ffmpeg -i %s -vf \"fps=%d, scale=%d:%d\" ./frames/%%03d.png", tv->video_path, tv->fps, tv->w, tv->h);
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


