#include <stdio.h>
#include <string.h>

// Hard coding input should be fine, echo is a very simple command.
int main(int argc, char *argv[]){

    // If the command is simple echo, no -n or anything else
    if (argc == 1){
        puts("\n");
        return 0;
    }

    // If the command is echo -n. -n means to not print the trailing -n, so no
    // printing or puts is needed
    if (argc == 2 && strcmp(argv[1],"-n")){
        return 0;
    }

    // Otherwise, the command 

    if (strcmp(argv[1], "-n")){

    }
    else {

    }

}
