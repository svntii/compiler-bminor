#!/bin/sh

echo "\n\n\nOnline Examples"

for testfile in good*.bminor
do
	if ./bminor -parse  $testfile > $testfile.out
	then
		echo "$testfile success (as expected)"
	else
		echo "$testfile failure (INCORRECT)"
	fi
done

for testfile in bad*.bminor
do
	if ./bminor -parse  $testfile > $testfile.out
	then
		echo "$testfile success (INCORRECT)"
	else
		echo "$testfile failure (as expected)"
	fi
done

echo "\n\n\nTHESE ARE MY TEST CASES"

for testfile in mygood*.bminor
do
	if  ./bminor -parse  $testfile > $testfile.out
	then
		echo "$testfile success (as expected)"
	else
		echo "$testfile failure (INCORRECT)"
	fi
done

for testfile in mybad*.bminor
do
	if ./bminor -parse  $testfile > $testfile.out
	then
		echo "$testfile success (INCORRECT)"
	else
		echo "$testfile failure (as expected)"
	fi
done




