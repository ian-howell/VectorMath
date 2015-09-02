make:
	g++ -c *.cpp
	g++ *.o -o tester.exe
	./tester.exe
	make clean

clean:
	rm *.o
	rm tester.exe
