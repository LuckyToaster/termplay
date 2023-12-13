CC = gcc
SRC_DIR = src
BUILD_DIR = build
FRAMES_DIR = frames
TARGET = $(BUILD_DIR)/bad_apple
STB_IMAGE_H = src/stb_image.h
SRCS = $(wildcard $(SRC_DIR)/*.c)

# lm is for including math library, otherwise i get error
# -lncurses to link the ncurses lib
$(TARGET): $(SRCS)
	mkdir -p $(BUILD_DIR)
	$(CC) $^ -o $@ -I $(SRC_DIR) -lm -lncurses

run: $(TARGET)
	$(TARGET) $(path) $(fps) $(w) $(h)

run_noargs: $(TARGET)
	$(TARGET) ba.mp4 12 200 150

clean:
	rm -rf $(BUILD_DIR) $(FRAMES_DIR)

.PHONY: clean
