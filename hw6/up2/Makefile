OUTPUT = $(shell find ./ -name "*.out")

all: clear compile clean

compile: $(OUTPUT) $(GCH)
	g++ -std=c++11 -g main.cpp
	./a.out
	@rm -rf $(OUTPUT)
	

# compile: $(OUTPUT) $(GCH)
# 	g++ -Wall -Wextra -Werror -std=c++11 -g main.cpp
# 	./a.out
# 	@rm -rf $(OUTPUT)


#compile:$(FILES) $(INCLUDES) $(OUTPUT) $(GCH)
#	g++ -Wall -Wextra -Werror -std=c++11 $(INCLUDES) $(FILES)
#	g++ -Wall -Wextra -std=c++11 $(INCLUDES) $(FILES)
#	./a.out
clean: $(OUTPUT) $(GCH)
	@rm -f $(OUTPUT)
clear:
#	$(shell clear)
	@clear

