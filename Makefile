CC=g++

init:
	if ! [ -d ./OBJ ]; then mkdir OBJ; fi
	if ! [ -d ./LOGS ]; then mkdir LOGS; fi
	if ! [ -d ./EXEC ]; then mkdir EXEC; fi
all:
	cd src && $(CC) -c -I ../hdr *.cpp && mv *.o ../OBJ/
	cd OBJ && $(CC) -o dbShell -I ../hdr *.o

all-run:
	cd src && $(CC) -c -I ../hdr *.cpp && mv *.o ../OBJ/
	cd OBJ && $(CC) -o dbShell -I ../hdr *.o
	cd OBJ && mv dbShell.exe ../EXEC/
