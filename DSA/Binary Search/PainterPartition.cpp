#include <iostream>
#include <algorithm>
using namespace std;


bool isPossible(int boards[],int n, int k, int mid){
    int painterCount=1;
    int boardLength=0;

    for(int i=0; i<n; i++){
       if(boardLength+boards[i]<=mid){
            boardLength+=boards[i];
        }
        else{
            painterCount++;
            if(painterCount>k || boards[i]>mid){
                return false;
            }
            boardLength= boards[i];
        }
    }
    return true;
}

 

int findLargestMinDistance(int boards[], int n, int k)
{
    int s=0;
    int sum=0;
    for(int i = 0; i < n; i++){
        sum += boards[i];
    }
    int e=sum;
    int ans=-1;

    while(s<=e){

        int mid= s+(e-s)/2;

        if(isPossible(boards, n, k, mid)){
            ans= mid;
            e= mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}

int main()
{
    int boards[6] = {2,1,5,6,2,3};
    int n = 6;
    int k = 2;

    int result = findLargestMinDistance(boards,n,k);

    cout << "The minimum time to get this job done is " << result << endl;
}