# TERMPLAY
Reproduce any video on the terminal

## Dependencies
* Linux system
* gcc
* ffmpeg
* ncurses
  
## Installation 
1. Cloning the repo:
```bash
git clone https://github.com/LuckyToaster/termplay.git
```
2. To Compile:
```bash
cd termplay
make
``` 
3. To install system-wide and grant execution priviledges to executable:
```bash
sudo cp build/termpplay /usr/local/bin
sudo chmod +x /usr/local/bin/termplay
```

## Running
```bash
make run <args...>
```
To run with make (only works from the repository directory). For example a path to a video, fps, width and height arguments are required and the program is run with make like: 
```bash
make run path=<path> fps=<fps> w=<width> h=<height
```
__Or__ by running the executable either on the cloned repo directory or anywhere if installed system-wide (installation instruction 3). The order matters and the arguments must be given like this:
```bash
./termplay <video_path> <fps> <w> <h>
```

## Uninstalling
To remove the cloned repo:
```bash 
rm -rf <cloned repository directory
```
And to remove the executable from the /usr/bin folder
```bash 
sudo rm /usr/local/bin/termplay
```
