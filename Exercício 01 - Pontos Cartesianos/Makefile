MAIN=main.c
UTIL=caminho.c ponto.c
BINARY=executavel

all:
	gcc -Wall -g $(UTIL) $(MAIN) -o $(BINARY) -lm

run:
	./$(BINARY)
	
debug:
	gcc -DDEBUG -lm -Wall $(MAIN) $(UTIL) -o $(BINARY)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

clean:
	@rm *.o

zip:
	@zip -r ex1.zip * 