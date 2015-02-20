PATH := /usr/um/gcc-4.7.0/bin:$(PATH)
LD_LIBRARY_PATH := /usr/um/gcc-4.7.0/lib64
LD_RUN_PATH := /usr/um/gcc-4.7.0/lib64

FLAGS = -Wall -Wextra -pedantic -Wvla -std=c++11 -O3

debug: FLAGS += -g
debug: all

main.o: main.cpp
	g++ $(FLAGS) -pg -c main.cpp

all: 
	g++ $(FLAGS) main.cpp -o execute
# make clean - remove .o files.  You can modify it to remove whatever
clean:
	rm -f *.o market test
