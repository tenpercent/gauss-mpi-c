CXX = mpicc
ARGS = -O0 -lm
ARGS_FAST = -O3 -lm -Wall
FILES = main.c io.c tools.c gauss-invert-faster-rewrite.c multiplication-mod.c simpleinvert-mod.c residual.c
OLD_FILES = main.c io.c tools.c gauss-invert.c multiplication.c simpleinvert.c residual.c

all: release old_release
release:
	$(CXX) $(ARGS_FAST) $(FILES) -o test.out
debug:
	$(CXX) -g $(ARGS) $(FILES) -o testd.out
old_release:
	$(CXX) $(ARGS_FAST) $(OLD_FILES) -o test_old.out
clean:
	rm *.out 
archive:
	tar -cf backup.tar .
