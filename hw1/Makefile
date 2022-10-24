#g++ -Wall -Wextra -Werror -std=c++11 utils.h utils.cpp  main.cpp

FILES = $(shell find ./ -name "*.cpp")
INCLUDES = $(shell find ./ -name "*.h")
GCH = $(shell find ./ -name "*.gch")
OUTPUT = $(shell find ./ -name "*.out")

all:
	clear
	compile
	clean

compile:$(FILES) $(INCLUDES) $(OUTPUT) $(GCH)
#	g++ -Wall -Wextra -Werror -std=c++11 $(INCLUDES) $(FILES)
	g++ -Wall -Wextra -std=c++11 $(INCLUDES) $(FILES)
	./a.out
clean: $(OUTPUT) $(GCH)
	rm -f $(OUTPUT)
	rm -f $(GCH)
clear:
	$(shell clear)
