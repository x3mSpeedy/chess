compile:
  g++ *.cpp *.h -o chess -g -O0 -fprofile-arcs -ftest-coverage

test:
  python generator.py 3000 456 > moves
  ./chess < moves
  
coverage:
  gcovr -x --xml-pretty -r . -k -v -o cobertura.xml -s
  lcov --capture --directory . --output-file coverage.info
  genhtml coverage.info -o reports
  
