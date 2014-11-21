NUM_MOVES?=10000
MOVES_SEED?=350

compile:
	g++ *.cpp -o chess -g -O0 -fprofile-arcs -ftest-coverage

test:
	python generator.py $(NUM_MOVES) $(MOVES_SEED) > moves
	./chess < moves > output.txt
  
coverage: coverage-xml coverage-html
  
coverage-xml:
	gcovr -x --xml-pretty -r . -k -v -o cobertura.xml -s

coverage-html:
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info -o reports

clear-all:
	rm -rf coverage.info *.gcda *.gcno *.gcov gmon.out chess cobertura.xml

profiler:
	# valgrind --tool=callgrind --log-file=analysis.txt ./chess < moves > output.txt
	valgrind --leak-check=yes --log-file=analysis.txt ./chess < moves > output.txt
	cat analysis.txt
