#!/bin/bash

read key
while [ "$key" != "success" ]
do
  ./a.out
  read key
done
echo "ok"
