# Makefile
PATH := /usr/um/gcc-4.7.0/bin:$(PATH)
LD_LIBRARY_PATH := /usr/um/gcc-4.7.0/lib64
LD_RUN_PATH := /usr/um/gcc-4.7.0/lib64

CC = g++
LD = g++

CFLAGS = -pedantic -Wall -c
SERVER_LFLAGS = -ldl -pthread -lpthread
STDFLAG = -std=c++11

SERVER_OBJS = server_main.o Index_server.o mongoose.o

SERVER = indexServer_pa6

default: $(SERVER) $(INDEXER)

debug: CFLAGS += -g
debug: SERVER_LFLAGS += -g
debug: $(SERVER) $(INDEXER)

$(SERVER): $(SERVER_OBJS)
	$(LD) $(SERVER_OBJS) -o $(SERVER) $(SERVER_LFLAGS)

server_main.o: server_main.cpp Index_server.h
	$(CC) $(CFLAGS) $(STDFLAG) server_main.cpp

Index_server.o: Index_server.cpp Index_server.h
	$(CC) $(CFLAGS) $(STDFLAG) Index_server.cpp

mongoose.o: mongoose.c mongoose.h
	gcc -c mongoose.c 

clean:
	rm -rf *.o $(SERVER) $(INDEXER)
