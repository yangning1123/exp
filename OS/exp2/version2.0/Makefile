CC = clang++
CCFLAGS = -pipe -Wall -Wextra -O3 -march=native
OBJS = main.o Process.o Process_Block.o
EXEC = exp2

main: $(OBJS)
	$(CC) $(CCFLAGS) -o $(EXEC) $(OBJS)
main.o: main.cpp
	$(CC) $(CCFLAGS) -c main.cpp
Process.o: Process.cpp
	$(CC) $(CCFLAGS) -c Process.cpp
Process_Block.o: Process_Block.cpp
	$(CC) $(CCFLAGS) -c Process_Block.cpp

clean:
	rm -rf $(EXEC) $(OBJS)
