#include <iostream>
using namespace std;

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    int weight[20], value[20];   // weight = cost, value = profit or benefit

    cout << "Enter weight of each item: ";
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter value of each item: ";
    for (int i = 0; i < n; i++)
        cin >> value[i];

    cout << "Enter capacity of the knapsack: ";
    cin >> capacity;

    int dp[20][100];  // assuming max capacity <= 100 for simplicity

    // Build DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i - 1] <= w)
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // ----------- DISPLAY DP TABLE -----------
    cout << "\nDP Table:\n";
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++)
            cout << dp[i][w] << "\t";
        cout << endl;
    }

    // Maximum value = dp[n][capacity]
    int maxValue = dp[n][capacity];

    // Backtrack to find selected items
    int w = capacity;
    int selected[20];
    int count = 0;
    int temp = maxValue; // copy of max value for backtracking
    for (int i = n; i > 0 && temp > 0; i--) {
        if (temp != dp[i - 1][w]) {  // item i was included
            selected[count++] = i;
            temp -= value[i - 1];
            w -= weight[i - 1];
        }
    }

    // ----------- DISPLAY RESULTS -----------
    cout << "\n------------------------------------";
    cout << "\nOptimal 0/1 Knapsack Result";
    cout << "\n------------------------------------";

    cout << "\nSelected items: ";
    for (int i = count - 1; i >= 0; i--)
        cout << selected[i] << " ";

    int totalWeight = 0;
    for (int i = 0; i < count; i++)
        totalWeight += weight[selected[i] - 1];

    cout << "\nTotal weight used = " << totalWeight;
    cout << "\nMaximum value achieved = " << dp[n][capacity] << endl;

    return 0;


}
