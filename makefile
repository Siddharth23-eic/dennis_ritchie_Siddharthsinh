CC      = gcc
CFLAGS  = -Wall -O3 -Iinclude
LFLAGS	= -lm
OBJDIR  = obj
BINDIR  = bin
TARGET  = $(BINDIR)/main

# Collect all source files
SRCFILES := $(wildcard src/*.c src/*/main*.c src/*/source/*.c)

# Map src/chapterX/... to obj/chapterX/...
OBJS := $(patsubst src/%.c,$(OBJDIR)/%.o,$(SRCFILES))

# Fix "chapter/source/*c" → "chapter/*.o"
OBJS := $(patsubst %/source/%.o,%/%.o,$(OBJS))

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

# Generic rule: compile any .c in src/ → .o in obj/, flattening "source"
$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)

