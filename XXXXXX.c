#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>

#define PROCESSNUM     10

int main (int argc ,char ** argv)
{
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

