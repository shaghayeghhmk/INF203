#!/bin/bash

echo "Bonjour, comment t'appelles-tu ?"
read prenom

echo "Bonjour $prenom, quel âge as-tu ?"
read age

echo "Je vais te poser quelques questions pour déterminer ton espérance de vie."
echo "Réponds par oui ou non."

reduction=100
echo "Est-ce que tu fumes ?"|cowsay
read fume
if [ "$fume" == "oui" ]; then
  reduction=$((reduction - 10))
fi

echo "Est-ce que tu bois de l'alcool ?"|cowsay
read alcool
if [ "$alcool" == "oui" ]; then
  reduction=$((reduction - 5))
fi

echo "Est-ce que tu manges souvent de la junk food ?"|cowsay
read junk_food
if [ "$junk_food" == "oui" ]; then
  reduction=$((reduction - 6))
fi

echo "Est-ce que tu fais régulièrement du sport ?"|cowsay
read workout
if [ "$workout" == "non" ]; then
  reduction=$((reduction - 7))
fi

esp_vie=$((reduction - age))

echo "D'après mes calculs, tu as une espérance de vie de $esp_vie ans." | cowsay
if [ $esp_vie -lt 0 ]; then
  echo "Désolé $prenom, mais tu ne vas probablement pas survivre jusqu'à ta retraite !" | cowsay -e "--"
else
  echo "Tu as encore pas mal de temps devant toi, profite-en bien $prenom !" | cowthink -e "^^"
fi
