CC = g++
CCFLAGS = -pipe -Wall -Wextra -O3 -march=native

OBJS = main.o Procedure.o
EXEC = exp3

main: $(OBJS)
	$(CC) $(CCFLAGS) -o $(EXEC) $(OBJS)

clean:
	rm -rf $(EXEC) $(OBJS)
