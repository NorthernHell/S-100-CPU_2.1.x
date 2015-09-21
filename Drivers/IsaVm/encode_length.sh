#!/bin/sh

#rm -rf $2
for byte in `ls -l $1 | tr -s ' ' |cut -f 5 -d ' ' | xargs printf %08x | sed 's/\(..\)\(..\)\(..\)\(..\)/\1 \2 \3 \4/g'`; do
  printf \\x$byte #>> $2
done
