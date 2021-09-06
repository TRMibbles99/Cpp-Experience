CPPORTIONS = -std=c++11 -g3
LDOPTIONS =

all: test_hash test_dict movies hash_data

test_hash: hash.h hash.cpp test_hash.cpp
	g++ $(CPPOPTIONS) -o test_hash test_hash.cpp

test_dict: hash.h hash.cpp dict.h dict.cpp test_dict.cpp
	g++ $(CPPOPTIONS) -o test_dict test_dict.cpp

movies: hash.h hash.cpp dict.h dict.cpp movie.h movies.cpp
	g++ $(CPPOPTIONS) -o movies movies.cpp

hash_data: hash_data.cpp
	g++ $(CPPOPTIONS) -o hash_data hash_data.cpp

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean: tidy
	rm -f *.o
