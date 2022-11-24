#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[])
{
   FILE *fptr;
   char c;
   size_t size = 10;
   int p_id, p_pid;
   time_t seconds;
   struct tm *timeStruct;

   time(&seconds);
   timeStruct = localtime(&seconds);

   p_id = getpid();
   p_pid = getppid();

   char *input = malloc(sizeof(char) * size);
   printf("Enter input: ");
   getline(&input, &size, stdin);

   fptr = fopen(argv[argc - 1], "a");

   if (fptr != NULL)
   {
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