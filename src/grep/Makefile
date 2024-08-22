TARGET1 = s21_grep
CC = gcc
FLAGS =  -Wall -Werror -Wextra -o 


$(TARGET1): s21_grep.o
	$(CC) $(FLAGS) $(TARGET1) s21_grep.o

s21_grep.o :s21_grep.c
	$(CC) -c $(FLAGS) s21_grep.o s21_grep.c

clean:
	rm -rf *.o