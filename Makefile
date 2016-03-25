PROG=Macierze

all: main.cpp macierz.cpp
	$(CXX)  -g -std=c++11 -o $(PROG) main.cpp macierz.cpp
clean:
	$(RM) $(PROG)
