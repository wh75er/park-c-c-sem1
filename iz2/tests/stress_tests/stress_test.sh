#!/bin/bash

calc(){ awk "BEGIN { print $* }"; }

if [[ -z $BUILD_DIR ]]; then
  echo "BUILD_DIR env variable is not set! Exiting..."
  exit 1
fi

mtime=0
otime=0

for i in {1..10}; do
  echo ">>$i run:"
  echo ">Running main implementation..."
  main_out=$(./$BUILD_DIR/main/main input.txt output_main.txt)
  mtime_=$(echo $main_out | awk '{print $3}') 
  mtime=$(calc $mtime + $mtime_)
  echo "-Time: $mtime_"
  echo "-Finished!"

  echo ""

  echo ">Running other implementation..."
  other_out=$(./$BUILD_DIR/main/other input.txt output_other.txt)
  otime_=$(echo $other_out | awk '{print $3}') 
  otime=$(calc $otime + $otime_)
  echo "-Time: $otime_"
  echo "-Finished!"

  echo ""

  echo ">Output differences:"
  diffs=$(diff output_main.txt output_other.txt)

  if [[ -z $diffs ]]; then
    echo "-Output is similar!"
  else
    echo "-Output is not similar!"
    exit 1
  fi

  echo ""
done

mtime=$(calc $mtime / 10)
otime=$(calc $otime / 10)

echo "Avarage time for main: $mtime"
echo "Avarage time for other: $otime"

exit 0
