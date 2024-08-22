TARGET1 = my_cat
CC = gcc
FLAGS =  -Wall -Werror -Wextra -o 


$(TARGET1): my_cat.o
	$(CC) $(FLAGS) $(TARGET1) my_cat.o

my_cat.o :my_cat.c
	$(CC) -c $(FLAGS) my_cat.o my_cat.c

clean:
	rm -rf *.o my_cat log.txt