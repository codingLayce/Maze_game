#!/bin/bash

find ./ -name '*.c' > ./all.txt 

while IFS="" read -r line || [ -n "$p" ]
do
	echo $line
echo "/**
* ENSICAEN
* 6 Boulevard Maréchal Juin
* F-14050 Caen Cedex
*
* This file is owned by ENSICAEN students. No portion of this
* documents may be reproduced, copied or revised without written
* permission of the authors.
*
* @author Lucas Guilbert <lguilbert@ecole.ensicaen.fr>
* @version 1.0
*
*/
" | cat - $line > ./tmp.c
	mv tmp.c $line
done < ./all.txt
