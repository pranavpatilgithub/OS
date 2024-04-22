#include <stdio.h>
#include <stdlib.h>

void fcfs(int string[], int size, int head){
    int seekCount = 0;

    for(int i=0;i<size;i++){
        seekCount += abs(head-string[i]);
        head = string[i];
    }

    printf("seek count = %d\n",seekCount);
    printf("sequence - - - ");
    for(int i=0;i<size;i++){
        printf("%d  ",string[i]);
    }
    printf("\n");
}

void sstf(int string[], int size, int head){
    int seekCount = 0;
    
    int seekSequence[size + 1];
    seekSequence[0] = head;

    int accessed[size];
    for(int i=0;i<size;i++){
        accessed[i]=0;
    }

    for(int i=0 ; i<size ; i++){
        int diff[size];
        for(int j=0 ; j<size ; j++){
            diff[j] = abs(head - string[j]);
        }  
        int minIndex = -1;
        int minimum = 1000;
        for(int j=0 ; j<size ; j++){
            if(!accessed[j] && minimum > diff[j]){
                minimum = diff[j];
                minIndex = j;
            }
        }
        accessed[minIndex] = 1;
        seekCount += diff[minIndex];
        head = string[minIndex];
        seekSequence[i+1] =  head;
    }
    printf("seek count = %d\n",seekCount);
    printf("sequence - - - ");
    for(int i=0;i<size;i++){
        printf("%d  ",seekSequence[i]);
    }
    
}

int main(){
    int n,head;
    printf("enter number of elements in sequence = ");
    scanf("%d",&n);
    
    int string[n];
    printf("\nenter sequence =  \n");
    for(int i=0; i<n; i++){
        scanf("%d",&string[i]);
    }

    printf("\nenter head = ");
    scanf("%d",&head);

    printf("FCFS - --------\n");
    fcfs(string,n,head);
    printf("SSTF - --------\n");
    sstf(string,n,head);

    return 0;
}
