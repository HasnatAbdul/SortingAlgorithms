set boxwidth 0.7
set style fill solid
plot "gnu.out" using 1:3:xtic(2) with boxes

set title "Sorting Algorithmes"
set xlabel "Sorting Methods"
set ylabel "Time (s)"

