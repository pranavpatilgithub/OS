#include <stdio.h>

void fcfs(int process[], int burstTime[], int n){
	int i;
	//dublicate
	int p[n],bt[n];
	for(i=0;i<n;i++){
		p[i] = process[i];
		bt[i] = burstTime[i];
	}
	
	//calculate waiting time
	int wt[n];
	wt[0] = 0;
	float total_wt =0;
	for(i=1;i<n;i++){
		wt[i] = wt[i-1] + bt[i-1];
		total_wt += wt[i];
	}
	
	//calculate turn around time
	int tat[n];
	float total_tat = 0;
	for(i = 0;i<n;i++){
		tat[i] = wt[i] + bt[i];
		total_tat += tat[i];
	}
	
	//print result
	printf("process\t burst time\twaiting time\t turn around time\n");
	for(i=0;i<n;i++){
		printf("%d \t\t%d \t\t%d \t\t%d\n",p[i],bt[i],wt[i],tat[i]);
	}
	
	printf("\nAverage waiting time = %f",total_wt/n);
	printf("\nAverage turn around time = %f\n\n",total_tat/n);	
}

void sjf(int process[], int burstTime[], int n){
	//dublicate
	int p[n],bt[n];
	int i,j;
	for(i=0;i<n;i++){
		p[i] = process[i];
		bt[i] = burstTime[i];
	}
	//sort burst times
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(bt[j] > bt[j+1]){
				//swap
				int temp = bt[j];
				bt[j] = bt[j+1];
				bt[j+1] = temp;
				
				//swap
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
	
	//calculate waiting time
	int wt[n];
	wt[0] = 0;
	float total_wt =0;
	for(i=1;i<n;i++){
		wt[i] = wt[i-1] + bt[i-1];
		total_wt += wt[i];
	}
	
	//calculate turn around time
	int tat[n];
	float total_tat = 0;
	for(i = 0;i<n;i++){
		tat[i] = wt[i] + bt[i];
		total_tat += tat[i];
	}
	
	//print result
	printf("process\t burst time\twaiting time\t turn around time\n");
	for(i=0;i<n;i++){
		printf("%d \t\t%d \t\t%d \t\t%d\n",p[i],bt[i],wt[i],tat[i]);
	}
	
	printf("\nAverage waiting time = %f",total_wt/n);
	printf("\nAverage turn around time = %f",total_tat/n);
}

int main(){
	int n,i;
	printf("enter number of processes = ");
	scanf("%d",&n);
	
	int process[n],burstTime[n];
	printf("enter burst time for each process = \n");
	
	for(i=0;i<n;i++){
		process[i]=i+1;
		printf("p%d = ",i+1);
		scanf("%d",&burstTime[i]);
	}
	
	fcfs(process, burstTime, n);
	sjf(process, burstTime, n);
	
	
	
	return 0;
}
