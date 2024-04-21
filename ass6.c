#include <stdio.h>

void firstFit(int processSize[], int n, int blockSize[], int m){

	int bs[m];
	for(int i=0;i<m;i++){
		bs[i] = blockSize[i];
	}
	
	int as[n] , allocation[n];
	for(int i=0;i<n;i++){
		as[i] = -1;
		allocation[i] = -1;
	}

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(bs[j] >= processSize[i] ){
                allocation[i]=j;
                bs[j] -= processSize[i];
                as[i] = bs[j];
                break;
            }
        }
    }

    //print result
    printf("process no.  \tprocess size \tblock no.  \tavl space \n");
    for(int i=0 ; i<n ; i++){
        printf("\t\t%d \t\t",i+1);
        printf("%d \t\t",processSize[i]);
        if(allocation[i] !=-1){
            printf("%d \t\t",allocation[i]+1);
        }
        else{
            printf("-- \t\t");
        }
        if(as[i] !=-1){
            printf("%d \t\t",as[i]);
        }
        else{
            printf("-- \t\t");
        }
        printf("\n");
    }

    
	
	
}

void bestFit(int processSize[], int n, int blockSize[], int m){
    int bs[m];
	for(int i=0;i<m;i++){
		bs[i] = blockSize[i];
	}
	
	int as[n] , allocation[n];
	for(int i=0;i<n;i++){
		as[i] = -1;
		allocation[i] = -1;
	}

    
    for(int i=0 ; i<n ; i++){
        int bestIndex = -1;
        for(int j=0 ; j<m ; j++){
            if(bs[j] >= processSize[i] ){
                if(bestIndex == -1){
                    bestIndex = j;
                }
                else if(bs[bestIndex] > bs[j]){
                    bestIndex = j;
                }
            }
        }
       if(bestIndex!=-1){
        allocation[i] = bestIndex;
        bs[bestIndex] -= processSize[i];
        as[i] = bs[bestIndex];
       }
    }

    //print
    printf("process no.  \tprocess size \tblock no.  \tavl space \n");
    for(int i=0 ; i<n ; i++){
        printf("\t\t%d \t\t",i+1);
        printf("%d \t\t",processSize[i]);
        if(allocation[i] !=-1){
            printf("%d \t\t",allocation[i]+1);
        }
        else{
            printf("-- \t\t");
        }
        if(as[i] !=-1){
            printf("%d \t\t",as[i]);
        }
        else{
            printf("-- \t\t");
        }
        printf("\n");
    }
    
}

int main(){
	int n;
	printf("enter number of process = ");
	scanf("%d",&n);

    int m;
	printf("enter number of block size = ");
	scanf("%d",&m);
	
	int processSize[n],blockSize[m];
	
	printf("enter process size - - \n");
	for(int i=0;i<n;i++){
		scanf("%d",&processSize[i]);
	}
	
	printf("\nenter block size - - \n");
	for(int i=0;i<m;i++){
		scanf("%d",&blockSize[i]);
	}
	printf("FIRST FIT -------------\n");
	firstFit(processSize,n,blockSize,m);
	printf("BEST FIT -------------\n");
	bestFit(processSize,n,blockSize,m);
	return 0;
	
}
