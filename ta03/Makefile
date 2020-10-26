CC= gcc 
CFLAGS= -ansi 

main.exe:
	$(CC) $(CFLAGS) -o hw7 hw7.o list.o mystruct.o stack.o queue.o

hw7.o:
	$(CC) $(CFLAGS) -c hw7.c

list.o:
	$(CC) $(CFLAGS) -c list.c

mystruct.o:
	$(CC) $(CFLAGS) -c mystruct.c

stack.o:
	$(CC) $(CFLAGS) -c stack.c

queue.o:
	$(CC) $(CFLAGS) -c queue.c

clean:
	rm *.o
