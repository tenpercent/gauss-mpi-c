CXX = mpicc
ARGS = -O0 -lm
ARGS_FAST = -O3 -lm -Wall
FILES = main.c io.c tools.c gauss-invert.c multiplication.c simpleinvert.c residual.c

all: release debug
release:
	$(CXX) $(ARGS_FAST) $(FILES) -o test.out
debug:
	$(CXX) -g $(ARGS) $(FILES) -o testd.out
clean:
	rm *.out 
archive:
	tar -cf backup.tar .
