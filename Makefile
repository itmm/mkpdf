.PHONY: test clean

SOURCEs := $(wildcard *.md)

md-run: $(SOURCEs)
	mdp README.md
	date > md-run
	$(MAKE) test

clean:
	rm -f md-run mkpdf-tests

test: mkpdf-tests
	./mkpdf-tests

mkpdf-tests: mkpdf-tests.cpp mkpdf.h mkpdf.cpp
	$(CXX) $(CXXFLAGS) mkpdf-tests.cpp mkpdf.cpp -o $@

