#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void userCommand(char *inp[]);

int main(int argc, char *argv[],char ** arg){
while(1){
	//input,temp ve inp dizileri için bellekten yer ayrımı yapıldı.
	char *userInput = (char*) malloc((100) * sizeof(char *));
	char *temp = (char*) malloc((100) * sizeof(char *));
	char **input = ((char **) malloc (100*sizeof(char**)));
	//Değişken tanımlamaları yapıldı ve kullanıcıdan input alındı.
	int m=0, size=0; 
		printf("myshell>>");
		gets(userInput,100,stdin); 
		//alınan input strtok methodu ile boşluklarına göre bölündü.
		temp =strtok(userInput, " ");
		//temp değerinin null olup olmadığı kontrol edildi ve değilse inp matrisine atandı.
 		while (temp != NULL) { 
    			input[m]=temp;
        		temp = strtok(NULL," "); 
        		m++; 
			size++; 
    		}
    		input[size]=NULL; 
		//kullanıcıdan alınan inputun boyutu 5ten küçükse inp matrisi parametre olarak command methoduna atandı.
			userCommand(input); 
	//kullanıcıdan input alınırken dizi temizlendi.
	free(userInput);
   }
}
//kullanıcının girdiği komutlara göre gereken işlemler gerçekleştirilir.
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