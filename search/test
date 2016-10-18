#!/usr/bin/awk -f

BEGIN { res="ok" }

$1<=$2 { print("error: acc<=data[pos-1]<="); res="err" }
$1>$3 { print("error: acc>data[pos]"); res="err" }
$1>$4 { print("error: acc>data[pos+1]"); res="err" }

END { print(res) }
