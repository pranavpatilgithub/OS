#include <stdio.h>
#include <limits.h>
void fcfs(int string[], int n, int frame) {
    int s;
    int fault = 0;
    int temp[frame];

    for (int i = 0; i < frame; i++) {
        temp[i] = -1;
    }

    printf("\nstring \tstatus \t frame-1 \t frame-2 \t frame-3 \n");
    for (int i = 0; i < n; i++) {
        s = 0;
        for (int j = 0; j < frame; j++) {
            if (string[i] == temp[j]) {
                fault--;
                s++;
            }
        }
        fault++;

       

        printf("%d \t", string[i]);
         if (s == 0) {
             printf("miss \t");
            if (fault <= frame) {
                temp[fault - 1] = string[i];
            } else {
                temp[fault % frame] = string[i];
            }
        }
        else{
            printf("hit \t");
        }
        for (int j = 0; j < frame; j++) {
            if (temp[j] != -1) {
                printf("%d \t", temp[j]);
            } else {
                printf("-- \t");
            }
        }
        printf("\n");
    }
    printf("fault = %d\n", fault);
}

int checkhit(int string, int temp[], int occupied){
    for(int i=0;i<occupied;i++){
        if(string == temp[i]){
            return 1;
        }
    }
    return 0;
}

void printresult(int temp[], int occupied){
    for(int i=0;i<occupied;i++){
        printf("%d \t\t",temp[i]);
    }
}

void lru(int string[], int n, int frame){
    int distance[n];
    int fault = 0, occupied = 0;
    int temp[frame];
    for(int i=0;i<frame;i++){
        temp[i]=-1;
    }
    printf("string \t status \t frame1 \t frame2 \tframe3\n");
    for(int i=0;i<n;i++){
        printf("%d \t",string[i]);
        
        if(checkhit(string[i],temp,occupied)){
            printf("hit \t");
            printresult(temp,occupied);
        }
        else{
            printf("miss \t");

            if(occupied < frame){
                temp[occupied] = string[i];
                occupied++;
                fault++;
            }

            else{
                int max = INT_MIN;
                int index;
                for(int j=0 ; j<frame ; j++){
                    distance[j] = 0;
                    for(int k=i-1;k>=0;k--){
                        ++distance[j];
                        if(temp[j] == string[k]){
                            break;
                        }
                    }
                    if(distance[j] > max){
                        max=distance[j];
                        index=j;
                    }
                }
                fault++;
                temp[index]=string[i];
            }
            printresult(temp,occupied);
            
        }

        printf("\n");
    }
printf("\nfault = %d",fault);   
}

int main() {
    int n;
    printf("enter number of pages = ");
    scanf("%d", &n);

    int string[n];
    printf("enter incoming stream = \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &string[i]);
    }

    int frame;
    printf("enter no of frames = ");
    scanf("%d", &frame);

    fcfs(string, n, frame);
    lru(string, n, frame);
    return 0;
}
