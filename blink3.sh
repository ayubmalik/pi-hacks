#!/bin/bash


function mode_in() {
  gpio mode 0 in
  gpio mode 1 in
  gpio mode 2 in
  exit 0
}

function mode_out() {
  gpio mode 0 out
  gpio mode 1 out
  gpio mode 2 out
}

trap mode_in INT

mode_out

while(true)
do
  gpio write 2 0
  gpio write 0 1
  sleepms 100
  gpio write 1 1
  sleepms 50
  gpio write 0 0
  gpio write 2 1
  sleepms 50
  gpio write 1 0
  sleepms 100
done

mode_in

