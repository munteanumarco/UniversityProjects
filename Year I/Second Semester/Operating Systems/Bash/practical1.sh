#!/bin/bash

for A in $@
do
	if [ -f "$A" ]
	then	
		S=`du -b $A | awk '{print $1}'`
		echo "$A It's a file of size : $S"
	elif [ -d "$A" ]
	then
		M=0
		MN=""
		for F in `ls $A`
		do	
			if [ -f "$A/$F" ]
			then
				S=`du -b "$A/$F" | awk '{print $1}'`
				if [ $S -gt $M ]
				then
					M=`expr $S`
					MN="$F"
				fi
			fi
		done
		echo "$A It's a directory, largest file : $MN with size $M"
	else
		echo "$A It's neither a file or directory"
		if [[ "$A" == [aeiouAEIOU]* ]]
		then 
			`touch $A`
			echo "Created the file $A"
		else
			`mkdir $A`
			echo "Created the directory $A"
		fi
	fi
done
