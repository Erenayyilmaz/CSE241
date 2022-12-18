FILES = $(shell find ./ -name "*.cpp")
INCLUDES = $(shell find ./ -name "*.h")
GCH = $(shell find ./ -name "*.gch")
TXT = $(shell find ./ -name "*.txt")
OUTPUT = $(shell find ./ -name "*.out")

all: clear compile_auto clean clear compile_manuel clean

compile_auto:  $(INCLUDES) $(OUTPUT) $(GCH)
	g++ -std=c++11 -U DRIVER_MODE -D DRIVER_MODE=0 -g *.cpp *.h
	./a.out
	@rm -f $(TXT)
	@rm -f $(OUTPUT)
	@rm -f $(GCH)

compile_manuel: $(INCLUDES) $(OUTPUT) $(GCH)
	g++ -std=c++11 -U DRIVER_MODE -D DRIVER_MODE=1 -g *.cpp *.h	
	./a.out
	@rm -f $(OUTPUT)
	@rm -f $(GCH)
	@rm -f $(TXT)

compile:$(FILES) $(INCLUDES) $(OUTPUT) $(GCH)
#	g++ -Wall -Wextra -Werror -std=c++11 $(INCLUDES) $(FILES)
	g++ -std=c++11 -U DRIVER_MODE -D DRIVER_MODE=0 -g *.cpp *.h
	./a.out
	g++ -std=c++11 -U DRIVER_MODE -D DRIVER_MODE=1 -g *.cpp *.h
	./a.out
clean: $(OUTPUT) $(GCH) $(TXT)
	@rm -f $(OUTPUT)
	@rm -f $(GCH)
	@rm -f $(TXT)
clear:
	@clear
