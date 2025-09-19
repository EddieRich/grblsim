#!/usr/bin/bash

if command -v socat &> /dev/null; then
	echo "found socat"
else
	echo "installing socat"
	sudo apt install socat -y
fi

sudo socat -d -d PTY,link=/dev/ttysim,user=ed,group=dialout,mode=660,raw,echo=0 PTY,link=/dev/ttyUSB9,user=ed,group=dialout,mode=660,raw,echo=0
