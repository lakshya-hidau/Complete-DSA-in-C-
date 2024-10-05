#include <bits/stdc++.h>
using namespace std;

// Function to determine if person 'a' knows person 'b'
bool knows(const vector<vector<int>>& M, int a, int b) {
    return M[a][b] == 1;
}

// Solution class for finding the celebrity
class Solution {
public:
    // Function to find if there is a celebrity in the party or not
    int celebrity(vector<vector<int>>& M, int n) {
        stack<int> s;

        // Step 1: Push all elements into the stack
        for (int i = 0; i < n; ++i) {
            s.push(i);
        }

        // Step 2: Determine the potential celebrity
        while (s.size() > 1) {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            if (knows(M, a, b)) {
                s.push(b); // b could be the celebrity
            } else {
                s.push(a); // a could be the celebrity
            }
        }

        int candidate = s.top(); // Potential celebrity

        // Step 3: Verify the candidate
        int zeroCount = 0;
        for (int i = 0; i < n; ++i) {
            if (M[candidate][i] == 0) {
                ++zeroCount;
            }
        }

        // Check if all values in the row of candidate are 0
        if (zeroCount != n) {
            return -1; // Not a celebrity
        }

        int oneCount = 0;
        for (int i = 0; i < n; ++i) {
            if (M[i][candidate] == 1) {
                ++oneCount;
            }
        }

        // Check if all values in the column of candidate are 1, except the diagonal
        if (oneCount != n - 1) {
            return -1; // Not a celebrity
        }

        return candidate;
    }
};

// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
    return 0;
}
