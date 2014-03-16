CC			= gcc
CXX			= g++
INCLUDES	= include
CFLAGS		= -Wall #$(shell pkg-config --cflags --libs glib-2.0)
ELFS		= $(shell find . -exec file {} \;|grep ELF|cut -d: -f1)

%:%.cpp
	$(CXX) $(CFLAGS) $(SYMBOLS:%=-D%) $(INCLUDES:%=-I%) $(LDPATH:%=-L%) $(LIBS:%=-l%) lib/*.c $< -o $@

%:%.c
	$(CC) $(CFLAGS) $(SYMBOLS:%=-D%) $(INCLUDES:%=-I%) $(LDPATH:%=-L%) $(LIBS:%=-l%) lib/*.c $< -o $@

clean:
	rm -f $(ELFS)

