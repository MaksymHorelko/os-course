CC = gcc
CFLAGS = -Wall -Iinclude

SRCDIR = src
INCDIR = include
OBJDIR = build
BINDIR = bin

SOURCES = $(SRCDIR)/main.c $(SRCDIR)/monte_carlo.c
OBJECTS = $(OBJDIR)/main.o $(OBJDIR)/monte_carlo.o
EXEC = $(BINDIR)/monte_carlo_app

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
