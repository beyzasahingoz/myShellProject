#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[])
{
   //defined variables
   FILE *fptr;
   char c;
   size_t size = 10;
   int p_id, p_pid;
   time_t seconds;
   struct tm *timeStruct;
   //received current time.
   time(&seconds);
   timeStruct = localtime(&seconds);
   //received pid and ppid
   p_id = getpid();
   p_pid = getppid();
   //received input from user.
   char *input = malloc(sizeof(char) * size);
   printf("Enter input: ");
   getline(&input, &size, stdin);
   //if the file is not created, created and writed by user.
   fptr = fopen(argv[argc - 1], "a");
   //if the file is created, writed by user.
   if (fptr != NULL)
   {
      //text and time are printed to the file.
      fprintf(fptr, "%s\n", input);
      fprintf(fptr, "Current time : %d:%d:%d pid: %d ppid: %d\n--\n", timeStruct->tm_hour, timeStruct->tm_min, timeStruct->tm_sec, p_id, p_pid);
      fclose(fptr);

      fptr = fopen(argv[argc - 1], "r");
      while ((c = fgetc(fptr)) != EOF)
      {
         printf("%c", c);
      }
      fclose(fptr);
      return 0;
   }
   //text and time are printed to the file.
   fprintf(fptr, "Current time : %d:%d:%d pid: %d ppid: %d\n--\n", timeStruct->tm_hour, timeStruct->tm_min, timeStruct->tm_sec, p_id, p_pid);
   fprintf(fptr, "%s\n", input);

   fclose(fptr);
   fptr = fopen(argv[argc - 1], "r");

   while ((c = fgetc(fptr)) != EOF)
   {
      printf("%c", c);
   }
   fclose(fptr);
   free(input);

   return 0;
}
