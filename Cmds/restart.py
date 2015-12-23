#!/usr/bin/python
from commands import *
getoutput('ifconfig eth0 down && /etc/init.d/networking restart && ifconfig eth0 up') 
getoutput('htpasswd -b /var/pasweb s-100 s-100')

file =open ("/root/myscr/isa.sh", 'w')
file.write("swapon -p 1 /dev/mmcblk0p3\n")
file.write("cd /root/Cmds\n")
file.write("insmod led_evro.ko\n")
file.write("./buttons&\n")
file.write("./ISaGRAF&\n")
file.write("killall startpar&\n")
file.write("killall net.agent\n")
file.close()



 
 #write

file =open ("/etc/network/interfaces", 'r')
line_1 = file.readline()
line_2 = file.readline()
line_3 = file.readline()
line_4 = file.readline()
line_5 = file.readline()
line_6 = file.readline()
file.close()

file =open ("/etc/network/ip_mask_g", 'w')
file.write(line_1 )
file.write(line_2 )
file.write(line_3 )
file.write(line_4 )
file.write(line_5 )

file.close()

file =open ("/etc/network/hw", 'w')
file.write(line_6 )
file.close()

 

