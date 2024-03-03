#build.sh
#g++ test_menu.o menu.cpp -I/home/course_ps/u00/public/cxtra /home/course_ps/u00/public/cxtra/utilities.o -o test_menu

INCLUDE_DIR=/home/course_ps/u00/public/cxtra
UTILITIES_O=/home/course_ps/u00/public/cxtra/utilities.o
g++ test_menu.o menu.cpp -I$INCLUDE_DIR $UTILITIES_O -o test_menu

