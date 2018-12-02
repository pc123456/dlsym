
CC = g++ 
CFLAGS = -Wall  -g

INC_DIR = -I.
LIB_DIR = -L/usr/local/lib  
BIN_DIR =./bin
BIN_LIB_DIR = ./lib

SHARED_MAJOR = 1
SHARED_MINOR = 0
SHARED_NAME  = libtest.so
SHARED_ALL_NAME = $(BIN_LIB_DIR)/$(SHARED_NAME).$(SHARED_MAJOR).$(SHARED_MINOR)

SHARED_LDFLAGS = -shared
SHARED_CFLAGS = -fPIC -fvisibility=hidden

LIBSOURCES=./libtest.cpp


default:all 
all: $(SHARED_ALL_NAME)

.PHONY : $(SHARED_ALL_NAME)
$(SHARED_ALL_NAME):
	mkdir -p  $(BIN_LIB_DIR)
	$(CC) ${CFLAGS} $(SHARED_LDFLAGS) $(SHARED_CFLAGS) $(INC_DIR) $(LIBSOURCES) -o $@

clean:		
	rm -rf ./lib/* 


