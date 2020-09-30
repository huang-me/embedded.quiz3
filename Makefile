CC = gcc
FLAGS = -O2
files = asr numofsteps compareGCD bitset powfour

all: $(files)

powfour: powfour.c
	$(CC) $^ -o $@ $(FLAGS)

bitset: bitset.c
	$(CC) $^ -o $@ $(FLAGS)

asr: asr.c
	$(CC) $^ -o $@ $(FLAGS)

numofsteps: numofsteps.c
	$(CC) $^ -o $@ $(FLAGS)

compareGCD: compareGCD.c
	$(CC) $^ -o $@ $(FLAGS)

clean: 
	rm -f $(files)
