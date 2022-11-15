#!/bin/sh

echo "**********RESOLVE**********\n\n"
echo "\n\n\nOnline Examples"

echo "good files"
for testfile in good*.bminor
do
	if ./bminor -resolve  $testfile > $testfile.out
	then
		echo "$testfile 1st pass success (as expected)"
	else
		echo "$testfile 1st pass failure (INCORRECT)"
	fi
	
done
echo "bad files"

for testfile in bad*.bminor
do
	if ./bminor -resolve  $testfile > $testfile.out
	then
			echo "$testfile 1st pass success (INCORRECT)"
		else
			echo "$testfile 1st pass failure (as expected)"
	fi
done

echo "\n\n\nTHESE ARE MY TEST CASES"

echo "good files"
for testfile in mygood*.bminor
do
	if  ./bminor -resolve  $testfile > $testfile.out
	then
			echo "$testfile success (as expected)"
	else
		echo "$testfile 1st pass failure (INCORRECT)"
	fi
	
done

echo "bad files"

for testfile in mybad*.bminor
do
	if ./bminor -resolve  $testfile > $testfile.out
	then
		echo "$testfile 1st pass success (INCORRECT)"
	else
			echo "$testfile 2nd pass failure (as expected)"
	fi
done

echo "\n**********TYPECHECK**********\n\n"


echo "good files"
for testfile in good*.bminor
do
	if ./bminor -typecheck  $testfile > $testfile.out
	then
		echo "$testfile 1st pass success (as expected)"
	else
		echo "$testfile 1st pass failure (INCORRECT)"
	fi
	
done
echo "bad files"

for testfile in bad*.bminor
do
	if ./bminor -typecheck  $testfile > $testfile.out
	then
			echo "$testfile 1st pass success (INCORRECT)"
		else
			echo "$testfile 1st pass failure (as expected)"
	fi
done

echo "\n\n\nTHESE ARE MY TEST CASES"

echo "good files"
for testfile in mygood*.bminor
do
	if  ./bminor -typecheck  $testfile > $testfile.out
	then
			echo "$testfile success (as expected)"
	else
		echo "$testfile 1st pass failure (INCORRECT)"
	fi
	
done

echo "bad files"

for testfile in mybad*.bminor
do
	if ./bminor -typecheck  $testfile > $testfile.out
	then
		echo "$testfile 1st pass success (INCORRECT)"
	else
			echo "$testfile 2nd pass failure (as expected)"
	fi
done




