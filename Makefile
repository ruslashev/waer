CXX = clang++
OBJS = $(patsubst source/%.cpp, objs/%.o, $(shell find source -name '*cpp'))
EXECNAME = waer

default: $(EXECNAME)
	./$(EXECNAME)

$(EXECNAME): $(OBJS)
	$(CXX) -o $@ $^ -lSDL2

objs/%.o: source/%.cpp
	$(CXX) -c -o $@ $< -Wall -Wextra -g -std=c++0x

clean:
	-rm -f $(OBJS) $(EXECNAME)

