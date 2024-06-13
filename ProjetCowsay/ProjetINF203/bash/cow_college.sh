#!/bin/bash
if [[ $# -ne 1 ]]; then
    echo "Usage: $0 n"
    exit 1
fi

n=$1
a=0
b=1

while [[ $a -le $n ]]; do
    echo $a | cowsay
    sleep 1
    c=$((a + b))
    a=$b
    b=$c
done

cowsay -T "U" "J'ai fini!"
