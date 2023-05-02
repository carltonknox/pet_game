# pet_game
### A Qt-based pet game and screensaver written in C++, along with a linux kernel module, targeting the Beagleboard BeagleBone Black
Final Project for EC535: Embedded Systems, by Carlton Knox and Raina Yin

Prerequisites:
* c/c++ compilers for your target system
* qmake
* (optional) Qt creator community

To build the game, run:
```
qmake pet_game.pro
make
```
Then run it with: ```./pet_game```

To build the screensaver, run:
```
qmake pet_game_screensaver.proo
make
```
and then build the screensaver kernel module with:
```
make -C kernel_module
```
To run the screensaver, copy `./kernelmodule/kscreensaverlauncher.ko` and `./pet_game_screensaver` to your target linux system, then run:
`
chmod +x ./pet_game_screensaver
mknod /dev/kscreensaverlauncher c 61 0
insmod ./kscreensaverlauncher.ko
`

This screensaver is assuming that you have an input device corresponding to `/dev/input/event0`. After 15 seconds of no activity, the screensaver will launch.
To stop the kernel module, run
```
rmmod ./kscreensaverlauncher.ko
```


Art by Raina Yin.
