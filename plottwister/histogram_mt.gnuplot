set terminal pngcairo size 900,600
set output "histogram_mt.png"

set title "Distribution du nombre d'années avant extinction (Mersenne Twister)"
set xlabel "Durée de vie (années)"
set ylabel "Fréquence d'extinction"
set style fill solid 0.5
set boxwidth 1
set grid

bin_width = 2
bin(x,width) = width * floor(x / width)
plot "extinction_mt.dat" using (bin($1,bin_width)):(1.0) smooth freq with boxes lc rgb "#66ccff" title "Mersenne Twister"
