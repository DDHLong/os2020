#include <stdio.h>
#include <unistd.h>

void main(){
	int pid_1 = fork();
	int pid_2 = fork();

	if (pid_1==0 && pid_2==0) return;
	else if (pid_1==0){
		printf("I'm launching ps -ef\n");
		execl("/bin/ps","ps","-ef",NULL);
	}
	else if (pid_2==0){
		printf("launching free -h\n");
		execl("/usr/bin/free","free","-h",NULL);
	} 
	else printf("I am parent, child is %d and %d\n",pid_1,pid_2);

	return;
}