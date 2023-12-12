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

    load_frame(&tv, "frames/001.png"); exec_frame(&tv);
    load_frame(&tv, "frames/002.png"); exec_frame(&tv);
    load_frame(&tv, "frames/003.png"); exec_frame(&tv);
    load_frame(&tv, "frames/004.png"); exec_frame(&tv);
    load_frame(&tv, "frames/005.png"); exec_frame(&tv);
    load_frame(&tv, "frames/006.png"); exec_frame(&tv);
    load_frame(&tv, "frames/007.png"); exec_frame(&tv);
    load_frame(&tv, "frames/008.png"); exec_frame(&tv);
    load_frame(&tv, "frames/009.png"); exec_frame(&tv);
    load_frame(&tv, "frames/010.png"); exec_frame(&tv);
    load_frame(&tv, "frames/011.png"); exec_frame(&tv);
    load_frame(&tv, "frames/012.png"); exec_frame(&tv);
    load_frame(&tv, "frames/013.png"); exec_frame(&tv);
    load_frame(&tv, "frames/014.png"); exec_frame(&tv);
    load_frame(&tv, "frames/015.png"); exec_frame(&tv);
    load_frame(&tv, "frames/016.png"); exec_frame(&tv);
    load_frame(&tv, "frames/017.png"); exec_frame(&tv);
    load_frame(&tv, "frames/018.png"); exec_frame(&tv);
    load_frame(&tv, "frames/019.png"); exec_frame(&tv);
    load_frame(&tv, "frames/020.png"); exec_frame(&tv);
    load_frame(&tv, "frames/021.png"); exec_frame(&tv);
    load_frame(&tv, "frames/022.png"); exec_frame(&tv);
    load_frame(&tv, "frames/023.png"); exec_frame(&tv);
    load_frame(&tv, "frames/024.png"); exec_frame(&tv);
    load_frame(&tv, "frames/025.png"); exec_frame(&tv);
    load_frame(&tv, "frames/026.png"); exec_frame(&tv);
    load_frame(&tv, "frames/027.png"); exec_frame(&tv);
    load_frame(&tv, "frames/028.png"); exec_frame(&tv);
    load_frame(&tv, "frames/029.png"); exec_frame(&tv);
    load_frame(&tv, "frames/030.png"); exec_frame(&tv);
    load_frame(&tv, "frames/031.png"); exec_frame(&tv);
    load_frame(&tv, "frames/032.png"); exec_frame(&tv);
    load_frame(&tv, "frames/033.png"); exec_frame(&tv);
    load_frame(&tv, "frames/034.png"); exec_frame(&tv);
    load_frame(&tv, "frames/035.png"); exec_frame(&tv);
    load_frame(&tv, "frames/036.png"); exec_frame(&tv);
    load_frame(&tv, "frames/037.png"); exec_frame(&tv);
    load_frame(&tv, "frames/038.png"); exec_frame(&tv);
    load_frame(&tv, "frames/039.png"); exec_frame(&tv);
    load_frame(&tv, "frames/040.png"); exec_frame(&tv);
    load_frame(&tv, "frames/041.png"); exec_frame(&tv);
    load_frame(&tv, "frames/042.png"); exec_frame(&tv);
    load_frame(&tv, "frames/043.png"); exec_frame(&tv);
    load_frame(&tv, "frames/044.png"); exec_frame(&tv);
    load_frame(&tv, "frames/045.png"); exec_frame(&tv);
    load_frame(&tv, "frames/046.png"); exec_frame(&tv);
    load_frame(&tv, "frames/047.png"); exec_frame(&tv);
    load_frame(&tv, "frames/048.png"); exec_frame(&tv);
    load_frame(&tv, "frames/049.png"); exec_frame(&tv);
    load_frame(&tv, "frames/050.png"); exec_frame(&tv);
    load_frame(&tv, "frames/051.png"); exec_frame(&tv);
    load_frame(&tv, "frames/052.png"); exec_frame(&tv);
    load_frame(&tv, "frames/053.png"); exec_frame(&tv);
    load_frame(&tv, "frames/054.png"); exec_frame(&tv);
    load_frame(&tv, "frames/055.png"); exec_frame(&tv);
    load_frame(&tv, "frames/056.png"); exec_frame(&tv);
    load_frame(&tv, "frames/057.png"); exec_frame(&tv);
    load_frame(&tv, "frames/058.png"); exec_frame(&tv);
    load_frame(&tv, "frames/059.png"); exec_frame(&tv);
    load_frame(&tv, "frames/060.png"); exec_frame(&tv);
    load_frame(&tv, "frames/061.png"); exec_frame(&tv);
    load_frame(&tv, "frames/062.png"); exec_frame(&tv);
    load_frame(&tv, "frames/063.png"); exec_frame(&tv);
    load_frame(&tv, "frames/064.png"); exec_frame(&tv);
    load_frame(&tv, "frames/065.png"); exec_frame(&tv);
    load_frame(&tv, "frames/066.png"); exec_frame(&tv);
    load_frame(&tv, "frames/067.png"); exec_frame(&tv);
    load_frame(&tv, "frames/068.png"); exec_frame(&tv);
    load_frame(&tv, "frames/069.png"); exec_frame(&tv);
    load_frame(&tv, "frames/070.png"); exec_frame(&tv);
    load_frame(&tv, "frames/071.png"); exec_frame(&tv);
    load_frame(&tv, "frames/072.png"); exec_frame(&tv);
    load_frame(&tv, "frames/073.png"); exec_frame(&tv);
    load_frame(&tv, "frames/074.png"); exec_frame(&tv);
    load_frame(&tv, "frames/075.png"); exec_frame(&tv);
    load_frame(&tv, "frames/076.png"); exec_frame(&tv);
    load_frame(&tv, "frames/077.png"); exec_frame(&tv);
    load_frame(&tv, "frames/078.png"); exec_frame(&tv);
    load_frame(&tv, "frames/079.png"); exec_frame(&tv);
    load_frame(&tv, "frames/080.png"); exec_frame(&tv);
    load_frame(&tv, "frames/081.png"); exec_frame(&tv);
    load_frame(&tv, "frames/082.png"); exec_frame(&tv);
    load_frame(&tv, "frames/083.png"); exec_frame(&tv);
    load_frame(&tv, "frames/084.png"); exec_frame(&tv);
    load_frame(&tv, "frames/085.png"); exec_frame(&tv);
    load_frame(&tv, "frames/086.png"); exec_frame(&tv);
    load_frame(&tv, "frames/087.png"); exec_frame(&tv);
    load_frame(&tv, "frames/088.png"); exec_frame(&tv);
    load_frame(&tv, "frames/089.png"); exec_frame(&tv);
    load_frame(&tv, "frames/090.png"); exec_frame(&tv);
    load_frame(&tv, "frames/091.png"); exec_frame(&tv);
    load_frame(&tv, "frames/092.png"); exec_frame(&tv);
    load_frame(&tv, "frames/093.png"); exec_frame(&tv);
    load_frame(&tv, "frames/094.png"); exec_frame(&tv);
    load_frame(&tv, "frames/095.png"); exec_frame(&tv);
    load_frame(&tv, "frames/096.png"); exec_frame(&tv);
    load_frame(&tv, "frames/097.png"); exec_frame(&tv);
    load_frame(&tv, "frames/098.png"); exec_frame(&tv);
    load_frame(&tv, "frames/099.png"); exec_frame(&tv);
    load_frame(&tv, "frames/100.png"); exec_frame(&tv);
    load_frame(&tv, "frames/101.png"); exec_frame(&tv);
    load_frame(&tv, "frames/102.png"); exec_frame(&tv);
    load_frame(&tv, "frames/103.png"); exec_frame(&tv);
    load_frame(&tv, "frames/104.png"); exec_frame(&tv);
    load_frame(&tv, "frames/105.png"); exec_frame(&tv);
    load_frame(&tv, "frames/106.png"); exec_frame(&tv);
    load_frame(&tv, "frames/107.png"); exec_frame(&tv);
    load_frame(&tv, "frames/108.png"); exec_frame(&tv);
    load_frame(&tv, "frames/109.png"); exec_frame(&tv);
    load_frame(&tv, "frames/110.png"); exec_frame(&tv);
    load_frame(&tv, "frames/111.png"); exec_frame(&tv);
    load_frame(&tv, "frames/112.png"); exec_frame(&tv);
    load_frame(&tv, "frames/113.png"); exec_frame(&tv);
    load_frame(&tv, "frames/114.png"); exec_frame(&tv);
    load_frame(&tv, "frames/115.png"); exec_frame(&tv);
    load_frame(&tv, "frames/116.png"); exec_frame(&tv);
    load_frame(&tv, "frames/117.png"); exec_frame(&tv);
    load_frame(&tv, "frames/118.png"); exec_frame(&tv);
    load_frame(&tv, "frames/119.png"); exec_frame(&tv);
    load_frame(&tv, "frames/120.png"); exec_frame(&tv);
    load_frame(&tv, "frames/121.png"); exec_frame(&tv);
    load_frame(&tv, "frames/122.png"); exec_frame(&tv);
    load_frame(&tv, "frames/123.png"); exec_frame(&tv);
    load_frame(&tv, "frames/124.png"); exec_frame(&tv);
    load_frame(&tv, "frames/125.png"); exec_frame(&tv);
    load_frame(&tv, "frames/126.png"); exec_frame(&tv);
    load_frame(&tv, "frames/127.png"); exec_frame(&tv);
    load_frame(&tv, "frames/128.png"); exec_frame(&tv);
    load_frame(&tv, "frames/129.png"); exec_frame(&tv);
    load_frame(&tv, "frames/130.png"); exec_frame(&tv);
    load_frame(&tv, "frames/131.png"); exec_frame(&tv);
    load_frame(&tv, "frames/132.png"); exec_frame(&tv);
    load_frame(&tv, "frames/133.png"); exec_frame(&tv);
    load_frame(&tv, "frames/134.png"); exec_frame(&tv);
    load_frame(&tv, "frames/135.png"); exec_frame(&tv);
    load_frame(&tv, "frames/136.png"); exec_frame(&tv);
    load_frame(&tv, "frames/137.png"); exec_frame(&tv);
    load_frame(&tv, "frames/138.png"); exec_frame(&tv);
    load_frame(&tv, "frames/139.png"); exec_frame(&tv);
    load_frame(&tv, "frames/140.png"); exec_frame(&tv);
    load_frame(&tv, "frames/141.png"); exec_frame(&tv);
    load_frame(&tv, "frames/142.png"); exec_frame(&tv);
    load_frame(&tv, "frames/143.png"); exec_frame(&tv);
    load_frame(&tv, "frames/144.png"); exec_frame(&tv);
    load_frame(&tv, "frames/145.png"); exec_frame(&tv);
    load_frame(&tv, "frames/146.png"); exec_frame(&tv);
    load_frame(&tv, "frames/147.png"); exec_frame(&tv);
    load_frame(&tv, "frames/148.png"); exec_frame(&tv);
    load_frame(&tv, "frames/149.png"); exec_frame(&tv);
    load_frame(&tv, "frames/150.png"); exec_frame(&tv);
    load_frame(&tv, "frames/151.png"); exec_frame(&tv);
    load_frame(&tv, "frames/152.png"); exec_frame(&tv);
    load_frame(&tv, "frames/153.png"); exec_frame(&tv);
    load_frame(&tv, "frames/154.png"); exec_frame(&tv);
    load_frame(&tv, "frames/155.png"); exec_frame(&tv);
    load_frame(&tv, "frames/156.png"); exec_frame(&tv);
    load_frame(&tv, "frames/157.png"); exec_frame(&tv);
    load_frame(&tv, "frames/158.png"); exec_frame(&tv);
    load_frame(&tv, "frames/159.png"); exec_frame(&tv);
    load_frame(&tv, "frames/160.png"); exec_frame(&tv);
    load_frame(&tv, "frames/161.png"); exec_frame(&tv);
    load_frame(&tv, "frames/162.png"); exec_frame(&tv);
    load_frame(&tv, "frames/163.png"); exec_frame(&tv);
    load_frame(&tv, "frames/164.png"); exec_frame(&tv);
    load_frame(&tv, "frames/165.png"); exec_frame(&tv);
    load_frame(&tv, "frames/166.png"); exec_frame(&tv);
    load_frame(&tv, "frames/167.png"); exec_frame(&tv);
    load_frame(&tv, "frames/168.png"); exec_frame(&tv);
    load_frame(&tv, "frames/169.png"); exec_frame(&tv);
    load_frame(&tv, "frames/170.png"); exec_frame(&tv);
    load_frame(&tv, "frames/171.png"); exec_frame(&tv);
    load_frame(&tv, "frames/172.png"); exec_frame(&tv);
    load_frame(&tv, "frames/173.png"); exec_frame(&tv);
    load_frame(&tv, "frames/174.png"); exec_frame(&tv);
    load_frame(&tv, "frames/175.png"); exec_frame(&tv);
    load_frame(&tv, "frames/176.png"); exec_frame(&tv);
    load_frame(&tv, "frames/177.png"); exec_frame(&tv);
    load_frame(&tv, "frames/178.png"); exec_frame(&tv);
    load_frame(&tv, "frames/179.png"); exec_frame(&tv);
    load_frame(&tv, "frames/180.png"); exec_frame(&tv);
    load_frame(&tv, "frames/181.png"); exec_frame(&tv);
    load_frame(&tv, "frames/182.png"); exec_frame(&tv);
    load_frame(&tv, "frames/183.png"); exec_frame(&tv);
    load_frame(&tv, "frames/184.png"); exec_frame(&tv);
    load_frame(&tv, "frames/185.png"); exec_frame(&tv);
    load_frame(&tv, "frames/186.png"); exec_frame(&tv);
    load_frame(&tv, "frames/187.png"); exec_frame(&tv);
    load_frame(&tv, "frames/188.png"); exec_frame(&tv);
    load_frame(&tv, "frames/189.png"); exec_frame(&tv);
    load_frame(&tv, "frames/190.png"); exec_frame(&tv);
    load_frame(&tv, "frames/191.png"); exec_frame(&tv);
    load_frame(&tv, "frames/192.png"); exec_frame(&tv);
    load_frame(&tv, "frames/193.png"); exec_frame(&tv);
    load_frame(&tv, "frames/194.png"); exec_frame(&tv);
    load_frame(&tv, "frames/195.png"); exec_frame(&tv);
    load_frame(&tv, "frames/196.png"); exec_frame(&tv);
    load_frame(&tv, "frames/197.png"); exec_frame(&tv);
    load_frame(&tv, "frames/198.png"); exec_frame(&tv);
    load_frame(&tv, "frames/199.png"); exec_frame(&tv);
    load_frame(&tv, "frames/200.png"); exec_frame(&tv);
    load_frame(&tv, "frames/201.png"); exec_frame(&tv);
    load_frame(&tv, "frames/202.png"); exec_frame(&tv);
    load_frame(&tv, "frames/203.png"); exec_frame(&tv);
    load_frame(&tv, "frames/204.png"); exec_frame(&tv);
    load_frame(&tv, "frames/205.png"); exec_frame(&tv);
    load_frame(&tv, "frames/206.png"); exec_frame(&tv);
    load_frame(&tv, "frames/207.png"); exec_frame(&tv);
    load_frame(&tv, "frames/208.png"); exec_frame(&tv);
    load_frame(&tv, "frames/209.png"); exec_frame(&tv);
    load_frame(&tv, "frames/210.png"); exec_frame(&tv);
    load_frame(&tv, "frames/211.png"); exec_frame(&tv);
    load_frame(&tv, "frames/212.png"); exec_frame(&tv);
    load_frame(&tv, "frames/213.png"); exec_frame(&tv);
    load_frame(&tv, "frames/214.png"); exec_frame(&tv);
    load_frame(&tv, "frames/215.png"); exec_frame(&tv);
    load_frame(&tv, "frames/216.png"); exec_frame(&tv);
    load_frame(&tv, "frames/217.png"); exec_frame(&tv);
    load_frame(&tv, "frames/218.png"); exec_frame(&tv);
    load_frame(&tv, "frames/219.png"); exec_frame(&tv);
    load_frame(&tv, "frames/220.png"); exec_frame(&tv);
    load_frame(&tv, "frames/221.png"); exec_frame(&tv);
    load_frame(&tv, "frames/222.png"); exec_frame(&tv);
    load_frame(&tv, "frames/223.png"); exec_frame(&tv);
    load_frame(&tv, "frames/224.png"); exec_frame(&tv);
    load_frame(&tv, "frames/225.png"); exec_frame(&tv);
    load_frame(&tv, "frames/226.png"); exec_frame(&tv);
    load_frame(&tv, "frames/227.png"); exec_frame(&tv);
    load_frame(&tv, "frames/228.png"); exec_frame(&tv);
    load_frame(&tv, "frames/229.png"); exec_frame(&tv);
    load_frame(&tv, "frames/230.png"); exec_frame(&tv);
    load_frame(&tv, "frames/231.png"); exec_frame(&tv);
    load_frame(&tv, "frames/232.png"); exec_frame(&tv);
    load_frame(&tv, "frames/233.png"); exec_frame(&tv);
    load_frame(&tv, "frames/234.png"); exec_frame(&tv);
    load_frame(&tv, "frames/235.png"); exec_frame(&tv);
    load_frame(&tv, "frames/236.png"); exec_frame(&tv);
    load_frame(&tv, "frames/237.png"); exec_frame(&tv);
    load_frame(&tv, "frames/238.png"); exec_frame(&tv);
    load_frame(&tv, "frames/239.png"); exec_frame(&tv);
    load_frame(&tv, "frames/240.png"); exec_frame(&tv);
    load_frame(&tv, "frames/241.png"); exec_frame(&tv);
    load_frame(&tv, "frames/242.png"); exec_frame(&tv);
    load_frame(&tv, "frames/243.png"); exec_frame(&tv);
    load_frame(&tv, "frames/244.png"); exec_frame(&tv);
    load_frame(&tv, "frames/245.png"); exec_frame(&tv);
    load_frame(&tv, "frames/246.png"); exec_frame(&tv);
    load_frame(&tv, "frames/247.png"); exec_frame(&tv);
    load_frame(&tv, "frames/248.png"); exec_frame(&tv);
    load_frame(&tv, "frames/249.png"); exec_frame(&tv);
    load_frame(&tv, "frames/250.png"); exec_frame(&tv);
    load_frame(&tv, "frames/251.png"); exec_frame(&tv);
    load_frame(&tv, "frames/252.png"); exec_frame(&tv);
    load_frame(&tv, "frames/253.png"); exec_frame(&tv);
    load_frame(&tv, "frames/254.png"); exec_frame(&tv);
    load_frame(&tv, "frames/255.png"); exec_frame(&tv);
    load_frame(&tv, "frames/256.png"); exec_frame(&tv);
    load_frame(&tv, "frames/257.png"); exec_frame(&tv);
    load_frame(&tv, "frames/258.png"); exec_frame(&tv);
    load_frame(&tv, "frames/259.png"); exec_frame(&tv);
    load_frame(&tv, "frames/260.png"); exec_frame(&tv);
    load_frame(&tv, "frames/261.png"); exec_frame(&tv);
    load_frame(&tv, "frames/262.png"); exec_frame(&tv);
    load_frame(&tv, "frames/263.png"); exec_frame(&tv);
    load_frame(&tv, "frames/264.png"); exec_frame(&tv);
    load_frame(&tv, "frames/265.png"); exec_frame(&tv);
    load_frame(&tv, "frames/266.png"); exec_frame(&tv);
    load_frame(&tv, "frames/267.png"); exec_frame(&tv);
    load_frame(&tv, "frames/268.png"); exec_frame(&tv);
    load_frame(&tv, "frames/269.png"); exec_frame(&tv);
    load_frame(&tv, "frames/270.png"); exec_frame(&tv);
    load_frame(&tv, "frames/271.png"); exec_frame(&tv);
    load_frame(&tv, "frames/272.png"); exec_frame(&tv);
    load_frame(&tv, "frames/273.png"); exec_frame(&tv);
    load_frame(&tv, "frames/274.png"); exec_frame(&tv);
    load_frame(&tv, "frames/275.png"); exec_frame(&tv);
    load_frame(&tv, "frames/276.png"); exec_frame(&tv);
    load_frame(&tv, "frames/277.png"); exec_frame(&tv);
    load_frame(&tv, "frames/278.png"); exec_frame(&tv);
    load_frame(&tv, "frames/279.png"); exec_frame(&tv);
    load_frame(&tv, "frames/280.png"); exec_frame(&tv);
    load_frame(&tv, "frames/281.png"); exec_frame(&tv);
    load_frame(&tv, "frames/282.png"); exec_frame(&tv);
    load_frame(&tv, "frames/283.png"); exec_frame(&tv);
    load_frame(&tv, "frames/284.png"); exec_frame(&tv);
    load_frame(&tv, "frames/285.png"); exec_frame(&tv);
    load_frame(&tv, "frames/286.png"); exec_frame(&tv);
    load_frame(&tv, "frames/287.png"); exec_frame(&tv);
    load_frame(&tv, "frames/288.png"); exec_frame(&tv);
    load_frame(&tv, "frames/289.png"); exec_frame(&tv);
    load_frame(&tv, "frames/290.png"); exec_frame(&tv);
    load_frame(&tv, "frames/291.png"); exec_frame(&tv);
    load_frame(&tv, "frames/292.png"); exec_frame(&tv);
    load_frame(&tv, "frames/293.png"); exec_frame(&tv);
    load_frame(&tv, "frames/294.png"); exec_frame(&tv);
    load_frame(&tv, "frames/295.png"); exec_frame(&tv);
    load_frame(&tv, "frames/296.png"); exec_frame(&tv);
    load_frame(&tv, "frames/297.png"); exec_frame(&tv);
    load_frame(&tv, "frames/298.png"); exec_frame(&tv);
    load_frame(&tv, "frames/299.png"); exec_frame(&tv);
    load_frame(&tv, "frames/300.png"); exec_frame(&tv);

    char path[12];
    for (int i = 1; i < tv.frame_n; i++) {
        make_frame_path(path, i);
        //printf("FRAME PATH: %s\n", path);
        load_frame(&tv, path);
        exec_frame(&tv);
    }

    return 0;
}


void make_frame_path(char* buf, size_t i) {
    if (i < 10) sprintf(buf, "frames/00%d.png\0", i);
    else if (i < 100 && i > 9) sprintf(buf, "frames/0%d.png\0", i);
    else sprintf(buf, "frames/%d.png\0", i);
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
    usleep(tv->micros);
    fflush(stdout);
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


