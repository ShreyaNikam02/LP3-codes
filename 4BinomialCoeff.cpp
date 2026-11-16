#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cout << "Enter n and k (0 <= k <= n): ";
    cin >> n >> k;

    vector<vector<int>> C(n + 1, vector<int>(k + 1, 0));

    // Bottom-up Pascal's Triangle calculation[cite: 33, 34]
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    cout << "\nBinomial Coefficient C(" << n << ", " << k << ") = " << C[n][k] << endl;
    return 0;
}