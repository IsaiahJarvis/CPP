# my_tests_bad.sh

./eval_pre_post "+ * 2 3"
./eval_pre_post "+ x 2 3"
./eval_pre_post "+ * 2 3 4 5"
./eval_pre_post "3 3 * 5"
./eval_pre_post "2 3 4 + x"
./eval_pre_post "2 3 + *"
./eval_pre_post "2 3 4 5 6 + *"

