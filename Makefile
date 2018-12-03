
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
LIBSOURCES=./lib/src/libtest.cpp  ./lib/src/strlib.c

TEST_BIN_NAME = tstld
TEST_BIN_ALL_NAME = $(BIN_DIR)/$(TEST_BIN_NAME)
BINSOURCES = ./main.cpp \
  	     ./lib/src/ilibtest.cpp

default:all 
all: $(SHARED_ALL_NAME) $(TEST_BIN_ALL_NAME) 

.PHONY: $(SHARED_ALL_NAME)
$(SHARED_ALL_NAME):
	 	mkdir  -p $(BIN_LIB_DIR)
	 	$(CC) ${CFLAGS} $(SHARED_LDFLAGS) $(SHARED_CFLAGS) $(INC_DIR) $(LIBSOURCES) -o $@

.PHONY: $(TEST_BIN_ALL_NAME)
$(TEST_BIN_ALL_NAME):
		mkdir  -p  $(BIN_DIR)
		$(CC)  $(CFLAGS) $(LIB_DIR)  -ldl $(BINSOURCES) -o $@

clean:		
	rm -rf ./lib/*.so.*
	rm -rf ./bin/*


