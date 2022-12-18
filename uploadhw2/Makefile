#g++ -Wall -Wextra -Werror -std=c++11 utils.h utils.cpp  main.cpp

FILES = $(shell find ./ -name "*.cpp")
INCLUDES = $(shell find ./ -name "*.h")
GCH = $(shell find ./ -name "*.gch")
OUTPUT = $(shell find ./ -name "*.out")

all: clear compile_auto clean clear compile_manuel clean

compile_auto: new_utils2.cpp new_main.cpp $(INCLUDES) $(OUTPUT) $(GCH)
	g++ -Wall -Wextra -std=c++11 $(INCLUDES) new_utils2.cpp new_main.cpp	
	./a.out

compile_manuel: new_utils.cpp new_main.cpp $(INCLUDES) $(OUTPUT) $(GCH)
	g++ -Wall -Wextra -std=c++11 $(INCLUDES) new_utils.cpp new_main.cpp	
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
