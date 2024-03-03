# my_tests_good.sh
# Shell script for testing valid input to the simple calculator.
# Usage:
# prompt> ./my_tests_good.sh
# This command will run all the test examples shown
# below. You can delete some tests, or add some of
# your own. Or you can change the file name of the
# the program you're running, if that is appropriate.

./demo_compute "26 "
./demo_compute "          26"
./demo_compute "(0-26)"
./demo_compute "(1+0)"
./demo_compute "( 1+1) "
./demo_compute "(1  +2)"
./demo_compute "(1+   3)"
./demo_compute "(1+4    )"
./demo_compute "( 1  +5)"
./demo_compute "( 1+  6)"
./demo_compute "( 1+7  )"
./demo_compute "(1  +   8)"
./demo_compute "(1  +9   )"
./demo_compute "(1+  10   )"
./demo_compute "( 1  +  11)"
./demo_compute "( 1  +12   )"
./demo_compute "( 1+  13   )"
./demo_compute "(1 +  14    )"
./demo_compute "(42 - 11)"
./demo_compute "(16 * 2)"
./demo_compute "(1485 / 45)"
./demo_compute "((4*6)+(0-3))"
./demo_compute "(((73/2)/5)/3)"
./demo_compute "((12 + 7) * (13 - 9))"
./demo_compute "(((3 + (21 / 6)) * (0-4)) / ((7+3)/3))"
./demo_compute "(((11+23)*(7-3))/(((5+6)*(7+8))/(9+10)))"
./demo_compute "((((11+23)*(7-3))/(5+6))*((7+8)/(9+10)))"

