CXX = clang++
OBJS = main.o
EXECNAME = waer

default: $(EXECNAME)
	./$(EXECNAME)

$(EXECNAME): $(OBJS)
	$(CXX) -o $@ $^ -lSDL2

%.o: %.cpp
	$(CXX) -c -o $@ $< -Wall -Wextra -g -std=c++0x

clean:
	-rm -f $(OBJS) $(EXECNAME)

