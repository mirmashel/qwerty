a: main.o student.o queue.o  node.o tree.o
	g++ main.o student.o queue.o node.o tree.o -o a
main.o: main.cpp student.h queue.h node.h tree.h
	g++ -c main.cpp
student.o: student.cpp student.h
	g++ -c student.cpp
queue.o: queue.cpp queue.h student.h
	g++ -c queue.cpp
node.o: node.cpp node.h queue.h student.h
	g++ -c node.cpp
tree.o: tree.cpp tree.h node.h queue.h student.h
	g++ -c tree.cpp
clean:
	rm -f *.o a a.out
