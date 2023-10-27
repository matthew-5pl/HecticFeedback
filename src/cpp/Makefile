all:
	g++ -std=c++17 -c HecticFeedback.cpp -o HecticFeedback.o
	g++ -shared ../swift/libSwiftHaptics.dylib HecticFeedback.o -o libhecticfeedback.so
	rm -rf *.o *.dylib

debug:
	g++ -DHACTIC_DEBUG -std=c++17 -c HecticFeedback.cpp -o HecticFeedback.o
	g++ -shared ../swift/libSwiftHaptics.dylib HecticFeedback.o -o libhecticfeedback.so
	rm -rf *.o *.dylib

clean:
	rm -rf *.o *.dylib *.so Test