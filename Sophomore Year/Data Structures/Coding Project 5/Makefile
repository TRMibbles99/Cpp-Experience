CPPORTIONS = -std=c++11 -g3
LDOPTIONS =

all: test_bst test_dict movies

test_bst: bst.h bst.cpp test_bst.cpp
	g++ $(CPPOPTIONS) -o test_bst test_bst.cpp

test_dict: bst.h bst.cpp dict.h dict.cpp test_dict.cpp
	g++ $(CPPOPTIONS) -o test_dict test_dict.cpp

movies: bst.h bst.cpp dict.h dict.cpp movie.h movies.cpp
	g++ $(CPPOPTIONS) -o movies movies.cpp

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean: tidy
	rm -f *.o
