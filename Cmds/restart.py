#!/usr/bin/python
from commands import *
getoutput('ifconfig eth0 down && /etc/init.d/networking restart && ifconfig eth0 up') 
getoutput('htpasswd -b /var/pasweb s-100 s-100')



 
 