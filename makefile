#makefile

all: sll.cpp pointers.cpp dll.cpp Bst.cpp
	g++ -o executables/sll sll.cpp
	g++ -o executables/pointers pointers.cpp
	g++ -o executables/dll dll.cpp
	g++ -o executables/bst Bst.cpp
clean:
	rm -f executables/*
