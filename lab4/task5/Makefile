CC = gcc
CFLAGS = -Wall -Iinclude

SRCDIR = src
INCDIR = include
OBJDIR = build
BINDIR = bin

SOURCES = $(SRCDIR)/main.c $(SRCDIR)/mysystem.c
OBJECTS = $(OBJDIR)/main.o $(OBJDIR)/mysystem.o
EXEC = $(BINDIR)/my_program

all: $(EXEC)

$(EXEC): $(OBJECTS) | $(BINDIR)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXEC)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BINDIR):
	mkdir -p $(BINDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(BINDIR)
