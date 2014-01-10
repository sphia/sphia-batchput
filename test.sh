#!/bin/bash

export SPHIA_PATH=test-db

rm -rf $SPHIA_PATH

cmd=""
for i in {1..5}; do
  cmd="$cmd key$i value$i"
done

./sphia-batchput $cmd

failed=0
for i in {1..5}; do
  value=`sphia get --key key$i`
  if [ "$value" != "value$i" ]; then
    echo "Assertion failed: '$value' == 'value$i'"
    failed=$(($failed + 1))
  fi
done

exit $failed
