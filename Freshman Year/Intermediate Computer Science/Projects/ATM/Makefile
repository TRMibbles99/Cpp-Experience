TestATM:TestATM.o Account.o ATM.o
	g++ TestATM.o Account.o ATM.o -o TestATM

TestATM.o:TestATM.cpp Account.h ATM.h
	g++ -c TestATM.cpp -o TestATM.o

ATM.o:ATM.cpp ATM.h Account.h
	g++ -c ATM.cpp -o ATM.o

Account.o:Account.cpp Account.h
	g++ -c Account.cpp -o Account.o
