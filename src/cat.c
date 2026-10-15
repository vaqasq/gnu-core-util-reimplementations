#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define COUNT 100

int main(int argc, char *argv[]){

    // If just ./cat or ./cat -
    if (argc == 1 || (argc == 2 && (strcmp("-", argv[1]) == 0))){
       char     buf[COUNT] = {0};
       ssize_t  readin;
       ssize_t  written;

       while ((readin = read(STDIN_FILENO, buf, COUNT))){

           if (readin < 0){
               switch errno{
                   case EAGAIN:
                   case EINTR:
                       continue;
               }
               perror("");
               return 1;
           }

           written = write(STDOUT_FILENO, buf, readin);

           if (written < 0){
               switch errno{
                   case EAGAIN:
                   case EINTR:
                       continue;
               }
               perror("");
               return 1;
           }
       }
       
           
    }

    
/*
    for (int i = 1; i < argc; ++i){
        
        if (strcmp(argv[]))
    }
    */
    
}


