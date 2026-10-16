#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define COUNT 100

int meow(int inputFD);

int main(int argc, char *argv[]){

    // If just ./cat or ./cat -
    if (argc == 1 || (argc == 2 && (strcmp("-", argv[1]) == 0))){
        int rc = meow(STDIN_FILENO);
        return rc;
    }

    // Otherwise, cat - filenames, or cat filenames

    int *fdArr = malloc((argc-1) * sizeof(*fdArr));
    int entries_fdArr = 0;
    bool dashPresent = false;


    for (int i = 1; i < argc; ++i){

        if (strcmp(argv[i], "-") == 0){
            if (dashPresent)
                continue;
            fdArr[entries_fdArr] = STDIN_FILENO;
            entries_fdArr++;
            dashPresent = true; 
        }

        // just open files now/check/add to arr
        
    }


    // cat files

    for (int i = 0; i < entries_fdArr; ++i){

    }

    free(fdArr);

    return 0;
}

// meow cuz cat
int meow(int inputFD){

    char     buf[COUNT] = {0};
    ssize_t  readin;
    ssize_t  written;

    while ((readin = read(inputFD, buf, COUNT))){

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
    return 0;

}


