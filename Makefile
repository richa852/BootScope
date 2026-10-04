XX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = bootscope

SRC = src/main.cpp \
      src/system_info.cpp \
      src/boot_profiler.cpp \
      src/dependency_analyzer.cpp \
      src/optimizer.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
	rm -f src/*.o
	rm -f src/*_test
	rm -f src/bootscope
