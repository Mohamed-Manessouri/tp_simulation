set terminal png size 900,600
set output 'histogram_extinction.png'
set title "Distribution du nombre d'années avant extinction (100 graines)"
set xlabel "Durée de vie de la population (années)"
set ylabel "Fréquence"
set style fill solid 0.7
binwidth=2
bin(x,width)=width*floor(x/width)
plot 'extinction.dat' using (bin($1,binwidth)):(1.0) smooth freq with boxes lc rgb "skyblue" notitle
