CC=g++
CFLAGS = -O2 -W -Wall -std=c++0x
LDFLAGS = 
LIBS=-lm
SRC = $(wildcard *.cpp)
OBJS = $(SRC:.cpp=.o)
AOUT = rayTracer

all : $(AOUT) 

rayTracer : $(OBJS)
	$(CC) $(LDFLAGS) $(LIBS) -o $@ $^

%.o : %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	@rm *.o

cleaner : clean
	@rm $(AOUT)