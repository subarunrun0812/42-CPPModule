#! /bin/bash

make

# テストケースの実行
echo "====== CPP05 ex00 ======"

test_cases=("0" "42.0f" "42.42" \
"nan" "-inf" "+inf")

for test_case in "${test_cases[@]}"; do
    echo "[$test_case]"
    ./ex00 $test_case
done