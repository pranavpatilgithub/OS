#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int pipe1[2],pipe2[2];
	int status1,status2;
	int maxlen = 20;
	int i;
	char readmessage[maxlen];
	char pipe1writemessage[maxlen] , pipe2writemessage[maxlen];
	pid_t child = 0;
	
	int n;
	printf("enter number of message = ");
	scanf("%d",&n);
	getchar();
	
	status1 = pipe(pipe1);
	status2 = pipe(pipe2);
	if(status1 == -1 || status2 == -1){
		printf("error in creating pipe");
	}
	
	
	child = fork();
	if(child != 0){
		close(pipe1[0]);
		close(pipe2[1]);
		for(i=0;i<n;i++){
			printf("In parent :: enter the message %d = ",i+1);
			fgets(pipe1writemessage,maxlen,stdin);
			
			write(pipe1[1], pipe1writemessage , strlen(pipe1writemessage)+1);
			printf("In parent :: writing message = %s",pipe1writemessage);
			
			read(pipe2[0],readmessage,sizeof(readmessage));
			printf("In parent :: reading child's message = %s \n",readmessage);
		}
	}
	else{
		close(pipe1[1]);
		close(pipe2[0]);
		for(i=0;i<n;i++){
			read(pipe1[0],readmessage,sizeof(readmessage));
			printf("In child :: reading message from parent = %s\n",readmessage);
			
			printf("In child :: enter message = ");
			fgets(pipe2writemessage,maxlen,stdin);
			
			printf("In child :: writing message = %s",pipe2writemessage);
			write(pipe2[1],pipe2writemessage,strlen(pipe2writemessage)+1);
			
		}
		
	}
	
	
	
	return 0;
}

// /tmp/IBcrRIr4G1.o
// enter number of message = 2
// In parent :: enter the message 1 = hi
// In parent :: writing message = hi
// In child :: reading message from parent = hi

// In child :: enter message = hello
// In child :: writing message = hello
// In parent :: reading child's message = hello
 
// In parent :: enter the message 2 = bye
// In parent :: writing message = bye
// In child :: reading message from parent = bye

// In child :: enter message = bye
// In child :: writing message = bye
// In parent :: reading child's message = bye
 


// === Code Execution Successful ===
