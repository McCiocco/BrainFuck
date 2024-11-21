#! /usr/bin/bash

currpath=$(pwd)
pathIn=$currpath"/"$1
pathOut=$currpath"/"$2

/home/ciocco/Desktop/bfc/bfcompiler $pathIn
cd $currpath

pathInLength=${#pathIn}
pathCPP=${pathIn:0:pathInLength-3}
pathCPP=$pathCPP".cpp"

g++ $pathCPP -o $pathOut

rm $pathCPP