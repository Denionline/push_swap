#!/bin/bash

awk '{
  for (i = 1; i <= NF; i++) {
    count[$i]++
    total++
  }
}
END {
  for (w in count) print w, count[w]
  print "Total operations:", total
}' | sort -k2nr
