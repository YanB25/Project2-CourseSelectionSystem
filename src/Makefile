object = main.o
header = Course.hpp Person.hpp Object.hpp System.hpp Group.hpp
CourseSelectionSystem.out : $(object)
	g++ -g $(object) -o CourseSelectionSystem.out
	./CourseSelectionSystem.out
main.o : $(header)
	g++ -c main.cpp -std=c++14 -Wall -W
.PHONY : clean
clean :
	rm *.out $(object)
