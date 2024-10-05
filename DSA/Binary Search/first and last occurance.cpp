#include<iostream>
using namespace std;

int firstOcc(int arr[], int size, int key) {
    int start = 0, end = size - 1;
    int mid = start + (end - start)/2;
    int ans = -1;

    while (start <= end)
    {
        if(arr[mid] == key) {
            ans = mid;
            end = mid - 1;
        }
        else if(key > arr[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        mid = start + (end - start)/2; 
    }
    return ans;
}

int lastOcc(int arr[], int size, int key) {
    int start = 0, end = size - 1;
    int mid = start + (end - start)/2;
    int ans = -1;

    while (start <= end)
    {
        if(arr[mid] == key) {
            ans = mid;
            start = mid + 1;
        }
        else if(key > arr[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        mid = start + (end - start)/2; 
    }
    return ans;
}

int main()
{
    int arr[5] = {1,2,3,3,5};

    cout <<"First Index of 3 is at Index " << firstOcc(arr, 5, 3) << endl;
    cout <<"Last Index of 3 is at Index " << lastOcc(arr, 5, 3) << endl;
}