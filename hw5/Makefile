FILES = $(shell find ./ -name "*.cpp")
INCLUDES = $(shell find ./ -name "*.h")
GCH = $(shell find ./ -name "*.gch")
OUTPUT = $(shell find ./ -name "*.out")

all: clear compile_auto clean clear compile_manuel clean

compile_manuel: driver1.cpp $(FILES) $(INCLUDES) $(OUTPUT) $(GCH)
	g++ -Wall -Wextra -std=c++11 TetrisAdapter.cpp tetromino.cpp driver1.cpp TetrisArray1D.cpp TetrisVector.cpp
	./a.out

compile_auto: driver2.cpp $(INCLUDES) $(OUTPUT) $(GCH)
	g++ -Wall -Wextra -std=c++11 $(INCLUDES) TetrisAdapter.cpp tetromino.cpp driver2.cpp TetrisArray1D.cpp TetrisVector.cpp
	./a.out

#compile:$(FILES) $(INCLUDES) $(OUTPUT) $(GCH)
#	g++ -Wall -Wextra -Werror -std=c++11 $(INCLUDES) $(FILES)
#	g++ -Wall -Wextra -std=c++11 $(INCLUDES) $(FILES)
#	./a.out
clean: $(OUTPUT) $(GCH)
	@rm -f $(OUTPUT)
	@rm -f $(GCH)
clear:
#	$(shell clear)
	@clear

