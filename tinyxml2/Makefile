ver = release
name = libtinyxml2.so

CROSS = arm-linux-
CC = $(CROSS)gcc
CXX = $(CROSS)g++
LD = $(CROSS)g++

SO_NAME=$(name)
BIN_DIR=./
INCPATH = -I./
LIBPATH = -L./
LDFLAGS = $(LIBPATH) -lpthread -ldl -lrt -fPIC -shared -Wno-psabi

OUT_DIR=$(BIN_DIR)/
CFLAGS = -Wall -c $(INCPATH) $(LDFLAGS) 
CXXFLAGS = -Wall -c $(INCPATH) $(LDFLAGS)

C_SRCS = $(wildcard *.c)
C_OBJS = $(patsubst %c, %o, $(C_SRCS))

CXX_SRCS = $(wildcard *.cpp)
CXX_OBJS = $(patsubst %cpp, %o, $(CXX_SRCS))

H_SRCS = $(wildcard *.h)

TARGET = $(OUT_DIR)$(SO_NAME)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(C_OBJS) $(CXX_OBJS)
	$(LD) -o $@ $^ $(LDFLAGS)

%o: %c $(H_SRCS)
	$(CC) $(CFLAGS) -o $@ $<

%o: %cpp $(H_SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f *.o *.so $(TARGET) $(OUT_DIR)*.so
