#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std; 

bool ispossible(int rank[],int n, int m,int mid){
    int totalorder=0;

    for(int i=0;i<n;i++){
        int numoforder=1;
        int mins=rank[i]*numoforder;

        while(mins<=mid){
            totalorder++;
            numoforder++;
            mins+=rank[i]*numoforder;
        }
    }

    if(totalorder>=m) return true;
    else return false;
}

int minCookTime(int rank[],int n, int m)
{
    int sum=0;
    int maxi=rank[n-1];

    for(int i=1;i<=m;i++){
        sum+=i*maxi;
    }

    int s=0,e=sum;
    int mid=s+(e-s)/2;
    int ans=-1;

    while(s<=e){
        if(ispossible(rank, n, m, mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }

        mid=s+(e-s)/2;
    }

    return ans;

}

int main()
{
    int rank[4] = {1,2,3,4};
    int n = 4;
    int m = 11;

    cout << "Minimum time to cook dishes is " << minCookTime(rank,n,m) << endl;;
}