make:
	g++ -c *.cpp
	g++ *.o -o tester.exe
	./tester.exe

clean:
	rm *.o
	rm tester.exe
