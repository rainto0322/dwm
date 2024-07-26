#! /bin/bash
daemons() {
    [ $1 ] && sleep $1
    picom  &
    feh --bg-fill ~/.config/dwm/wallpaper/cat.png
    fcitx5 &
    # mpd &
    dunst &
    # sudo mongod -f /etc/mongodb.conf
}
daemons 1 &