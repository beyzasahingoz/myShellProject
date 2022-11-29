#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void userCommand(char *inp[]);

int main(int argc, char *argv[],char ** arg){
while(1){
	//allocated memory for input,temp and inp arrays.
	char *userInput = (char*) malloc((100) * sizeof(char *));
	char *temp = (char*) malloc((100) * sizeof(char *));
	char **input = ((char **) malloc (100*sizeof(char**)));
	//defined variable and receipt input from user.
	int m=0, size=0; 
		printf("\nmyshell>>");
		gets(userInput,100,stdin); 
		//the input received was divided according to its spaces with the strtok method.
		temp =strtok(userInput, " ");
		//checked if the temp value is null and if not it is assigned to the inp matrix.
 		while (temp != NULL) { 
    			input[m]=temp;
        		temp = strtok(NULL," "); 
        		m++; 
			size++; 
    		}
    		input[size]=NULL; 
		//if the input size from the user is less than 5, the inp matrix is assigned to the command method as a parameter.
			userCommand(input); 
	//array is cleared while receiving input from the user.
	free(userInput);
   }
}
//operations are performed according to the commands entered by the user and check the inputs.
void userCommand(char *input[]){
	int f,stat;
	int size= findLength(input);
	if(strcmp(input[0],"exit")==0){
		exit(0);
	}else if(strcmp(input[0],"bash")==0 && size==1){
  		system("/bin/bash");
  	}else if(strcmp(input[0],"cat")==0 && size>1){
		f=fork();
		if(f==0){
			stat = execv("/bin/cat",input);
			perror("exec failed");
		}else{
			//wait child process
			wait(&stat);
		}
  	}else if(strcmp(input[0],"ls")==0 && size==1){
    		system("/bin/ls");
   	}else if (strcmp(input[0],"clear")==0 && size==1){
        	system("clear");
    }else if(strcmp(input[0],"execx")==0 && !strcmp(input[1], "-t")&& isNumber(input[2])== 1 && size>=4){
  		int i,m;
  		i = fork();
            	if(i == 0){  
                	m = execve("execx",input,NULL); 
                	perror("execx failed\n");
            	}else{
                	wait(&m);
            	}  	
  	}else if(strcmp(input[0],"writef")==0 && !strcmp(input[1], "-f")&& input[2] != NULL && size==3){
  		int i,m;
  		i = fork();
            	if(i == 0){
                	m = execve("writef",input,NULL);
                	perror("writef failed\n");
            	}else{
                	wait(&m); 
            	}  	
  	}else{
  		printf("Wrong command!\n");
  	}
}
//this method checks if the input is a number.
int isNumber(char *n){
	int i=strlen(n);
	int isNum=(i>0);
	while(i-- && isNum){
		if(!(n[i]>='0'&& n[i]<='9')){
			isNum=0;
		}
	}
	return isNum;
}
// this method finds argv length.
int findLength(char **input[]){
	int size=0,i;
	for (i = 0; input[i]!='\0'; i++)
	{
		size++;
	}
	return size;
	
} 
