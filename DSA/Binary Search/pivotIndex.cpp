#include<iostream>
using namespace std;

int pivotIndex(int arr[], int size) {
    int left = 0;
    int right;

    for(int i = 0; i < size; i++){
        right = 0;
        for(int j = i+1; j<size; j++) {
            right += arr[j];
        }
        if(left == right){
            return i;
        }
        left += arr[i];
    }
    return -1;
}

int main()
{
    int arr1[6] = {1,7,3,6,5,6};
    int arr2[3] = {1,2,3};
    int arr3[3] = {2,1,-1};

    cout << "The Pivot index of arr1 is " << pivotIndex(arr1, 6) << endl;
    cout << "The Pivot index of arr2 is " << pivotIndex(arr2, 3) << endl;
    cout << "The Pivot index of arr3 is " << pivotIndex(arr3, 3) << endl;
}

