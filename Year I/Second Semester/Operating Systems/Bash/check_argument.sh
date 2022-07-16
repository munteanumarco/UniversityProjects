#!/bin/bash

for A in $@; do
	if [ -f "$A" ]; then
		echo "$A It is a file"
	elif [ -d "$A" ]; then
		echo "It is a directory man"
		echo "Here is the content:"
		for C in `find $A`; do
			echo  `cat $C | sha1sum`
		done
	else
		echo "$A I dunno what this is :("
	fi
done


