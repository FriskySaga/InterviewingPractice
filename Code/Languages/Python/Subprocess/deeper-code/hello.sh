#!/bin/bash
title='Simulator'
# echo -e interprets certain sequences in the string given
# \033 is an escape character to use ]
# ] is an Xterm parlance to preface an operating system command
# 2 changes the Window Title
# \007 is a special character that terminates the string
echo -e '\033]2;'$title'\007'
echo 'Testing my Linux world!'
sleep 2