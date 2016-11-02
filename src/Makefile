sample.out: other.o jni_test.o sample.o
	g++ other.o jni_test.o sample.o -o sample.out

other.o: other.c
	gcc -Wall -c other.c

jni_test.o: jni_test.cpp
	g++ -Wall -c jni_test.cpp

sample.o: sample.cpp
	g++ -Wall -c sample.cpp

clean:
	rm -rf *.o
