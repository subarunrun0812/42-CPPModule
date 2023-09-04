#! /bin/bash

make

# テストケースの実行
echo "====== CPP05 ex00 ======"

test_cases=("0" "42.0f" "42.42" \
"c" "a" "hoge" \
"-42" "42" \
"0.0f" "-4.2f" "4.2f" \
"nanf" "-inff" "+inff" \
"0.0" "-4.2" "4.2" \
"nan" "-inf" "+inf")

for test_case in "${test_cases[@]}"; do
    echo "[$test_case]"
    ./ex00 $test_case
done