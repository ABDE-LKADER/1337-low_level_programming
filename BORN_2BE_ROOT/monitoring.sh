#!/bin/bash

ramu=$(free --mega | grep "^Mem:" | awk '{printf("%d/%dMB (%.2f%%)"), $3, $2, $3*100/$2}')
tmem=$(df -BG | grep "^/dev/mapper" | awk '{SUM += $2} END {print SUM}')
umem=$(df -BM | grep "^/dev/mapper" | awk '{SUM += $3} END {print SUM}')
pmem=$(df -BM | grep "^/dev/mapper" | awk '{TN += $2} {UN += $3} END {printf("%d"), UN*100/TN}')

wall "	#Architecture: $(uname -a)
	#CPU physical : $(lscpu | grep "Socket(s)" | awk '{print $2}')
	#vCPU : $(lscpu | grep "^CPU(s):" | awk '{print $2}')
	#Memory Usage: $ramu
	#Disk Usage: $umem/$tmem"Gb" ($pmem%)
	#CPU load: $(mpstat | tail -n 1 | awk '{print 100 - $13}')%
	#Last boot: $(who -b | awk '{print $3}') $( who -b | awk '{print $4}')
	#LVM use: $(if lsblk | grep -q "lvm"; then echo "yes"; else echo "no"; fi)
	#Connections TCP : $(netstat -a | grep -c ESTABLISHED) ESTABLISHED
	#User log: $(users | tr ' ' '\n' | uniq | wc -l)
	#Network: IP $(hostname -I)($(ip address | grep "ether" | awk '{print $2}'))
	#Sudo : $(journalctl _COMM=sudo -q | wc -l) cmd"
