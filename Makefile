.DEFAULT_GOAL=build
SHELL := bash
CPPFLAGS+=-Iext/include
CXXFLAGS+=-g

GTEST_LIBS=ext/libs/*.o
TEST_DIR=test
OUT_DIR=out
TEST_LINK_FILES=$(shell find ${TEST_DIR} -name *.cc | sed 's/\.cc/.o/g' | sed 's/^test/${OUT_DIR}/g') 
CHECK_CMD=${OUT_DIR}/gtest

${OUT_DIR}:
	@mkdir ${OUT_DIR}

${OUT_DIR}/%.o: ${OUT_DIR}
	$(CXX) ${CPPFLAGS} ${CXXFLAGS} -c ${TEST_DIR}/$*.cc -o $@

${OUT_DIR}/gtest: ${TEST_LINK_FILES}
	$(CXX) ${CPPFLAGS} ${CXXFLAGS} ${GTEST_LIBS} ${OUT_DIR}/*.o -o ${CHECK_CMD}

compile: ${OUT_DIR}/gtest

check:
	@${CHECK_CMD}

build: compile check

clean:
	@rm ${OUT_DIR} -rf
