#!/bin/bash

ls ~/Music > music.list 

cd 	~/Music

mplayer -loop 0 -playlist music.list < /dev/null > /dev/null 2>&1 &
