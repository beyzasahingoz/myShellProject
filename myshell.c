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
		printf("myshell>>");
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
//operations are performed according to the commands entered by the user.
void userCommand(char *input[]){
	if(strcmp(input[0],"exit")==0){
		exit(0);
	}else if(strcmp(input[0],"bash")==0){
  		system("/bin/bash");
  	}else if(strcmp(input[0],"cat")==0){
  		printf("cat:%s\n",input[1]);
  	}else if(strcmp(input[0],"ls")==0){
    		system("/bin/ls");
   	}else if (strcmp(input[0],"clear")==0){
        	system("clear");
    }else if(strcmp(input[0],"execx")==0){
  		int i,m;
  		i = fork();
            	if(i == 0){  
                	m = execve("execx",input,NULL); 
                	perror("execx failed\n");
            	}else{
                	wait(&m);
            	}  	
  	}else if(strcmp(input[0],"writef")==0){
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
