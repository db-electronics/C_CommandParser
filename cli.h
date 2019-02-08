#ifndef CLI_H_INCLUDED
#define CLI_H_INCLUDED

#define CMDLENGTH           16
#define MAXCOMMANDS         64

typedef struct _sCmd {
    	char token[CMDLENGTH];
    	void (*function)();
} sCmd;


int cli_register_cmd(char* cmd, void (*function)());
int cli_parse_input(char* input);
char * cli_next_arg(void);


#endif // CLI_H_INCLUDED
