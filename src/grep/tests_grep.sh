#!/ bin / bash
SUCCESS=0
FAIL=0
COUNTER=0
DIFF=""
TEST_FILE=(
    "tests/test1.txt"
    "tests/test2.txt"
    "tests/test3.txt"
    "tests/test4.txt"
)

FIND_FILE=(
    "tests/tofind.txt"
    "tests/tofind2.txt"
)

my_grep="./my_grep"
grep="grep"



flags=(
    "-e"
    "-i"
    "-v"
    "-c"
    "-l"
    "-n"
    "-h"
    "-s"
)

flags2=(
    "-i"
    "-v"
    "-c"
    "-l"
    "-n"
    "-h"
    "-s"
)

flags3=(
    "-f"
)

TEST_PATTERN=(
    "hello"
)

printf "\n"
echo "#######################"
echo "AUTOTESTS"
echo "#######################"
printf "\n"
echo "======================="
echo "1 PARAMETER - 1 FILE"
echo "======================="
printf "\n"



for var1 in "${flags[@]}"
do
    for var2 in "${TEST_PATTERN[@]}"
    do

        for var3 in "${TEST_FILE[@]}"
        do
            (( COUNTER++ ))
            TEST1="$var1 $var2 $var3"

            $my_grep $TEST1 >  test_result_my_grep.txt
            $grep $TEST1 > test_result_grep.txt
            DIFF_RES="$(diff -s test_result_my_grep.txt test_result_grep.txt)"
            if [ "$DIFF_RES" == "Files test_result_my_grep.txt and test_result_grep.txt are identical" ]
                then
                    (( SUCCESS++ ))
                    echo "$COUNTER - \033[32mSUCCESS\033[0m $TEST1"
                else
                    echo "$TEST1" >> log.txt
                    (( FAIL++ ))
                    echo "$COUNTER - \033[31mFAIL\033[0m $TEST1"
            fi
            rm test_result_my_grep.txt test_result_grep.txt
        done
    done
done


printf "\n"
echo "FAILED: $FAIL"
echo "SUCCESSFUL: $SUCCESS"
echo "ALL: $COUNTER"
printf "\n"
##############################



printf "\n"
echo "#######################"
echo "AUTOTESTS"
echo "#######################"
printf "\n"
echo "======================="
echo "2 PARAMETER - 1 FILE"
echo "======================="
printf "\n"



for var1 in "${flags2[@]}"
do
    for var2 in "${flags2[@]}"
    do
        if [ $var1 != $var2 ]
        then
            for var3 in "${TEST_PATTERN[@]}"
            do
                for var4 in "${TEST_FILE[@]}"
                do
                    (( COUNTER++ ))
                    TEST1="$var1 $var2 $var3 $var4"

                    $my_grep $TEST1 >  test_result_my_grep.txt
                    $grep $TEST1 > test_result_grep.txt
                    DIFF_RES="$(diff -s test_result_my_grep.txt test_result_grep.txt)"
                    if [ "$DIFF_RES" == "Files test_result_my_grep.txt and test_result_grep.txt are identical" ]
                        then
                            (( SUCCESS++ ))
                            echo "$COUNTER - \033[32mSUCCESS\033[0m $TEST1"
                        else
                            echo "$TEST1" >> log.txt
                            (( FAIL++ ))
                            echo "$COUNTER - \033[31mFAIL\033[0m $TEST1"
                    fi
                    rm test_result_my_grep.txt test_result_grep.txt
                done
            done
        fi
    done
done


printf "\n"
echo "FAILED: $FAIL"
echo "SUCCESSFUL: $SUCCESS"
echo "ALL: $COUNTER"
printf "\n"
##############################






printf "\n"
echo "#######################"
echo "AUTOTESTS"
echo "#######################"
printf "\n"
echo "======================="
echo "f PARAMETER - 1 FILE"
echo "======================="
printf "\n"



for var1 in "${flags3[@]}"
do
    for var2 in "${FIND_FILE[@]}"
    do

        for var3 in "${TEST_FILE[@]}"
        do
            (( COUNTER++ ))
            TEST1="$var1 $var2 $var3"

            $my_grep $TEST1 >  test_result_my_grep.txt
            $grep $TEST1 > test_result_grep.txt
            DIFF_RES="$(diff -s test_result_my_grep.txt test_result_grep.txt)"
            if [ "$DIFF_RES" == "Files test_result_my_grep.txt and test_result_grep.txt are identical" ]
                then
                    (( SUCCESS++ ))
                    echo "$COUNTER - \033[32mSUCCESS\033[0m $TEST1"
                else
                    echo "$TEST1" >> log.txt
                    (( FAIL++ ))
                    echo "$COUNTER - \033[31mFAIL\033[0m $TEST1"
            fi
            rm test_result_my_grep.txt test_result_grep.txt
        done
    done
done


printf "\n"
echo "FAILED: $FAIL"
echo "SUCCESSFUL: $SUCCESS"
echo "ALL: $COUNTER"
printf "\n"
##############################


printf "\n"
echo "#######################"
echo "AUTOTESTS"
echo "#######################"
printf "\n"
echo "======================="
echo "f PARAMETER - 1 FILE"
echo "======================="
printf "\n"



for var1 in "${flags3[@]}"
do
    for var2 in "${FIND_FILE[@]}"
    do
        for var3 in "${flags3[@]}"
        do
            for var4 in "${FIND_FILE[@]}"
            do
               if [ $var2 != $var4 ]
                then 
                    for var5 in "${TEST_FILE[@]}"
                    do
                        (( COUNTER++ ))
                        TEST1="$var1 $var2 $var3 $var4 $var5"

                        $my_grep $TEST1 >  test_result_my_grep.txt
                        $grep $TEST1 > test_result_grep.txt
                        DIFF_RES="$(diff -s test_result_my_grep.txt test_result_grep.txt)"
                        if [ "$DIFF_RES" == "Files test_result_my_grep.txt and test_result_grep.txt are identical" ]
                            then
                                (( SUCCESS++ ))
                                echo "$COUNTER - \033[32mSUCCESS\033[0m $TEST1"
                            else
                                echo "$TEST1" >> log.txt
                                (( FAIL++ ))
                                echo "$COUNTER - \033[31mFAIL\033[0m $TEST1"
                        fi
                        rm test_result_my_grep.txt test_result_grep.txt
                    done
                fi
            done
        done
    done
done


printf "\n"
echo "FAILED: $FAIL"
echo "SUCCESSFUL: $SUCCESS"
echo "ALL: $COUNTER"
printf "\n"
##############################