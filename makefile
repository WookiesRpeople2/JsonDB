CC = gcc
POSTGRES_INCLUDE = drivers/postgresqlDriver/include
POSTGRES_LIB = drivers/postgresqlDriver/lib
LIB_DIR = lib
CFLAGS = -Wall -Wextra -L${POSTGRES_LIB} -I${LIB_DIR} -I$(POSTGRES_INCLUDE)
SRC_DIR = src
BUILD_DIR = build

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))


LIB_SRC_FILES = $(wildcard $(LIB_DIR)/*.c)

LIB_OBJ_FILES = $(patsubst $(LIB_DIR)/%.c, $(BUILD_DIR)/%.o, $(LIB_SRC_FILES))


TARGET = JsonDB

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJ_FILES) $(LIB_OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(LIB_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean
