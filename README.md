# Godsays 
My own interpretation of "Godsays" by [Terry A.Davis](https://en.wikipedia.org/wiki/Terry_A._Davis). - Written in C.

## Installation
First of all, you need to have make and gcc installed on your computer. If you are unsure then just execute the following code (adapt it to your distro)
```bash
sudo pacman -S --needed gcc make

```
Then, we do the following
```bash
cd	# This is for going to your home, you can change that if you want
mkdir godsays-repo	# the name of the directory to clone this repo 
cd godsays-repo
git clone https://github.com/SrCiocco/godsays.git
cd godsays
make

```
Once you do that, you can run the program going to "build/"
```bash
cd build
./godsays
```
## Things that i plan to do:
- [ ] Read words from a file instead of an array.
- ...
