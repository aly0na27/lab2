COMP_FLAGS = -Wextra -Wall -Werror
TARGET = test
.PHONY: clean run all
all: $(TARGET)
clean:
	rm *.o $(TARGET)
run: $(TARGET)
	./$(TARGET)

s2.o: s2.c
	gcc -c s2.c
s8.o: s8.c
	gcc -c s8.c
s16.o: s16.c
	gcc -c s16.c
clac.o: clac.c
	gcc -c clac.c
main.o: main.c
	gcc -c main.c
$(TARGET): s2.o s8.o s16.o clac.o main.o
	gcc s2.o s8.o s16.o clac.o main.o -lm -o $(TARGET) $(COMP_FLAGS)

