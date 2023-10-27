CC=g++
CFLAGS=-std=c++17 -I../src/cpp/
LFLAGS=-L../src/cpp/ -lhecticfeedback
SRC=./
BIN=./

SRCS=$(wildcard $(SRC)/*.cpp)
BINS=$(SRCS:$(SRC)/%.cpp=%)

all: $(BINS)

%: $(SRC)/%.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< $(LFLAGS)

clean:
	rm -rf $(BIN)*.dylib $(BIN)*.so $(BINS) 