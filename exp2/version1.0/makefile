CC = clang++
CCFLAGS = -Wall -c 
#GDBFLAGS = -g
OBJS = main.o initial.o banker.o security.o
EXEC = exp2

main: $(OBJS)
	$(CC) $(GDBFLAGS) -o $(EXEC) $(OBJS)
main.o: main.cpp
	$(CC) $(CCFLAGS) $(GDBFLAGS) main.cpp
initial.o: initial.cpp
	$(CC) $(CCFLAGS) $(GDBFLAGS) initial.cpp
banker.o: banker.cpp
	$(CC) $(CCFLAGS) $(GDBFLAGS) banker.cpp
security.o: security.cpp
	$(CC) $(CCFLAGS) $(GDBFLAGS) security.cpp

clean:
	rm -rf $(OBJS) $(EXEC)