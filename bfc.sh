#! /usr/bin/bash

currpath=${PWD##*/}
pathIn=$currpath+"$1"
pathOut=$currpath+"$2"

source ~/Desktop/bfc/bfcompiler $pathIn

pathInLength=${#pathIn}
pathCPP=${pathIn:0:pathInLength-3}
pathCPP+=".cpp"

g++ $pathCPP -o $pathOut

rm $pathCPP