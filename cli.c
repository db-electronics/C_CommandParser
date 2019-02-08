

#include <stdio.h>
#include <string.h>
#include "cli.h"

// declare list of commands
sCmd cli_command_list[MAXCOMMANDS];
int cli_num_commands = 0;

//*******************************************************
int cli_register_cmd(char* token, void (*function)()){

    // bounds check
    if( cli_num_commands >= MAXCOMMANDS-1 ){
        return -1;
    }else{
        // register the cmd
        strncpy(cli_command_list[cli_num_commands].token, token, CMDLENGTH);
        cli_command_list[cli_num_commands].function = function;
        cli_num_commands++;
    }

    return cli_num_commands;
}

//*******************************************************
int cli_parse_input(char* input){

    int i = 0;
    char *token,*pos;

    // check if the cmd is fully received, need a local copy for strtok
    pos = strchr(input, '\n');
    if( pos != NULL ){

        char* duplicate = strdup(input);  /* make copy; we can't manipulate string literal */

        token = strtok(duplicate, " ");
        // search for this token in commandlist
        for(i=0; i<cli_num_commands; i++){

            if( strcmp(cli_command_list[i].token, token) == 0 ){
                printf("decoded cmd %d\n", i);
                (*cli_command_list[i].function)();
                return i;
            }

        }

        return 0;

    }else{
        return -1;
    }

}

//*******************************************************
char * cli_next_arg(void){
    return strtok(NULL, " ");
}
