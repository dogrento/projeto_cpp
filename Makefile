build:
	g++ -o main main.cpp pessoa.cpp principal.cpp universidade.cpp dpto.cpp professor.cpp aluno.cpp disc.cpp helpers/myList.cpp
test:
	g++ -o tests/test tests/test.cpp dpto.cpp universidade.cpp helpers/myList.cpp
testdb:
	g++ -o tests/dbt tests/testdb.cpp -lsqlite3
clean:
	rm main tests/test tests/dbt