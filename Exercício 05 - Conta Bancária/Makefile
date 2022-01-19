MAIN=main.c
DEPENDENCE=TADs/account/account.c TADs/tree/tree.c
UTIL=TADs/util/util.c
PROGRAMNAME=Bank_Account
IN=.in

all:
	gcc -O3 -march=native -Wall -Werror -Wextra $(UTIL) ${DEPENDENCE} $(MAIN) -o $(PROGRAMNAME) -lm

run:
	./$(PROGRAMNAME)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(PROGRAMNAME)

clean:
	@rm *.o

zip:
	@zip -r $(PROGRAMNAME).zip * 

dev:
	gcc -O3 -march=native $(UTIL) ${DEPENDENCE} $(MAIN) -o $(PROGRAMNAME) -lm && ./$(PROGRAMNAME) < $(IN) && ./$(PROGRAMNAME) < $(IN) > .out
