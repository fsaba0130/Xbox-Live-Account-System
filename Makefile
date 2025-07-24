CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = main.cpp XboxLiveAccount.cpp Friend.cpp
OBJS = main.o XboxLiveAccount.o Friend.o

TARGET = XboxApp

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp XboxLiveAccount.h Friend.h
	$(CXX) $(CXXFLAGS) -c main.cpp

XboxLiveAccount.o: XboxLiveAccount.cpp XboxLiveAccount.h Friend.h
	$(CXX) $(CXXFLAGS) -c XboxLiveAccount.cpp

Friend.o: Friend.cpp Friend.h
	$(CXX) $(CXXFLAGS) -c Friend.cpp

clean:
	rm -f *.o $(TARGET)