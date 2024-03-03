#build.sh
#g++ gather_odds_evens.o functions.cpp -I/home/course_ps/u00/public/cxtra /home/course_ps/u00/public/cxtra/utilities.o -o gather_odds_evens

INCLUDE_DIR=/home/course_ps/u00/public/cxtra
UTILITIES_O=/home/course_ps/u00/public/cxtra/utilities.o
g++ gather_odds_evens.o functions.cpp -I$INCLUDE_DIR $UTILITIES_O -o gather_odds_evens

