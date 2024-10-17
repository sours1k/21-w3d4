CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./
PRINT_MODULE = ../build/Quest_1
DOCUMENTATION_MODULE = ../build/Quest_2

SRC = main_module_entry_point.c print_module.c documentation_module.c

all: $(PRINT_MODULE) $(DOCUMENTATION_MODULE)

$(PRINT_MODULE): main_module_entry_point.c print_module.c documentation_module.c
	mkdir -p ../build
	$(CC) $(CFLAGS) main_module_entry_point.c print_module.c documentation_module.c -o $(PRINT_MODULE)

$(DOCUMENTATION_MODULE): main_module_entry_point.c print_module.c documentation_module.c
	mkdir -p ../build
	$(CC) $(CFLAGS) main_module_entry_point.c print_module.c documentation_module.c -o $(DOCUMENTATION_MODULE)

clean:
	rm -rf ../build

rebuild: clean all