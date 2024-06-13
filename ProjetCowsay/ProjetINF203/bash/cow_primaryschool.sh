#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 n"
    echo "  n : nombre jusqu'auquel la vache doit compter"
    exit 1
fi

n=$1

if ! [[ "$n" =~ ^[0-9]+$ ]]; then
    echo "Erreur: '$n' n'est pas un nombre valide"
    exit 1
fi

for i in $(seq 1 $n); do
    cowsay $i
    sleep 1
done

cowsay -T "U" "J'ai fini!"
