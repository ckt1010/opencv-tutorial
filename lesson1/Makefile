CXX = g++
LD = -L /usr/local/Cellar/opencv/4.1.0_1/lib/
INC = -I /usr/local/Cellar/opencv/4.1.0_1/include/opencv4
LK = -lopencv_highgui -lopencv_core -lopencv_imgcodecs -lopencv_imgproc

CXXFLAGS = -Wall -Wextra -pedantic -std=c++11 -g -fsanitize=address $(INC)
LDFLAGS =  -fsanitize=address

SRC = disPic.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = lesson1

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) $(LD) $(LK) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)