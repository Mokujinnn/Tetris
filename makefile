LIBS = -lsfml-graphics -lsfml-window -lsfml-system -g
LIBSMAC = -I /Users/movavi_school/Documents/Maxim_L/include -L /Users/movavi_school/Documents/Maxim_L/lib -lsfml-graphics -lsfml-window -lsfml-system -std=c++20 -Wl, -rpath ../../lib
SRC = 
OBJ = $(SRC:.cpp=.o)
EXECUTABLE = app

all: $(SRC) $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	clang++ $(OBJ) -o $(EXECUTABLE) $(LIBSMAC) -g

%.o: %.cpp
	clang++ -c -Wall $< -o $@ -I ../../include

clean:
	rm $(EXECUTABLE) $(OBJ)
