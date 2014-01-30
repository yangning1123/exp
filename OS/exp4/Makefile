CC = g++
CCFLAGS = -pipe -Wall -Wextra -O3 -march=native
OBJS = Procedure.o main.o
EXEC = exp4

all: $(OBJS)
	$(CC) $(CCFLAGS) -o $(EXEC) $(OBJS)
%.o: %.cpp
	$(CC) $(CCFLAGS) -c  $< -o $@

clean:
	rm -rf $(EXEC) $(OBJS)
