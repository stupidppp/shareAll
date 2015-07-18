#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>

#include<signal.h>
#include<sys/wait.h>
#include<sys/types.h>

void handle_child_death(int sign)
{
		pid_t pid;
		int status;

	/*	if ( (pid = waitpid(-1,&status,WNOHANG|WUNTRACED)) > 0 ){
				printf("CHILD [%d] IS KILLED\n",pid);

				if (WIFEXITED(status)) {
						printf("exited, status=%d\n", WEXITSTATUS(status));
				} else if (WIFSIGNALED(status)) {
						printf("killed by signal %d\n", WTERMSIG(status));
				} else if (WIFSTOPPED(status)) {
						printf("stopped by signal %d\n", WSTOPSIG(status));
				}
		}else if (pid < 0 ){
				perror("waitpid");
		}
	*/
		while ((pid= waitpid(-1,&status,WNOHANG|WUNTRACED))>0) {
		
			if (WIFEXITED(status)) {
				printf("exited, status=%d\n", WEXITSTATUS(status));
			} else if (WIFSIGNALED(status)) {
				printf("killed by signal %d\n", WTERMSIG(status));
			} 
		}
}

#define PROCESSNUM     10

int main (int argc ,char ** argv)
{
		signal(SIGCHLD,handle_child_death);
#if 1 
		pid_t pid;
		int i;
		//printf("THE PARENT IS PID [%d]\n",getpid());
		for(i=0;i<PROCESSNUM;i++){
				pid = fork();
				if (pid == 0){
					printf("THIS IS %d CHILD PROCESS AND PID is %d,PPID is %d\n",i,getpid(),getppid());
					exit(1);
				}else if (pid < 0){
					printf("ERROR:%d\n",errno);
				}else{
					printf("THE PARENT IS %d  PID [%d]\n" ,i ,getpid());
				}
		}
#endif 

}

