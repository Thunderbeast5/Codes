#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to solve 0-1 Knapsack using Dynamic Programming
int knapsackDP(int W, const vector<int>& wt, const vector<int>& val, int n) {
    // Create DP table: dp[i][w] = max value using first i items with capacity w
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build table bottom-up
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Display DP table (optional, for learning)
    cout << "\nDP Table:\n";
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++)
            cout << dp[i][w] << "\t";
        cout << endl;
    }

    // Backtrack to find selected items
    int res = dp[n][W];
    int w = W;
    vector<int> selected;
    for (int i = n; i > 0 && res > 0; i--) {
        if (res == dp[i - 1][w])
            continue; // Item not included
        else {
            selected.push_back(i); // Item included
            res -= val[i - 1];
            w -= wt[i - 1];
        }
    }

    // Show selected items
    reverse(selected.begin(), selected.end());
    cout << "\nItems included (1-indexed): ";
    for (int i : selected)
        cout << i << " ";
    cout << endl;

    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> wt(n), val(n);
    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++)
        cin >> val[i];

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    int maxValue = knapsackDP(W, wt, val, n);
    cout << "\nMaximum value that can be obtained = " << maxValue << endl;

    return 0;
}
/*
(base) unix@unix-HP-280-G1-MT:~/tyb_46$ g++ knapsack_dp.cpp
(base) unix@unix-HP-280-G1-MT:~/tyb_46$ ./a.out
Enter number of items: 4
Enter weights of items: 2 3 4 5
Enter values of items: 3 4 5 8
Enter capacity of knapsack: 8

DP Table:
0	0	0	0	0	0	0	0	0	
0	0	3	3	3	3	3	3	3	
0	0	3	4	4	7	7	7	7	
0	0	3	4	5	7	8	9	9	
0	0	3	4	5	8	8	11	12	

Items included (1-indexed): 2 4 

Maximum value that can be obtained = 12
(base) unix@unix-HP-280-G1-MT:~/tyb_46$ 

*/
