#my_tests.sh
clear
echo $'\nFirst we test codes increasing horizontally'
read -p "(Pause from testing script) Press Enter to continue ... "

echo $'\nRunning first: demo_display_ascii2 \"A\" \"A\" h'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 "A" "A" h

echo $'\nRunning next: demo_display_ascii2 \"A\" \"B\" h'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 "A" "B" h

echo $'\nRunning next: demo_display_ascii2 \"A\" \"C\" h'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 "A" "C" h

echo $'\nRunning next: demo_display_ascii2 \"A\" \"D\" h'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 "A" "D" h

echo $'\nRunning next: demo_display_ascii2 \"A\" \"E\" h'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 "A" "E" h

echo $'\nRunning next: demo_display_ascii2 \"A\" \"Z\" h'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 "A" "Z" h

echo $'\nRunning next: demo_display_ascii2 \"a\" \"z\" h'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 "a" "z" h

echo $'\nRunning next: demo_display_ascii2 \" \" \"~\" h'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 " " "~" h

echo $'\nRunning next: demo_display_ascii2 \" \" \"w\" h'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 " " "w" h

echo $'\nRunning next: demo_display_ascii2 \" \" \"x\" h'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 " " "x" h

echo $'\nRunning next: demo_display_ascii2 \" \" \"y\" h'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 " " "y" h

echo $'\nRunning next: demo_display_ascii2 \" \" \"z\" h'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 " " "z" h

echo $'\nRunning next: demo_display_ascii2 \" \" \"{\" h'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 " " "{" h

echo $'\nRunning next: demo_display_ascii2 \" \" \"|\" h'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 " " "|" h

echo $'\nRunning next: demo_display_ascii2 \"$\" \"w\" h'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 "$" "w" h

echo $'\nRunning next: demo_display_ascii2 \"\\\" \"c\" h'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 "\\" "c" h

echo $'\nRunning next: demo_display_ascii2 \"\`\" \"g\" h'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 "\`" "g" h

#================================================================
clear
echo $'\nNext we test codes increasing vertically'
read -p "(Pause from testing script) Press Enter to continue ... "

echo $'\nRunning first: demo_display_ascii2 \"A\" \"A\" v'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 "A" "A" v

echo $'\nRunning next: demo_display_ascii2 \"A\" \"B\" v'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 "A" "B" v

echo $'\nRunning next: demo_display_ascii2 \"A\" \"C\" v'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 "A" "C" v

echo $'\nRunning next: demo_display_ascii2 \"A\" \"D\" v'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 "A" "D" v

echo $'\nRunning next: demo_display_ascii2 \"A\" \"E\" v'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 "A" "E" v

echo $'\nRunning next: demo_display_ascii2 \"A\" \"Z\" v'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 "A" "Z" v

echo $'\nRunning next: demo_display_ascii2 \"a\" \"z\" v'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 "a" "z" v

echo $'\nRunning next: demo_display_ascii2 \" \" \"~\" v'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 " " "~" v

echo $'\nRunning next: demo_display_ascii2 \" \" \"w\" v'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 " " "w" v

echo $'\nRunning next: demo_display_ascii2 \" \" \"x\" v'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 " " "x" v

echo $'\nRunning next: demo_display_ascii2 \" \" \"y\" v'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 " " "y" v

echo $'\nRunning next: demo_display_ascii2 \" \" \"z\" v'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 " " "z" v

echo $'\nRunning next: demo_display_ascii2 \" \" \"{\" v'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 " " "{" v

echo $'\nRunning next: demo_display_ascii2 \" \" \"|\" v'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 " " "|" v

echo $'\nRunning next: demo_display_ascii2 \"$\" \"w\" v'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 "$" "w" v

echo $'\nRunning next: demo_display_ascii2 \"\\\" \"c\" v'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 "\\" "c" v

echo $'\nRunning next: demo_display_ascii2 \"\`\" \"g\" v'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 "\`" "g" v

#================================================================
clear
echo $'\nNow we test input values that generate our error messages'
read -p "(Pause from testing script) Press Enter to continue ... "

echo $'\nRunning first: demo_display_ascii2 a'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 a

echo $'\nRunning next: demo_display_ascii2 a b'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 a b

echo $'\nRunning next: demo_display_ascii2 a b c d'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 a b c d

echo $'\nRunning next: demo_display_ascii2 a b cd'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 a b cd

echo $'\nRunning next: demo_display_ascii2 b a c'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 b a c

echo $'\nRunning next: demo_display_ascii2 a b c'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 a b c

echo $'\nRunning first: demo_display_ascii2 a'
read -p "(Pause from testing script) Press Enter to continue ... "
./demo_display_ascii2 a

#================================================================
clear
echo $'\nAll testing is now complete'
read -p "(Pause from testing script) Press Enter to continue ... "
