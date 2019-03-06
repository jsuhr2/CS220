#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

extern uint32_t* get_ebp(void);

void ret2libc(int dummy){
	
	uint32_t *curr_ebp;
	curr_ebp = get_ebp();

	curr_ebp[2] = curr_ebp[1];

	curr_ebp[2] = dummy;

	curr_ebp[1] = (uint32_t) &system;

	char *str = "/bin/bash";
	curr_ebp[3] = (uint32_t) str;
}

void ret2libc_generic(char *cmd){

	uint32_t *curr_ebp;
	curr_ebp = get_ebp();
	
	curr_ebp[3] = curr_ebp[2];
	
	curr_ebp[2] = curr_ebp[1];

	//curr_ebp[2] = (uint32_t) cmd;

	curr_ebp[1] = (uint32_t) &system;
}

int main(){
	char *str = "/bin/bash";
	ret2libc_generic(str);
	printf("Done!\n");
	return 0;
}
