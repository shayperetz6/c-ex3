CC=gcc
FLAG=-Wall -g
AR=ar
all: main_isort main_txtfind 
main_isort: isort.c  
	$(CC) $(FLAG) isort.c -o isort
main_txtfind: txtfind.c 
	$(CC) $(FLAG) txtfind.c -o txtfind
.PHONY:  clean all
clean:
	rm -f *.o *.a *.so isort txtfind