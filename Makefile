CC = gcc
TARGET = program.exe
OBJECTS = main.c
SUB_OBJECTS = lib/histogram.py lib/equalization.py
PYTHON = -lpython3.7m

$(TARGET) : $(OBJECTS)
	$(CC) -o $(TARGET) main.c -I/usr/include/python3.7 $(PYTHON)

$(OBJECTS) : $(SUB_OBJECTS)
	$(CC) -c -o $(OBJECTS) $(SUB_OBJECTS) -I/usr/include/python3.7 $(PYTHON)

clean :
	rm *.exe
