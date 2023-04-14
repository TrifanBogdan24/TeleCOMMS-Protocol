CC=gcc -g
PATH_CS=cd ../cs
PATH_INPUT=../input_gen
GENER=DataGenerator

build: $(GENER)

$(GENER):
	$(CC) data_generator.c -o $(GENER)

run: build
	./$(GENER)

valgrind: build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(GENER)

coding_style:
	$(PATH_CS) ; ./cs.sh $(PATH_INPUT)/ ; cd $(PATH_INPUT) 

clean:
	rm -f $(GENER)

arhive:
	zip -r generator.zip Makefile *.c *.h $(GENER)

