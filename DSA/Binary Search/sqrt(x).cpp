#include<iostream>
using namespace std;

long long int sqrt(int x){
    int start = 0;
    int end = x;
    long long int mid = start + (end - start)/2;

    long long int ans = -1;

    while (start <= end)
    {
        long long int square = mid * mid;
        if(square == x) {
            return mid;
        }

        if(square < x) {
            ans = mid;
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
    int n;
    cout << "Enter any number you want to find the square root : " ;
    cin >> n;
    cout << endl;

    cout << "The square root of this number is " << sqrt(n) << endl;
}