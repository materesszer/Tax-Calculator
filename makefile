CC = g++
CFLAGS = -Iinputs -Icalculator

all: taxalpha

taxalpha: taxalpha.cpp inputs/inputValidator.h inputs/inputHandling.cpp calculator/taxCalculator.cpp
	$(CC) $(CFLAGS) taxalpha.cpp inputs/inputHandling.cpp calculator/taxCalculator.cpp -o taxalpha

clean:
	rm -f taxalpha
