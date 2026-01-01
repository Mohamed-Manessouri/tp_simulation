set terminal pngcairo size 900,600
set output "evolution_mt.png"

set title "Évolution de la population selon la graine (Mersenne Twister)"
set xlabel "Années"
set ylabel "Nombre total de lapins"
set grid
set key outside

plot "results_seed1.dat"    using 1:2 with lines lw 2 lc rgb "red"   title "Graine = 1", \
     "results_seed42.dat"   using 1:2 with lines lw 2 lc rgb "blue"  title "Graine = 42", \
     "results_seed1234.dat" using 1:2 with lines lw 2 lc rgb "green" title "Graine = 1234"

