src_path = ./src
exe_path = ~/
exe_name = exe

CC = gcc #aarch64-xilinx-linux-gcc
CFLAGS = -g -Wall -Iinclude -lpthread -lstdc++ -O0 -o ${exe_path}${exe_name}

all: source

source: $(wildcard ${src_path}/*.c)
	@clear
	@${CC} ${CFLAGS} $^

run: source
	@${exe_path}${exe_name}

clean:
	@clear
	@rm -r ${exe_path}${exe_name}
