#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size - 1;

    int mid = start + (end - start)/2;

    while (start <= end)
    {
        if(arr[mid] == key) {
            return mid;
        }
        if(key > arr[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }

        mid = start + (end - start)/2;
    }
    return -1;
}

int main()
{
    int even[8] = {2,4,6,8,10,12,14,16};
    int odd[7] = {1,3,5,7,9,11,13};

    int evenIndex = binarySearch(even, 8, 14);
    cout << "Index of 14 is " << evenIndex << endl;

    int oddIndex = binarySearch(odd, 7, 3);
    cout << "Index of 3 is " << oddIndex << endl;

    return 0;
}