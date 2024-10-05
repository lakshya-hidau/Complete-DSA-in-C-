#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{   
    for(int i = 1; i < n; i++) {

        for(int j = 0; j < n-i; j++) {

            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main()
{
    int arr[9] =  {29,72,98,13,87,66,52,51,36};
    int size = 9;

    bubbleSort(arr,size);
    
    cout << "Sorted array is : ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}