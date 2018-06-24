CC=gcc
CXX=g++-mp-4.2
RM=rm -f
CPPFLAGS=-std=c++11-W -Wall -fopenmp
LDFLAGS=
LDLIBS= 

BIN=tarea01
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
