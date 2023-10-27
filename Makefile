all:
	cd src/swift && make
	cd src/cpp && make
test:
	cp src/swift/libSwiftHaptics.dylib tests/
	cd tests/ && make
debug:
	cd src/swift && make
	cd src/cpp && make debug
clean:
	cd src/swift && make clean
	cd src/cpp && make clean
	cd tests/ && make clean