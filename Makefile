CC=g++ -std=c++11

all: fractal linkedlist

fractal: recursion.cpp
	$(CC) recursion.cpp -o fractal

linkedlist: test_linked_list.o node.o linked_list.o
	$(CC) test_linked_list.o node.o linked_list.o -o linkedlist

test_linked_list.o: test_linked_list.cpp
	$(CC) -c test_linked_list.cpp

node.o: node.cpp
	$(CC) -c node.cpp

linked_list.o: linked_list.cpp
	$(CC) -c linked_list.cpp


clean:
	rm -f *.o fractal linkedlist