#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char * argv[]){
    //the command is executed whichever argv equals that string
    int f,j;
    if(strcmp(argv[3], "clear") == 0){
        printf("\033[H\033[J"); 
    } else if(strcmp(argv[3], "ls") == 0){
        for(int i = 0; i < atoi(argv[2]); i++){
            system("/bin/ls");
        }
    } else if(strcmp(argv[3], "cat") == 0){
        for(int i = 0; i < atoi(argv[2]); i++){
            printf("cat:%s\n", argv[4]);
        }
    } else if(strcmp(argv[3], "bash") == 0){
        for(int i = 0; i < atoi(argv[2]); i++){
            system("/bin/bash");
        }
    } else if(strcmp(argv[3], "exit") == 0){
        exit(0);
    } else if(strcmp(argv[3], "writef") == 0){
        for(int i = 0; i < atoi(argv[2]); i++){
            //the fork runs until the number entered
            f=fork();
            if(f==0){
                j= execve("writef", argv,NULL);
                exit(0);
                perror("exec failed");
            }else{
                wait(&j);
            }
        }
    } else {
        //if the input is not equal to any command, the input is written
        for(int i = 0; i < atoi(argv[2]); i++){
            printf("%s\n", argv[3]);
        }
    }
}
