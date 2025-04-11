pq: main.o intMinHeap.o
        g++ -o pq main.o intMinHeap.o

main.o: main.cpp
        g++ -c main.cpp

intMinHeap.o: intMinHeap.cpp intMinHeap.h
        g++ -c intMinHeap.cpp

clean:
        rm -f pq *.o *-
