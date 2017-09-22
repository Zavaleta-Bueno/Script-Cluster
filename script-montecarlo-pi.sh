#!/bin/bash
# Ejercicio1

if [ -e Montecarlo-PI.dat ]
then
rm salidas_$1.dat
touch Montecarlo-PI.dat
else
touch Montecarlo-PI.dat
fi




gcc montecarlo-pi-secuencial.c -o montecarlo -lm

# 

echo "========================================="
echo "=Calculo de PI con metodo  de Montecarlo="
echo "========================================="
echo " "
echo ""
echo ""

echo "Para 100"
./montecarlo 100

echo "========================================="
echo " "


echo "Para 1000"
./montecarlo 1000

echo "========================================="
echo " "


echo "Para 10000"
./montecarlo 10000

echo "========================================="
echo " "


echo "Para 100000"
./montecarlo 100000

echo "========================================="
echo " "


echo "Para 1000000"
./montecarlo 1000000

echo "========================================="
echo " "


echo "Para 10000000"
./montecarlo 10000000


echo "========================================="
echo " "

echo "Para 100000000"
./montecarlo 100000000

echo "========================================="
echo " "




