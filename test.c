

// A C/C++ program for splitting a string
// using strtok()
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cli.h"

extern sCmd cli_command_list[MAXCOMMANDS];

void prgbblk(){
    printf("prgbblk\n");
}

void prgwblk(){
    printf("prgwblk\n");
}

void prgbyte(){

    // get next argument, call with NULL resumes where cli_parse left off
    char *token = cli_next_arg();
    int num = 0;
    int argnum = 0;

    printf("reached command 'prgbyte'\n");
    while (token != NULL) {

        argnum = strtoul(token, (char**)0, 0);
		printf("arg %d: %s\n", num++, token);
		token = cli_next_arg();
	}
}

void prgword(){

    // get next argument, call with NULL resumes where cli_parse left off
    char *token = cli_next_arg();
    int num = 0;
    int argnum = 0;

    printf("reached command 'prgword'\n");
    while (token != NULL) {

        argnum = strtoul(token, (char**)0, 0);
		printf("arg %d: %s\n", num++, token);
		token = cli_next_arg();
	}
}

int main(void){

    #define NUMOFTESTCMDS   3
    char *cmds[NUMOFTESTCMDS];
    cmds[0] = "test some text";
    cmds[1] = "prgword 0x5555 0xAA 55 1234\n\r";
    cmds[2] = "prgbyte 54 test.bin\n\r";
    int i;

    if( cli_register_cmd("prgbblk", &prgbblk ) == -1 ){ printf("error"); }
    if( cli_register_cmd("prgwblk", &prgwblk ) == -1 ){ printf("error"); }
    if( cli_register_cmd("prgbyte", &prgbyte ) == -1 ){ printf("error"); }
    if( cli_register_cmd("prgword", &prgword ) == -1 ){ printf("error"); }

    //(*cli_command_list[0].function)();
    //(*cli_command_list[1].function)();
    //(*cli_command_list[0].function)();


    // listen for commands
    int var;

    //var = cli_parse_input(cmd0);
    //var = cli_parse_input(cmd1);

    for(i=0; i<NUMOFTESTCMDS; i++){
        var = cli_parse_input(cmds[i]);
    }

	return 0;
}
