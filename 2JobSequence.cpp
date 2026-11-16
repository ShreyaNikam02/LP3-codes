#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    string id;   // Changed from char to string so "j1", "j2" work
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        cout << "Enter Job ID, Deadline, Profit: ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    sort(jobs.begin(), jobs.end(), compare);

    vector<string> slot(maxDeadline + 1, "-");
    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j >= 1; j--) {
            if (slot[j] == "-") {
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "\nOptimal Job Sequence: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i] != "-") cout << slot[i] << " ";
    }
    cout << "\nMaximum Profit: " << totalProfit << endl;

    return 0;
}