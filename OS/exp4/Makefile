CC = g++
OBJS = Procedure.o main.o
EXEC = exp4

all: $(OBJS)
	$(CC) -g -o $(EXEC) $(OBJS)
%.o: %.cpp
	$(CC) -c -g $< -o $@

clean:
	rm -rf $(EXEC) $(OBJS)
