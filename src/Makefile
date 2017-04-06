object = main.o Course.o Object.o System.o
header = Course.hpp Person.hpp Object.hpp System.hpp Group.hpp
CourseSelectionSystem.out : $(object)
	g++ -g $(object) -o CourseSelectionSystem.out
	./CourseSelectionSystem.out
main.o : $(header)
	g++ -c main.cpp -std=c++14 -Wall -W
Course.o : Course.cpp Course.hpp
	g++ -c Course.cpp -std=c++14 -Wall -W
Object.o : Object.cpp Object.hpp
	g++ -c Object.cpp -std=c++14 -Wall -W
System.o : System.cpp System.hpp
	g++ -c System.cpp -std=c++14 -Wall -W
.PHONY : clean run
clean :
	rm *.out $(object)
run :
	./CourseSelectionSystem.out
