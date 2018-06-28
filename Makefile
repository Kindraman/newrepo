CC=gcc
CXX=g++
RM=rm -f rm *.txt
CPPFLAGS=-std=c++11 -W -Wall -fopenmp 
LDFLAGS=
LDLIBS= 

BIN=tareaOMP
SRCS=$(wildcard *.cc)
OBJS=$(subst .cc,.o,$(SRCS))

all: $(BIN)

$(BIN): $(OBJS)
	$(CXX) $(CPPFLAGS) $(LDFLAGS) -o $(BIN) $(OBJS) $(LDLIBS)

%.o: %.cc
		$(CXX) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)
	$(RM) *~


distclean: clean
	$(RM) $(BIN)
