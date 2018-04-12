# DICTIONARY
build = a.out
input = a.in

# RULES
.PHONY: all clean run

all: $(build)

$(build): $(src)
	@g++ $(src).cpp
	@mv $(src) $(build)

clean:
	@rm -f $(build) $(input)
