build:
	g++ -o main main.cpp src/pessoa.cpp src/principal.cpp src/universidade.cpp src/dpto.cpp src/professor.cpp src/aluno.cpp src/disc.cpp helpers/myList.cpp
test:
	g++ -o tests/test tests/test.cpp src/dpto.cpp src/universidade.cpp helpers/myList.cpp
testdb:
	# g++ -o tests/dbt tests/testdb.cpp -lsqlite3
	g++ -o tests/dbt tests/outrotestdb.cpp helpers/dbhandler.cpp -lsqlite3
clean:
	rm main tests/test tests/dbt
# Variáveis
