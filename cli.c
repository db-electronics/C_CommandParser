/*******************************************************************//**
 *  \file   cli.c
 *  \author René Richard
 *  \brief  This program tokenizes commands and associates them to
 *          function calls 
 *
 *  \copyright This file is part of Command Parser.
 *
 *   Command Parser is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Command Parser is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Command Parser.  If not, see <http://www.gnu.org/licenses/>.
 */

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
