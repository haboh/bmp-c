CC=gcc
INC=-Iinclude
OUT=hw-01_bmp
SDIR=src
ODIR=obj
_FLAGS = -std=c11 -Wall -Wextra -std=c11 -pedantic -Wno-gnu -Wmissing-prototypes -Wpointer-arith -Wshadow -Wcast-qual -Wstrict-prototypes -Wold-style-definition -Wno-unused-parameter -O2 -g
_OBJS=main.o bmp.o stego.o
OBJS=$(patsubst %,$(ODIR)/%,$(_OBJS))

all: $(OUT)

$(ODIR):
	mkdir $(ODIR)

$(OUT): $(ODIR) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(OUT)

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(FLAGS) -c $(INC) $< -o $@

clean:
	rm -rf obj/*.o $(OUT) obj

.PHONY: clean


