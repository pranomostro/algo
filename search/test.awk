#!/usr/bin/awk -f

$1<=$2 { print("error: acc<=data[pos-1]<=") }
$1>$3 { print("error: acc>data[pos]") }
$1>$4 { print("error: acc>data[pos+1]") }
