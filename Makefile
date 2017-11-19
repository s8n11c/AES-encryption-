run: 
	g++ -I /usr/include/python2.7  test.cpp -lpython2.7 -o test

clean:
	rm -rf *.pyc test
