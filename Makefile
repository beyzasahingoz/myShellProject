make: myshell writef execx clear

myshell: myshell.c
	 gcc myshell.c -o myshell -lreadline

writef: writef.c 
	gcc writef.c -o writef 

execx: execx.c 
	gcc execx.c -o execx

clear: 
	rm -rf *o shell
