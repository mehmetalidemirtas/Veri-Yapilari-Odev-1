derlecalistir:program calistir
program:main
	g++ ./lib/Node.o ./lib/List.o ./lib/main.o -o ./bin/program
main:
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
	g++ -I "./include" -c ./src/List.cpp -o ./lib/List.o
	g++ -I "./include" -c ./src/Node.cpp -o ./lib/Node.o
calistir:
	./bin/program.exe