#include <stdio.h>
#include <unistd.h>

int main(){
	int f = fork();
	if (f == 0) {
		execl("./hello",NULL);
	} else {
		printf("fork: %d\n", (int)getpid());
		execl("./hello",NULL);
	}

	return(0);
}
