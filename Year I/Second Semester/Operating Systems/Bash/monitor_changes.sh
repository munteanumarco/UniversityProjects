#!/bin/bash

D=$1
#Check if $D is empty
if [ -z "$D" ]; then
	echo "ERRORRORRRR, argument not sent"
	exit 1
fi
#Check if $D is not a dir
if [ ! -d $D ]; then
	echo "ERORORORRORORRR, $D is not a directory, Im scared"
	exit 1
fi
#State is the previous state
STATE=""
while true; do
#S is current state
	S=""
	#Iterate over all files and directories recursively
	for F in `find $D`; do
		#If it is a file, ls -l on the file for the details, sha1sum for encrypting
		if [ -f $F ]; then
			PROPERTIES=`ls -l $F | sha1sum`
			#Same for contents
			CONTENT=`cat $F | sha1sum`
		#If its a directory			
		elif [ -d $F ]; then
			#Properties with ls -d -l
			PROPERTIES=`ls -d -l $F | sha1sum`
			#Contents with ls -l
			CONTENT=`ls -l $F | sha1sum`
		fi
		#S for every file, on a new line we have checksums for every file
		S="$S\n$PROPERTIES $CONTENT"
	done
	#If state is not empty(for first step) and the current state != last state
	if [ -n "$STATE" ] && [ "$S" != "$STATE" ]; then
		#print Change occured
		echo "Change occured"
	fi
	#Save the current state
	STATE=$S
	#Sleep 1 second
	sleep 1
done

#NOTES

#In the beggining you have to specify "#!/bin/bash" (for the interpreter)

#For an if, you need a space after the first bracket and a space before the last bracket
#S=something, with no $(dollar sign) when assigning
#VAR=$S $S if we need the value
#You end an if with fi
#You end loops with done
#For ifs: (-z $VAR checks if var is empty, 
#          -d $VAR checks if var is a directory
#          -n $VAR checks if var is NOT empty
#          -f $VAR checks if var is a file

# In order to run a program you have to give yourself permision to execute it (see permissions with ls -l)
# The permissions are grouped in 3(read, write, execute) for the user, the group and everybody else
# You have to use chmod, specifying for every "group" which permissions you want to assign, by associating
# the permissions with binary
# chmod 700 for example gives the user all 3 permissions, and the group and others get nothing
