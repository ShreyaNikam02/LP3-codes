#include <iostream>
#include <vector>
using namespace std;

int recSteps = 0;

// 1. Iterative Method
void fibIterative(int n) {
    int a = 0, b = 1, c, steps = 2;
    cout << "Series: ";
    if (n >= 1) cout << a << " ";
    if (n >= 2) cout << b << " ";

    for (int i = 2; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
        steps += 3;
        cout << c << " ";
    }
    cout << "\nStep Count: " << steps << endl;
}

// 2. Recursive Method
int fibRecursive(int n) {
    recSteps++;
    if (n <= 1) return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// 3. Dynamic Programming Method
void fibDP(int n) {
    vector<int> dp(n + 1, 0);
    int steps = 2;
    dp[0] = 0;
    if (n > 0) dp[1] = 1;

    cout << "Series: " << dp[0] << " ";
    if (n >= 2) cout << dp[1] << " ";

    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        steps++;
        cout << dp[i] << " ";
    }
    cout << "\nStep Count: " << steps << endl;
}

int main() {
    int choice, n;
    while (true) {
        cout << "\n1. Iterative  2. Recursive  3. DP  4. Exit\nChoice: ";
        cin >> choice;
        if (choice == 4) break;

        cout << "Enter number of terms (n): ";
        cin >> n;

        if (choice == 1) fibIterative(n);
        else if (choice == 2) {
            recSteps = 0;
            cout << "Series: ";
            for (int i = 0; i < n; i++) cout << fibRecursive(i) << " ";
            cout << "\nStep Count: " << recSteps << endl;
        }
        else if (choice == 3) fibDP(n);
    }
    return 0;
}