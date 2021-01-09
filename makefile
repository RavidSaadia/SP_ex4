all: frequency

frequency: main.o Trie.o
	gcc -Wall main.o Trie.o -o frequency

Trie.o: Trie.c trieh.h
	gcc -Wall -c Trie.c

main.o: main.c trieh.h
	gcc -Wall -c main.c

clean:
	rm -f *.o frequency

.PHONY: clean all