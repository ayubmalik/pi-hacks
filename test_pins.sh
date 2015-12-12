#!/bin/bash

ms=128
pins=${1:-1}
max_pin=$((pins-1))

function mode_in() {
  for pin in `seq 0 $max_pin`; do
    gpio mode $pin in
  done
}

function mode_out() {
  for pin in `seq 0 $max_pin`; do
    gpio mode $pin out
  done
}

function test_pins() {
  for pin in `seq 0 $max_pin`; do
    gpio write $pin 1
    sleep 1.0
    gpio write $pin 0
  done
}

trap mode_in INT

mode_out

test_pins

mode_in

