.PHONY: all clean

LIB_NAME_SHARED := Test_libShared
LIB_NAME_STATIC:= Test_libStatic

CUR_DIR := .
BIN_DIR := $(CUR_DIR)/bin
INC_DIR := $(CUR_DIR)/include
SRC_DIR := $(CUR_DIR)/source
OBJ_DIR := $(CUR_DIR)/objs

LIB_DIR := $(CUR_DIR)/libs
LIB_STATIC := $(LIB_DIR)/static
LIB_SHARED := $(LIB_DIR)/shared

INC_FLAGS := -I $(INC_DIR)

CC := gcc
AR := ar
ARFLAGS := rcs

mk_objs:
	$(CC) -c $(CUR_DIR)/main.c -o $(OBJ_DIR)/main.o $(INC_FLAGS) 

# Object files for the shared library need to be compiled with the -fPIC flag (PIC = position independent code).
	$(CC) -c -fPIC $(SRC_DIR)/hello.c -o $(OBJ_DIR)/hello_shared.o $(INC_FLAGS) 
	$(CC) -c -fPIC $(SRC_DIR)/math.c -o $(OBJ_DIR)/math_shared.o $(INC_FLAGS) 

# The object files for the static library don't need this flag.
	$(CC) -c $(SRC_DIR)/hello.c -o $(OBJ_DIR)/hello_static.o $(INC_FLAGS) 
	$(CC) -c $(SRC_DIR)/math.c -o $(OBJ_DIR)/math_static.o $(INC_FLAGS) 

mk_shared:
	$(CC) -shared $(OBJ_DIR)/hello_shared.o $(OBJ_DIR)/math_shared.o -o $(LIB_SHARED)/lib$(LIB_NAME_SHARED).so

mk_static:
	$(AR) $(ARFLAGS) $(LIB_STATIC)/lib$(LIB_NAME_STATIC).a $(OBJ_DIR)/hello_static.o $(OBJ_DIR)/math_static.o

install:
	cp -f $(LIB_SHARED)/lib$(LIB_NAME_SHARED).so /usr/lib

all: mk_objs mk_shared mk_static install 
	$(CC) $(OBJ_DIR)/main.o -L$(LIB_SHARED) -l$(LIB_NAME_SHARED) -o $(BIN_DIR)/shared-lib
	$(CC) $(OBJ_DIR)/main.o -L$(LIB_STATIC) -l$(LIB_NAME_STATIC) -o $(BIN_DIR)/static-lib

clean:
	rm -rf $(OBJ_DIR)/*
	rm -rf $(LIB_SHARED)/*
	rm -rf $(LIB_STATIC)/*
	rm -rf $(BIN_DIR)/*
	