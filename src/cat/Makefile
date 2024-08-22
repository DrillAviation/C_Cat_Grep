TARGET1 = s21_cat
CC = gcc
FLAGS =  -Wall -Werror -Wextra -o 


$(TARGET1): s21_cat.o
	$(CC) $(FLAGS) $(TARGET1) s21_cat.o

s21_cat.o :s21_cat.c
	$(CC) -c $(FLAGS) s21_cat.o s21_cat.c

clean:
	rm -rf *.o