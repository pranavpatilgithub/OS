#include <bits/stdc++.h>
using namespace std;

void FCFS(int n, int sequence[], int HP)
{
    int temp, totalTrackPositions=0, head=HP, RS[n];
    for(int i=0; i<n; i++)
    {
        RS[i]=sequence[i];
    }
    for(int i=0; i<n; i++)
    {
        temp=abs(RS[i]-head);
        totalTrackPositions+=temp;
        head=RS[i];
    }
    cout<<"\nTotal no. of Track Positions: "<<totalTrackPositions<<endl;
}

void SSTF(int n, int sequence[], int HP)
{
    int count=0, totalTrackPositions=0, temp, head=HP, RS[n];
    for(int i=0; i<n; i++)
    {
        RS[i]=sequence[i];
    }
    while(count!=n)
    {
        int min=10000, index;
        
        for(int i=0; i<n; i++)
        {
            temp=abs(RS[i]-head);
            if(temp<min)
            {
                min=temp;
                index=i;
            }
        }
        totalTrackPositions+=min;
        head=RS[index];
        RS[index]=10000;
        count++;
    }
    cout<<"\nTotal no. of Track Positions: "<<totalTrackPositions<<endl;
}

void SCAN(int n, int sequence[], int HP)
{
    int DS, head=HP, RS[n];
    cout<<"Enter the disk size: ";
    cin>>DS;
    
    for(int i=0; i<n; i++)
    {
        RS[i]=sequence[i];
    }
    
    string direction;
    cout<<"Enter the direction (left/right): ";
    cin>>direction;
    
    int totalTrackPositions=0;
    vector<int>left, right;
    
    if(direction=="left")
    {
        left.push_back(0);
    }
    else
    {
        right.push_back(DS-1);
    }
    
    for(int i=0; i<n; i++)
    {
        if(RS[i]<head)
        {
            left.push_back(RS[i]);
        }
        else if(RS[i]>head)
        {
            right.push_back(RS[i]);
        }
    }
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());
    
    int count=2, temp;
    while(count--)
    {
        if(direction=="left")
        {
            for(int i=left.size()-1; i>=0; i--)
            {
                temp=abs(left[i]-head);
                totalTrackPositions+=temp;
                head=left[i];
            }
            direction="right";
        }
        
        else if(direction=="right")
        {
            for(int i=0; i<right.size(); i++)
            {
                temp=abs(right[i]-head);
                totalTrackPositions+=temp;
                head=right[i];
            }
            direction="left";
        }
    }
    cout<<"\nTotal no. of Track Positions: "<<totalTrackPositions<<endl;
}

void CSCAN(int n, int sequence[], int HP)
{
    int DS, head=HP, RS[n];
    cout<<"Enter the disk size: ";
    cin>>DS;
    
    for(int i=0; i<n; i++)
    {
        RS[i]=sequence[i];
    }
    
    int totalTrackPositions=0;
    vector<int>left, right;
    
    left.push_back(0);
    right.push_back(DS-1);
    
    for(int i=0; i<n; i++)
    {
        if(RS[i]<head)
        {
            left.push_back(RS[i]);
        }
        else if(RS[i]>head)
        {
            right.push_back(RS[i]);
        }
    }
    
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());
    int temp;
    
    for(int i=0; i<right.size(); i++)
    {
        temp=abs(right[i]-head);
        head=right[i];
        totalTrackPositions+=temp;
    }
    
    head=0;
    totalTrackPositions+=(DS-1);
    
    for(int i=0; i<left.size(); i++)
    {
        temp=abs(left[i]-head);
        totalTrackPositions+=temp;
        head=left[i];
    }
    cout<<"\nThe total no of track positions: "<<totalTrackPositions<<endl;
}

int main()
{
    int n, HP, choice;
    
    cout<<"Enter the no of requests: ";
    cin>>n;
    
    int RS[n];
    cout<<"Enter the requests sequence: ";
    for(int i=0; i<n; i++)
    {
        cin>>RS[i];
    }
    
    cout<<"Enter initial head position: ";
    cin>>HP;

    while(1)
    {
        cout<<"Enter the choice (1:FCFS 2:SSTF 3:SCAN 4:CSCAN 5:EXIT): ";
        cin>>choice;
        
        if(choice==1)
        {
            FCFS(n,RS,HP);
        } 
        else if(choice==2)
        {
            SSTF(n,RS,HP);
        }
        else if(choice==3)
        {
            SCAN(n,RS,HP);
        }
        else if(choice==4)
        {
            CSCAN(n,RS,HP);
        } 
        else
        {
            exit(0);
        }
    }
    return 0;
}
/*
Output:
Enter the no of requests: 7
Enter the requests sequence: 82 170 43 140 24 16 190
Enter initial head position: 50

Enter the choice (1:FCFS 2:SSTF 3:SCAN 4:CSCAN 5:EXIT): 1
Total no. of Track Positions: 642

Enter the choice (1:FCFS 2:SSTF 3:SCAN 4:CSCAN 5:EXIT): 2
Total no. of Track Positions: 208

Enter the choice (1:FCFS 2:SSTF 3:SCAN 4:CSCAN 5:EXIT): 3
Enter the disk size: 200
Enter the direction (left/right): right
Total no. of Track Positions: 332

Enter the choice (1:FCFS 2:SSTF 3:SCAN 4:CSCAN 5:EXIT): 4
Enter the disk size: 200
The total no of track positions: 391

Enter the choice (1:FCFS 2:SSTF 3:SCAN 4:CSCAN 5:EXIT): 5

=== Code Execution Successful ===*/
