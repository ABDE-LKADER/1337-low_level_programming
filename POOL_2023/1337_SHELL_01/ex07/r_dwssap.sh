#!/bin/bash
cat /etc/passwd | grep -v "#" | awk "NR%2==0" | sort -r | cut -d: -f1 | rev | tr "\n" " " | sed -n $FT_LINE1 $FT_LINE2 p | sed 's+ +, +g' | sed 's+, $+.+g'
