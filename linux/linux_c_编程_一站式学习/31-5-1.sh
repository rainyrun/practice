#! /bin/sh

COUNTER=0
echo $COUNTER
echo "Enter password:"
read TRY
while [ "$COUNTER" -lt 5 -a "$TRY" != "secret" ]; do
	echo "Sorry, try again"
	COUNTER=$(($COUNTER+1))
	echo $COUNTER
	read TRY
done

if [ "$COUNTER" -eq 5 ]; then
	echo "5 incorrect password attempts"
	exit 1
fi
