#include <stdio.h>
#include <unistd.h>

int main(){
	int x = 1;
	pid_t pid;
	pid = fork();

	if(pid == 0){
		x++;
		printf("child x is %i\n", x);
		printf("Child's ID is %d\n", getpid());
		printf("Parent's PPID is %d\n", getppid());
		printf("In child\n");
	} else{
		x--;
		printf("parent x is %i\n", x);
		sleep(1);
		printf("Parent's ID is %d\n", getpid());
		printf("Parent's PPID is %d\n", getppid());
		printf("In parent\n");
	}
	return 0;
}
