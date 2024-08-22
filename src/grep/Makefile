TARGET1 = my_grep
CC = gcc
FLAGS =  -Wall -Werror -Wextra -o 


$(TARGET1): my_grep.o
	$(CC) $(FLAGS) $(TARGET1) my_grep.o

my_grep.o :my_grep.c
	$(CC) -c $(FLAGS) my_grep.o my_grep.c

clean:
	rm -rf *.o my_grep