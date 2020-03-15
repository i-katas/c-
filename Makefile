.DEFAULT_GOAL=build
SHELL := bash
CPPFLAGS+=-Iext/include
CXXFLAGS+=-pedantic-errors
CXXFLAGS+=-std=c++17 -Wsign-conversion -Wextra -Werror

GTEST_LIBS=ext/libs
TEST_DIR=test
OUT_DIR=out
TEST_LINK_FILES=$(shell find ${TEST_DIR} -name *.cc | sed 's/\.cc/.o/g' | sed 's/^test/${OUT_DIR}/g') 
CHECK_CMD=${OUT_DIR}/gtest

export LD_LIBRARY_PATH=${GTEST_LIBS}

${OUT_DIR}:
	@mkdir ${OUT_DIR}

${OUT_DIR}/%.o: ${OUT_DIR}
	$(CXX) ${CPPFLAGS} ${CXXFLAGS} -c ${TEST_DIR}/$*.cc -o $@

${OUT_DIR}/gtest: ${TEST_LINK_FILES}
	$(CXX) -L${GTEST_LIBS} -lgtest_main -lgtest-all ${OUT_DIR}/*.o -o ${CHECK_CMD}

link: ${OUT_DIR}/gtest

check:
	ldd ${OUT_DIR}/gtest
	@${CHECK_CMD}

build: link check

clean:
	@rm ${OUT_DIR} -rf
