#!/bin/bash

# Récupérer l'expression mathématique en argument
expression="$1"

# Résoudre l'expression mathématique
result=$(echo "$expression" | bc)

# Créer la vache avec les yeux affichant le résultat
if [ "$result" -lt 10 ] && [ "$result" -ge 0 ]; then
cowsay -e "0$result" "$expression"
else
cowsay -e "$result" "$expression"
fi