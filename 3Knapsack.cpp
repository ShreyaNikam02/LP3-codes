#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> wt(n + 1), val(n + 1);
    for (int i = 1; i <= n; i++) {
        cout << "Enter Weight and Value of item " << i << ": ";
        cin >> wt[i] >> val[i];
    }

    cout << "Enter Knapsack Capacity (W): ";
    cin >> W;

    // Step 1 & 2: Build DP table T of size (n+1) x (W+1)[cite: 30, 31]
    vector<vector<int>> T(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (wt[i] <= j)
                T[i][j] = max(T[i - 1][j], val[i] + T[i - 1][j - wt[i]]);
            else
                T[i][j] = T[i - 1][j];
        }
    }

    cout << "\nMaximum Profit: " << T[n][W] << endl;

    // Step 3: Trace selected items from bottom to top[cite: 31]
    cout << "Selected Items: ";
    int remW = W;
    for (int i = n; i >= 1; i--) {
        if (T[i][remW] != T[i - 1][remW]) {
            cout << "Item " << i << " ";
            remW -= wt[i];
        }
    }
    cout << endl;

    return 0;
}