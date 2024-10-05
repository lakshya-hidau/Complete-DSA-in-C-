#include<iostream>
using namespace std;

int peakIndexInMountainArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start)/2;

    while(start < end){
        if(arr[mid] < arr[mid+1]){
            start = mid + 1;
        }
        else{
            end = mid;
        }
        mid = start + (end - start)/2;
        }
    return arr[start];
}

int main()
{
    int arr[4] = {0,10,55,2};

    cout << "The peak element of mountain array is " << peakIndexInMountainArray(arr, 4) << endl;
}