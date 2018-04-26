CXX = g++
CXXFLAGS +=
LDFLAGS += -lgtest -lpthread
EXEC = stackTest

all: $(EXEC)

.PHONY: all

stackTest:stackTest.c
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(EXEC) *.o

.PHONY: clean
