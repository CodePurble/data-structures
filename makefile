# Configure file directories
BIN_DIR=./bin
SRC_DIR=./src
INCLUDE_DIR=./include
EXEC=test

CFLAGS += -Wall -g -I$(INCLUDE_DIR)/

COMPILE=$(CXX) $(CFLAGS) -c $^ -o $@
LINK_EXE=$(CXX) $(CFLAGS) -o $@ $^

# Create lists of src and object files for src dir
SRC_FILES=$(wildcard $(SRC_DIR)/*.cpp)									# Get .c files in source
SRC_OBJS=$(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o, $(SRC_FILES))		# Get name of .o files in source

# Create bin directory if it doesn't exist
$(shell if [ ! -d "${BIN_DIR}" ]; then mkdir -p ${BIN_DIR}; fi;)

# Create src object files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(COMPILE)

# A phony target is one that is not really the name of a file;
# rather it is just a name for a recipe to be executed when you make an explicit request
# All targets that generate files should have target name = name of file
# so that make can correctly track if we need to rebuild the target
.phony: all clean 

all: $(BIN_DIR)/$(EXEC)

$(BIN_DIR)/$(EXEC): $(SRC_OBJS)
	$(LINK_EXE)

clean:
	rm -rf $(BIN_DIR)/*
