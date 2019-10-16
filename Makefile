CC = gcc
TARGET = exe
OBJECTS = histogram.o equalization.o
PYTHON = -lpython3.7m

$(TARGET) : $(OBJECTS)
	$(CC) -o $(TARGET) main.c -I/usr/include/python3.7 $(PYTHON)

histogram.o : histogram.py
	$(CC) -c -o histogram.o histogram.py -I/usr/include/python3.7 $(PYTHON)

equalization.o : equalization.py
	$(CC) -c -o equalization.o equalization.py -I/usr/include/python3.7 $(PYTHON)

clean :
	rm *.o exe
