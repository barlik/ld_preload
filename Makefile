all: unrandom.so inspect_open.so random_num

inspect_open.so: inspect_open.c
	gcc -shared -fPIC inspect_open.c -o inspect_open.so -ldl

unrandom.so: unrandom.c
	gcc -shared -fPIC unrandom.c -o unrandom.so

random_num: random_num.c
	gcc random_num.c -o random_num

