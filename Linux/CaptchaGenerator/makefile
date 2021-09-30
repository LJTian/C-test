ExecName=main

OBJ1=${ExecName}.c 

OBJ2=${ExecName}.o

all: clean
	gcc -c ${OBJ1} -o ${OBJ2}
	gcc ${OBJ2} -o ${ExecName}
	rm -rf ${OBJ2}

clean:
	rm -rf ${OBJ2} ${ExecName}
