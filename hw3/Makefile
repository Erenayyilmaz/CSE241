FILES = $(shell find ./ -name "*.cpp")
INCLUDES = $(shell find ./ -name "*.h")
GCH = $(shell find ./ -name "*.gch")
OUTPUT = $(shell find ./ -name "*.out")

all: clear compile_auto clean clear compile_manuel clean

compile_auto: driver2.cpp a.cpp $(INCLUDES) $(OUTPUT) $(GCH)
	g++ -Wall -Wextra -std=c++11 $(INCLUDES) driver2.cpp a.cpp	
	./a.out

compile_manuel: driver1.cpp a.cpp $(INCLUDES) $(OUTPUT) $(GCH)
	g++ -Wall -Wextra -std=c++11 $(INCLUDES) driver1.cpp a.cpp	
	./a.out

compile:$(FILES) $(INCLUDES) $(OUTPUT) $(GCH)
#	g++ -Wall -Wextra -Werror -std=c++11 $(INCLUDES) $(FILES)
	g++ -Wall -Wextra -std=c++11 $(INCLUDES) $(FILES)
	./a.out
clean: $(OUTPUT) $(GCH)
	@rm -f $(OUTPUT)
	@rm -f $(GCH)
clear:
#	$(shell clear)
	@clear
