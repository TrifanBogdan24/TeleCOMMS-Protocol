CC=gcc -g
TB=txt_to_bin
BT=bin_to_txt

build: $(TB) $(BT)

$(TB):
	$(CC) $(TB).c -o $(TB)

$(BT):
	$(CC) $(BT).c -o $(BT)

clean:
	rm -rf $(TB) $(BT) *.o *.out *.in *.dat *.ref 

archive:
	zip -r file_convertor.zip Makefile *.c $(TB) $(BT)