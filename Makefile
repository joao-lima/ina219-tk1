
CXXFLAGS := -Wall -O2 #-mtune=cortex-a15
PROGS := i2c-read i2c-log

all: $(PROGS)

i2c-read: Adafruit_INA219.cpp Adafruit_INA219.h i2c-read.cpp
	$(CXX) $(CXXFLAGS) -o i2c-read Adafruit_INA219.cpp i2c-read.cpp
i2c-log: Adafruit_INA219.cpp Adafruit_INA219.h i2c-log.cpp
	$(CXX) $(CXXFLAGS) -o i2c-log i2c-log.cpp Adafruit_INA219.cpp 

clean:
	rm -f $(PROGS) *.o
