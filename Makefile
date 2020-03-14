.DEFAULT_GOAL=build

CPPFLAGS+=-Iext/include
CXXFLAGS+=-g
GTEST_LIBS=ext/libs/*.o
TEST_DIR=test
OUT_DIR=out
CHECK_CMD=${OUT_DIR}/gtest

${OUT_DIR}:
	@mkdir ${OUT_DIR}

${OUT_DIR}/gtest.o: ${OUT_DIR}
	$(CXX) ${CPPFLAGS} ${CXXFLAGS} -c ${TEST_DIR}/*.cc -o ${OUT_DIR}/gtest.o

${OUT_DIR}/gtest: ${OUT_DIR}/gtest.o 
	$(CXX) ${CPPFLAGS} ${CXXFLAGS} ${GTEST_LIBS} ${OUT_DIR}/gtest.o -o ${CHECK_CMD}

compile: ${OUT_DIR}/gtest

check:
	@${CHECK_CMD}

build: compile check

clean:
	@rm ${OUT_DIR} -rf
