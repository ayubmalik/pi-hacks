#!/bin/bash


function reset() {
  gpio mode 0 in
  exit 0
}

trap reset INT

gpio mode 0 out
while(true)
do
  gpio write 0 1
  sleepms 10
  gpio write 0 0
  sleepms 100
done

reset
