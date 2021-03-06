CXX           := /usr/bin/clang++
LD            := /usr/bin/clang++


EXEC          := main 
FLAGS 				:= -MMD -MP -g -Wall -MMD -std=c++14 
CXXFLAGS      := $(FLAGS)
LDFLAGS       := $(FLAGS)
INC           := -I inc
SRC           := $(wildcard src/*.cpp)
OBJ           := $(SRC:src/%.cpp=tmp/%.o)

EXEC_TEST     := test
FLAGS_TEST    := $(FLAGS)
CXXFLAGS_TEST := $(CXXFLAGS)
LDFLAGS_TEST  := $(LDFLAGS)
INC_TEST      := $(INC) -I lib/catch/inc
SRC_TEST      := $(wildcard tst/*.cpp)
OBJ_TEST      := $(filter-out tmp/main.o, $(OBJ)) $(SRC_TEST:tst/%.cpp=tmp/%.o)

.SUFFIXES:

# --------------------------------------------------------------

.PHONY: all
all: out/$(EXEC)

out/$(EXEC): $(OBJ)
	@$(LD) $(LDFLAGS) $^ -o $@ && echo "[OK]  $@"

# --------------------------------------------------------------

.PHONY: test
test: out/$(EXEC_TEST)

out/$(EXEC_TEST): $(OBJ_TEST)
	@$(LD) $(LDFLAGS_TEST) $^ -o $@ && echo "[OK]  $@"

# --------------------------------------------------------------

tmp/%.o: src/%.cpp
	@$(CXX) $(CXXFLAGS) -c $< $(INC) -o $@ && echo "[OK]  $@"

tmp/%.o: tst/%.cpp
	@$(CXX) $(CXXFLAGS_TEST) -c $< $(INC_TEST) -o $@ && echo "[OK]  $@"

# --------------------------------------------------------------

.PHONY: clean, clear
clean clear:
	@rm -rf out/* && echo "[CL]  out/"
	@rm -rf tmp/* && echo "[CL]  tmp/"

.PHONY: archive, zip
archive zip:
	@zip -x out/* tmp/* lib/* -q -r out/$(EXEC)-$(shell date '+%F').zip . && echo "[OK]  out/$(EXEC)-$(shell date '+%F').zip"
