CC = g++
CFLAGS = -lz -lssl -lcrypto
TARGET = filemanager
SRC = src/main.cpp
INSTALL_PATH = /usr/local/bin

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) -o $(TARGET) $(SRC) $(CFLAGS)

install: $(TARGET)
	cp $(TARGET) $(INSTALL_PATH)
	echo Installed

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean run install

