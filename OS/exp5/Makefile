CXX = g++
CXXFLAGS = -pipe -Wall -Wextra -O3 -march=native
OBJS = MFD.o UFD.o main.o command.o fileshell.o
EXEC = exp5

all: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)
clean:
	rm -rf $(OBJS) $(EXEC)
