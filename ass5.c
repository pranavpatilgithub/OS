#include <stdio.h>

int main(){
	int n=5;
	int m=3;
	int max[n][m] , allocation[n][m];
	int need[n][m];
	int avl[m];
	int index = 0;
	int vis[5] = {-1,-1,-1,-1,-1};
	int safeseq[5] = {-1,-1,-1,-1,-1};
	
	printf("enter allocation matrix = \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("place[%d][%d] = ",i+1,j+1);
			scanf("%d",&allocation[i][j]);
		}
	}
	
	printf("enter max matrix = \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("place[%d][%d] = ",i+1,j+1);
			scanf("%d",&max[i][j]);
		}
	}
	
	printf("enter available = \n");
	for(int i=0;i<m;i++){
		scanf("%d",&avl[i]);
	}
	//calculate need matrix
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}
	//print matrix data
	printf("ALLOCATION = = = = \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d ",allocation[i][j]);
		}
		printf("\n");
	}
	
	printf("MAX = = = = \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d ",max[i][j]);
		}
		printf("\n");
	}
	
	printf("NEED = = = = \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d ",need[i][j]);
		}
		printf("\n");
	}
	
	printf("AVAILABLE = = = = \n");
	for(int i=0;i<m;i++){
		printf("%d ",avl[i]);
	}
	
	// main logic
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
	        if(vis[j] == -1 && (need[j][0]<=avl[0]) && (need[j][1]<=avl[1]) && (need[j][2] <= avl[2]) ){
	            vis[j] = j;
                safeseq[index++] = j;
                for(int k=0;k<m;k++){
                    avl[k] += allocation[j][k];
                }
                break;
	        }
	    }
	}
    printf("\n");
    int p = 0;
    for(p=0;p<5;p++){
        if(safeseq[p] == -1){
            printf("invalid sequence \n");
        }
    }
    if(p==5){
       for(int i=0;i<n;i++){
		printf("%d  ",safeseq[i]);
	 } 
    }

    return 0;
}


