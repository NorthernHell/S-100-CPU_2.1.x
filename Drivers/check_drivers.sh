#!/bin/sh

#FILTERED_DIRS="dpid fastarr gui fastmatrix fda_alarm fda_serv fir iir isaafb isaser iset"
#FILTERED_DIRS=`ls -p | grep /| tr -d '/'`
FILTERED_DIRS="$@"
              if [ ! -f update_drivers ];
then
#this is a clean build
touch update_drivers
exit
else
    prev_drivers=`cat Drivers.h| grep include | sed -r -e 's@#include \"(.*)\/.*@\1@'`;
#echo "prev: ${prev_drivers}";
#echo "current: ${FILTERED_DIRS}";
#check for missing drivers
for prev_drv in $ {prev_drivers};
do
found=0;
for cur_drv in $ {FILTERED_DIRS};
do
if [ $ {prev_drv} = $ {cur_drv} ];
then
#no need to search further, this driver was not removed
found=1
      break
      fi
      done
      if [ $ {found} -eq 0 ];
then
echo $ {prev_drv} was removed, Drivers.h rebuild is required
#no need to search further - one missing driver enough to cause rebuild
touch update_drivers
exit
fi
done
#we do not check for driver addition since make handles it automatically by dependencies
echo 'no drivers were removed'
exit
fi
#not reached
echo 'script exit'
