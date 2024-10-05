#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>& arr, int n, int m, int mid) {
    int studentCount = 1; // Start with one student
    int pageSum = 0;

    for (int i = 0; i < n; i++) {
        if (pageSum + arr[i] > mid) {
            studentCount++;
            pageSum = arr[i];
            if (studentCount > m) {
                return false;
            }
        } else {
            pageSum += arr[i];
        }
    }
    return true;
}

int findPages(vector<int>& arr, int n, int m) {
    if (n < m) {
        return -1; // Not possible to assign each student a book
    }

    int start = 0;
    int end = 0;

    // Calculate sum of all pages and maximum element
    for (int i = 0; i < n; i++) {
        end += arr[i];
        start = max(start, arr[i]); // Start from the maximum book size
    }

    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1; // Try to minimize the maximum pages allocated
        } else {
            start = mid + 1; // If not possible, increase the maximum pages allowed
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {10,20,30,40};
    int n = arr.size();
    int m = 2; // Number of students

    int result = findPages(arr, n, m);

    cout << "Minimum number of pages each student gets: " << result << endl;

    return 0;
}
