#include <stdio.h>

void firstFit(int processSize[], int n, int blockSize[], int m)
{

    int bs[m];
    for (int i = 0; i < m; i++)
    {
        bs[i] = blockSize[i];
    }

    int as[n], allocation[n];
    for (int i = 0; i < n; i++)
    {
        as[i] = -1;
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (bs[j] >= processSize[i])
            {
                allocation[i] = j;
                bs[j] -= processSize[i];
                as[i] = bs[j];
                break;
            }
        }
    }

    // print result
    printf("process no.  \tprocess size \tblock no.  \tavl space \n");
    for (int i = 0; i < n; i++)
    {
        printf("\t\t%d \t\t", i + 1);
        printf("%d \t\t", processSize[i]);
        if (allocation[i] != -1)
        {
            printf("%d \t\t", allocation[i] + 1);
        }
        else
        {
            printf("-- \t\t");
        }
        if (as[i] != -1)
        {
            printf("%d \t\t", as[i]);
        }
        else
        {
            printf("-- \t\t");
        }
        printf("\n");
    }
}

void bestFit(int processSize[], int n, int blockSize[], int m)
{
    int bs[m];
    for (int i = 0; i < m; i++)
    {
        bs[i] = blockSize[i];
    }

    int as[n], allocation[n];
    for (int i = 0; i < n; i++)
    {
        as[i] = -1;
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int bestIndex = -1;
        for (int j = 0; j < m; j++)
        {
            if (bs[j] >= processSize[i])
            {
                if (bestIndex == -1)
                {
                    bestIndex = j;
                }
                else if (bs[bestIndex] > bs[j])
                {
                    bestIndex = j;
                }
            }
        }
        if (bestIndex != -1)
        {
            allocation[i] = bestIndex;
            bs[bestIndex] -= processSize[i];
            as[i] = bs[bestIndex];
        }
    }

    // print
    printf("process no.  \tprocess size \tblock no.  \tavl space \n");
    for (int i = 0; i < n; i++)
    {
        printf("\t\t%d \t\t", i + 1);
        printf("%d \t\t", processSize[i]);
        if (allocation[i] != -1)
        {
            printf("%d \t\t", allocation[i] + 1);
        }
        else
        {
            printf("-- \t\t");
        }
        if (as[i] != -1)
        {
            printf("%d \t\t", as[i]);
        }
        else
        {
            printf("-- \t\t");
        }
        printf("\n");
    }
}
void worstFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n], as[n], db[m];
    for (int i = 0; i < m; i++)
    {
        db[i] = blockSize[i];
    }
    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
        as[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        int bestidx = -1;
        for (int j = 0; j < m; j++)
        {
            if (db[j] >= processSize[i])
            {
                if (bestidx == -1)
                {
                    bestidx = j;
                }
                else if (db[bestidx] < db[j])
                {
                    bestidx = j;
                }
            }
        }
        if (bestidx != -1)
        {
            allocation[i] = bestidx;
            db[bestidx] -= processSize[i];
            as[i] = db[bestidx];
        }
    }
    printf("Process no. \t Process Size \t Block no. \t Avl space\n");
    for (int i = 0; i < n; i++)
    {
        printf("\t\t%d\t\t", i + 1);
        printf("\t%d\t\t", processSize[i]);
        if (allocation[i] != -1)
        {
            printf("\t\t%d\t", allocation[i] + 1);
        }
        else
        {
            printf("\t\tno space");
        }
        if (as[i] != -1)
        {
            printf("\t\t%d", as[i]);
        }
        else
        {
            printf("\t--");
        }
        printf("\n");
    }
}
void nextFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n], as[n], db[m];
    for (int i = 0; i < m; i++)
    {
        db[i] = blockSize[i];
    }
    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
        as[i] = -1;
    }
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        while (count < m)
        {
            if (db[k] >= processSize[i])
            {
                allocation[i] = k;
                db[k] -= processSize[i];
                as[i] = db[i];
                break;
            }
            k = (k + 1) % m;
            count += 1;
        }
    }
    printf("Process no. \t Process Size \t Block no. \t Avl space\n");
    for (int i = 0; i < n; i++)
    {
        printf("\t\t%d\t\t", i + 1);
        printf("\t%d\t\t", processSize[i]);
        if (allocation[i] != -1)
        {
            printf("\t\t%d\t", allocation[i] + 1);
        }
        else
        {
            printf("\t\tno space");
        }
        if (as[i] != -1)
        {
            printf("\t\t%d", as[i]);
        }
        else
        {
            printf("\t--");
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("enter number of process = ");
    scanf("%d", &n);

    int m;
    printf("enter number of block size = ");
    scanf("%d", &m);

    int processSize[n], blockSize[m];

    printf("enter process size - - \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &processSize[i]);
    }

    printf("\nenter block size - - \n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &blockSize[i]);
    }
    printf("FIRST FIT -------------\n");
    firstFit(processSize, n, blockSize, m);
    printf("BEST FIT -------------\n");
    bestFit(processSize, n, blockSize, m);
    printf("WORST FIT -------------\n");
    worstFit(processSize, n, blockSize, m);
    printf("NEXT FIT -------------\n");
    nextFit(processSize, n, blockSize, m);
    return 0;
}



// /tmp/4485BI1gzg.o
// enter number of process = 4
// enter number of block size = 5
// enter process size - - 
// 90
// 50
// 30
// 10

// enter block size - - 
// 20
// 100
// 40
// 200
// 10
// FIRST FIT -------------
// process no.  	process size 	block no.  	avl space 
// 		1 		90 		2 		10 		
// 		2 		50 		4 		150 		
// 		3 		30 		3 		10 		
// 		4 		10 		1 		10 		
// BEST FIT -------------
// process no.  	process size 	block no.  	avl space 
// 		1 		90 		2 		10 		
// 		2 		50 		4 		150 		
// 		3 		30 		3 		10 		
// 		4 		10 		2 		0 		
// WORST FIT -------------
// Process no. 	 Process Size 	 Block no. 	 Avl space
// 		1			90				4			110
// 		2			50				4			60
// 		3			30				2			70
// 		4			10				2			60
// NEXT FIT -------------
// Process no. 	 Process Size 	 Block no. 	 Avl space
// 		1			90				2			20
// 		2			50				4			10
// 		3			30				4			40
// 		4			10				4			110
