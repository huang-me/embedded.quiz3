CC = gcc
FLAGS = -O2
files = asr numofsteps compareGCD bitset

all: $(files)

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
