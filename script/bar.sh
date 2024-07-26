#!/bin/dash

# ^c$var^ = fg color
# ^b$var^ = bg color

clock() {
	printf "$(date '+%H:%M') "
}

while true; do

  sleep 1 && xsetroot -name "$updates $(clock)"
done
