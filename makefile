CC=clang++
CFLAGS=-g -ggdb -Wall -Wshadow
INC=-I include
ALLEGRO=`pkg-config allegro-5 allegro_primitives-5 allegro_image-5 --libs --cflags`


all:
	$(CC) -o Spanko.e src/*.cpp $(INC) $(ALLEGRO)

clean:
	rm -rf *.e