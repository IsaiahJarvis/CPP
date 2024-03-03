#build_simple.sh
INCLUDE_DIR=/home/course_ps/u00/public/cxtra
UTILITIES_O=/home/course_ps/u00/public/cxtra/utilities.o
g++ test_menu_simple.cpp menu.cpp -I$INCLUDE_DIR $UTILITIES_O -o test_menu_simple

