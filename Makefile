CC = gcc
FLAGS = -O2
files = asr

all: $(files)

asr: asr.c
	$(CC) $^ -o $@ $(FLAGS)

clean: 
	rm -f $(files)
