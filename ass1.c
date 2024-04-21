#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void copyfile(){
	pid_t pid = fork();
	if(pid < 0){
		printf("fork failed");
	}
	else if(pid == 0){
		char *args[] = {"cp" , "source.txt" , "dest.txt" , NULL};
		execvp("cp",args);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else{
	    wait(NULL);
	    printf("file copied");
	}
	
}
void searchpattern(){
	pid_t pid = fork();
	char pattern[256];
	printf("enter pattern to search = ");
	scanf("%255s",pattern);
	
	if(pid < 0){
		printf("fork failed");
	}
	else if(pid == 0){
		char *args[] = {"grep" , pattern , "source.txt" , NULL};
		execvp("grep",args);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else{
	    wait(NULL);
	    printf("pattern searched");
	}
	
}

int main(){
    int ch;
    
    printf("1. copy command\n");
    printf("2. search pattern\n");
    printf("3. Get pid\n");
    printf("4. exit\n");
    
    printf("enter your choice = ");
    scanf("%d",&ch);
    
    
    
    switch(ch){
    	case 1:
    		copyfile();
    		break;
    	case 2:
			searchpattern();
			break;
		case 3:
			printf("The child id = %d",getpid());
			break;
		case 4:
			printf("= = exiting = =");
			break;
		default:
			printf("enter valid number\n");		
	}
	return 0;
	
}
