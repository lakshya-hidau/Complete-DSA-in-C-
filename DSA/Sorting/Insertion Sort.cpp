#include <iostream>
using namespace std;

void insertionSort(int n, int arr[]){
    for(int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;

        for(j; j >= 0; j--) {

            if(arr[j] > temp) {
                arr[j+1] = arr[j];
            }
            else {
                break;
            }
        }
        arr[j+1] = temp;
    }
}

int main()
{
    int arr[9] =  {29,72,98,13,87,66,52,51,36};
    int size = 9;

    insertionSort(size,arr);
    
    cout << "Sorted array is : ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}