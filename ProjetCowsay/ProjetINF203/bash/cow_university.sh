#!/bin/bash

n=$1
primes=(2)
for ((i=3; i<=n; i++)); do
    is_prime=true
    for p in "${primes[@]}"; do
        if (( i % p == 0 )); then
            is_prime=false
            break
        fi
    done
    if $is_prime; then
        primes+=("$i")
        echo "$i" | cowsay
        sleep 1
    fi
done
cowsay -T "U" "Je suis une vache intelligente qui connaît les nombres premiers jusqu'à $n!"
