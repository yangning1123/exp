CC = g++
CFLAGS = -pipe -Wall -Wextra -O3 -march=native
OBJS = main.o priority.o cycle.o

exp1: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)
#$(OBJS): %.o: %.cpp
#	$(CC) -c $(CFLAGS) $< -o $@
main.o: main.cpp PCB.h
	$(CC) $(CFLAGS) -c  main.cpp 
priority.o: priority.cpp PCB.h
	$(CC) $(CFLAGS) -c priority.cpp
cycle.o: cycle.cpp
	$(CC) $(CFLAGS) -c cycle.cpp

clean:
	-rm -rf exp1 $(OBJS) 

