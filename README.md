# TERMPLAY
Reproduce any video on the terminal

### Dependencies
* Linux system
* gcc
* ffmpeg
* ncurses
  
### Installation 
1. ```git clone https://github.com/LuckyToaster/ncurses_video_player.git```
2. ```make``` To compile
3. ```sudo cp build/termpplay /usr/local/bin```
4. ```sudo chmod +x /usr/local/bin/termplay```

### Running
* ```make run <args...>``` to run with make (only works from the repository directory). For example a path to a video, fps, width and height arguments are required and the program is run with make like: ```make run path=<path> fps=<fps> w=<width> h=<height```
* __Or__ by running the executable ```./termplay``` either on the cloned repo directory or anywhere if installed system-wide (installation instructions 3 and 4). The arguments must be given like this: ```./termplay <video_path> <fps> <w> <h>``` the order matters.

### Uninstalling
* ```rm -rf <cloned repository directory``` removing the cloned repo
* ```sudo rm /usr/local/bin/termplay``` removing executable from /usr/bin folder
