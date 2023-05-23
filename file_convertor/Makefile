CC=gcc -g
TB=txt_to_bin
BT=bin_to_txt
PATH_CS=cd ../'coding style'
PATH_CONV=../file_convertor

build: $(TB) $(BT)

$(TB):
	$(CC) $(TB).c -o $(TB)

$(BT):
	$(CC) $(BT).c -o $(BT)

valgrind_text_to_binary: build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(BT)

valgrind_text_to_binary: build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TB)

check_coding_style:
	$(PATH_CS) ; ./cs.sh $(PATH_CONV)/ ; cd $(PATH_CONV)

clean:
	rm -rf $(TB) $(BT) *.o

delete: clean
	rm -rf *.out *.in *.dat *.ref 

archive:
	zip -r file_convertor.zip Makefile *.c $(TB) $(BT)
