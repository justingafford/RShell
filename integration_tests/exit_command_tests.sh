#!/bin/sh
exit
exit ; echo this should not output ; echo error
echo exiting program; exit
ls && exit
mkdir fake; git status; ls; exit
vim newFile.cpp && ls || exit
