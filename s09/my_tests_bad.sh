#d my_tests.sh
# Shell script for testing invalid input to the simple calculator.
# Usage:
# prompt> ./my_tests_bad.sh
# This command will run all the test examples shown
# below. You can delete some tests, or add some of
# your own. Or you can change the file name of the
# the program you're running, if that is appropriate.

./demo_compute "+26"
./demo_compute "(26)"
./demo_compute "26a"
./demo_compute "-26"
./demo_compute "0-26"
./demo_compute "a"
./demo_compute "(1+2)a"
./demo_compute "(1+2)  a"
./demo_compute "((1+2))"
./demo_compute "(2*(1+(3)))"
./demo_compute "(4*6+(0-3))"
./demo_compute "(26 + (13 - 4 + 7)"

