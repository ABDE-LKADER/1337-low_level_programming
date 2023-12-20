#!/bin/bash

tram=$(free -m | grep "^Mem:" | awk '{print $2}')
uram=$(free -m | grep "^Mem:" | awk '{print $3}')
pram=$(free -m | grep "^Mem:" | awk '{printf("%.2f"), $3*100/$2}')
tmem=$(df -BG | grep "^/dev/mapper" | awk '{SUM += $2} END {print SUM}')
umem=$(df -BM | grep "^/dev/mapper" | awk '{SUM += $3} END {print SUM}')
pmem=$(df -BM | grep "^/dev/mapper" | awk '{TN += $2} {UN += $3} END {printf("%d"), UN*100/TN}')
cpul=$(mpstat | tail -n 1 | awk '{print 100 - $13}')

wall "	#Architecture: $(uname -a)
	#CPU physical : $(lscpu | grep "Socket(s)" | awk '{print $2}')
	#vCPU : $(lscpu | grep "^CPU(s):" | awk '{print $2}')
	#Memory Usage: $uram/$tram"MB" ($pram%)
	#Disk Usage: $umem/$tmem"Gb" ($pmem%)
	#CPU load: $cpul%
	#Last boot: $(who -b | awk '{print $3}') $( who -b | awk '{print $4}')
	#LVM use: $(if lsblk | grep -q "lvm"; then echo "yes"; else echo "no"; fi)
	#Connections TCP : $(netstat -a | grep -c ESTABLISHED) ESTABLISHED
	#User log: $(users | tr ' ' '\n' | uniq | wc -l)
	#Network: IP $(hostname -I)($(ip address | grep "ether" | awk '{print $2}'))
	#Sudo : $(journalctl _COMM=sudo -q | wc -l) cmd"
