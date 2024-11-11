build:
	g++ -o main main.cpp pessoa.cpp principal.cpp universidade.cpp dpto.cpp professor.cpp aluno.cpp disc.cpp helpers/myList.cpp
test:
	g++ -o test test.cpp dpto.cpp helpers/myList.cpp
clean:
	rm main test