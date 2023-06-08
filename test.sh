#!/bin/bash

#Tripouille/printfTester
cd printfTester
make a
cd ../

#usatie/printf-tester-tokyo
# cd printf-tester-tokyo
# make test

#AntoineBourin/printf-tester
# make re
# cp libftprintf.a ./printf-tester
# cd printf-tester
# sh test.sh
# rm libftprintf.a
# cd ../

#gavinfielder/pft
# cd pft
# make re
# ./test c
# ./test s
# ./test p
# ./test d
# ./test i
# ./test u
# ./test x
# ./test X
# ./test pct
# ./test zp
# ./test lj
# ./test pct_
# ./enable-test bonus_af
# ./enable-test bonus_sp
# ./enable-test bonus_as
# cd ../

#paulo-santana/ft_printf_tester
make re
cp libftprintf.a ./ft_printf_tester
cd ft_printf_tester
sh test
cd ../

#cacharle/ft_printf_test
# cd ft_printf_test
# make run
# make fclean
# make runbonus
# make fclean
# cd ../