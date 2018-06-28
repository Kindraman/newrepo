#!/usr/bin/env gnuplot

#-------------------------
#	Declaraciones comunes
#-------------------------

set encoding iso_8859_1

TIME_FILE="tiempos.csv"

#set term png size 640,480
set term png size 1200,800

#----------------------------------
#	Gráfico de Tiempos de Ejecución
#----------------------------------

set output "graph-ex02-tejec.png"

set title "Tiempo de ejecución\nTamaño del arreglo = 65.536"
set ylabel "Tiempo Ejecución [us]"
set xlabel "Nro de Threads"

#set key at 10000,1000
set key outside
set grid xtics ytics mytics

set logscale x 2
set xrange [.9:*]

#set style data histograms
#set style histogram rowstacked
#set boxwidth 0.5
#set style fill pattern 1 border -1


#plot newhistogram "Nro de procesos\nMétodo por franjas" lt 1, TIME_FILE  using 5:xtic(1) title "Comp" fill pattern 2 border -1 lt -1, \
#					'' using 8  title "Comm+Sync"  fill pattern 3 border -1 lt -1, \
#					'' using 11 title ""  fill pattern 3 border -1 lt -1

plot TIME_FILE  using 1:2 title "Mis datos"  with linespoints lt 3 pointtype 11 pointsize 1

#----------------------
#	Gráfico de SpeedUP
#----------------------

y(x)=x

set output "graph-ex02-speedup.png"

#Tiempo sacado del promedio de los tiempos de ejecución secuencial
TIME_SERIAL=0.000031

set title "Gráfico de SpeedUp\nTamaño del arreglo = 65.536\"
set ylabel "SpeedUp (S)"
set xlabel "Número de Threads"

set logscale y 2
set logscale x 2
set xrange [.9:*]
set yrange [.9:*]

set key at 4,128

plot TIME_FILE  using 1:(TIME_SERIAL/$16) title "Mis datos"  with linespoints lt 3 pointtype 11 pointsize 1, \
	 y(x) title "Teórico" lt 1

#
#----------------------
#	Gráfico de Eficiencia
#----------------------

set output "graph-ex02-eficiencia.png"
TIME_SERIAL=0.000031
set title "Eficiencia\nTamaño del arreglo = 65.536"
set ylabel "S/threads"
set xlabel "Número de Threads"

unset logscale y
set logscale x 2
set xrange [0.9:*]
set yrange [0:*]
set ytics 0.0001

set key at 128,1

plot TIME_FILE  using 1:(TIME_SERIAL/$2/$1) title "Mis datos"  with linespoints lt 3 pointtype 11 pointsize 1
