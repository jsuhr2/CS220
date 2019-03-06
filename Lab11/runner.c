#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(){
	printf("My pid is %d, parent pid is %d.\n", getpid(), getppid());
	return 0;
}
