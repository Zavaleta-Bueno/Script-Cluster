#!/bin/bash
# Ejercicio1


if [ -z "$1" ]
then
echo "Incluya el parametro de numero de procesos"
echo " "
exit 1
fi


#Comprobando si existe archivo de salidas,  
if [ -e salidas_$1.dat ]
then
rm salidas_$1.dat
touch salidas_$1.dat
else
touch salidas_$1.dat
fi


#Agregando datos
echo "# X	Y">>salidas_$1.dat

echo " "

#make_ejecutable=$(mpicc argumentos.c -o argumentos -lm)

# Send stdout to out.log, stderr to err.log
#echo $make_ejecutable > out.log 2> err.log


mpicc argumentos.c -o argumentos -lm

# Send both stdout and stderr to out.log
#echo $make_ejecutable &> out.log      # New bash syntax
#echo $make_ejecutable > out.log 2>&1  # Older sh syntax

# Log output, hide errors.

#echo $make_ejecutable > out.log 2> /dev/null

echo "========================================="
echo "= Ejecutando programa para $1 procesos  ="
echo "========================================="
echo " "
echo ""
echo ""


echo "Para una cantidad de 1000 intervalos"
#mpirun -np $1 ./argumentos 1000 >> $variable
OUTPUT="$(mpirun -np $1 ./argumentos 1000)"
echo "Tiempo de ejecucion y Error" 
echo "${OUTPUT}"
echo "${OUTPUT}	1000">>salidas_$1.dat
echo ""

echo "Para una cantidad de 10000 intervalos"
OUTPUT="$(mpirun -np $1 ./argumentos 10000)"
echo "Tiempo de ejecucion y Error" 
echo "${OUTPUT}"
echo "${OUTPUT}	10000">>salidas_$1.dat
echo ""

echo "Para una cantidad de 100000 intervalos"
OUTPUT="$(mpirun -np $1 ./argumentos 100000)"
echo "Tiempo de ejecucion y Error"
echo "${OUTPUT}"
echo "${OUTPUT}	100000">>salidas_$1.dat
echo ""

echo "Para una cantidad de 1000000 intervalos"
OUTPUT="$(mpirun -np $1 ./argumentos 1000000)"
echo "Tiempo de ejecucion y Error"
echo "${OUTPUT}"
echo "${OUTPUT}	1000000">>salidas_$1.dat
echo ""

echo "Para una cantidad de 10000000 intervalos"
OUTPUT="$(mpirun -np $1 ./argumentos 10000000)"
echo "Tiempo de ejecucion y Error"
echo "${OUTPUT}"
echo "${OUTPUT}	10000000">>salidas_$1.dat
echo ""

