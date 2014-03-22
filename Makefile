GTEST_DIR = ./lib/gtest-1.7.0

USER_DIR = ./src/main

TEST_DIR = ./src/test

TESTS = TestAnt

CPPFLAGS += -isystem $(GTEST_DIR)/include

CXXFLAGS += -g -Wall -Wextra -pthread

all : $(TESTS)

runtests : all
	./TestAnt

clean :
	rm -f $(TESTS) *.o

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
				$(GTEST_DIR)/include/gtest/internal/*.h
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
		$(GTEST_DIR)/src/gtest-all.cc

Ant.o : $(USER_DIR)/Ant.cpp $(USER_DIR)/Ant.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) -I$(USER_DIR) $(CXXFLAGS) -c $(USER_DIR)/Ant.cpp

TestAnt.o : $(TEST_DIR)/TestAnt.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -I$(USER_DIR) -c $(TEST_DIR)/TestAnt.cpp

TestAnt : Ant.o TestAnt.o gtest-all.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@

