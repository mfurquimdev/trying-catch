NAME=t9

SRC_DIR=./src
OBJ_DIR=./obj
INC_DIR=./inc
TEST_DIR=./test
MAIN_DIR=./main
BIN_DIR=./bin

SRC = ${wildcard $(SRC_DIR)/*.cpp}
MAIN = ${wildcard $(MAIN_DIR)/*.cpp}
TEST = ${wildcard $(TEST_DIR)/*.cpp}

OBJ = ${addprefix $(OBJ_DIR)/, ${notdir ${SRC:.cpp=.o}}}
MOBJ = ${addprefix $(OBJ_DIR)/, ${notdir ${MAIN:.cpp=.o}}}
TOBJ = ${addprefix $(OBJ_DIR)/, ${notdir ${TEST:.cpp=.o}}}

INC = -I$(INC_DIR)

CC=g++
CFLAGS= -Wall -Wextra -pedantic -ansi -std=c++11 -Ofast
LFLAGS= -lm

TARGET_MAIN=$(BIN_DIR)/$(NAME)_main
TARGET_TEST=$(BIN_DIR)/$(NAME)_test

all: dirs
	@$(MAKE) $(TARGET_MAIN)
	@$(MAKE) $(TARGET_TEST)

dirs:
	@mkdir -vp $(OBJ_DIR) $(BIN_DIR)

$(TARGET_MAIN): $(OBJ) $(MOBJ)
	@echo
	@echo Linking $@
	$(CC) -o $@ $(OBJ) $(MOBJ) $(LIB) $(LFLAGS)

$(TARGET_TEST): $(OBJ) $(TOBJ)
	@echo
	@echo Linking $@
	$(CC) -o $@ $(OBJ) $(TOBJ) $(LIB) $(LFLAGS)

$(OBJ_DIR)/%.o:  $(SRC_DIR)/%.cpp
	@echo
	@echo Building $@
	$(CC) -c $^ -o $@ $(CFLAGS) $(INC)

$(OBJ_DIR)/%.o:  $(MAIN_DIR)/%.cpp 
	@echo
	@echo Building $@
	$(CC) -c $^ -o $@ $(CFLAGS) $(INC)

$(OBJ_DIR)/%.o:  $(TEST_DIR)/%.cpp
	@echo
	@echo Building $@
	$(CC) -c $^ -o $@ $(CFLAGS) $(INC)

clean:
	@echo Cleaning...
	@rm -rvf *~ *.err $(OBJ_DIR) $(TARGET) $(TARGET_TEST) 

.PRECIOUS: %.o
