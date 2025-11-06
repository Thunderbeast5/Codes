#include <iostream>
using namespace std;

struct Item {
    int value;
    int weight;
    float ratio;
};

struct Node {
    int level;
    int profit;
    int weight;
    float bound;
};

// Function to calculate upper bound of profit in subtree of node u
float bound(Node u, int n, int W, Item items[]) {
    if (u.weight >= W)
        return 0; // invalid branch (overweight)

    float result = u.profit;
    int totalWeight = u.weight;
    int j = u.level + 1;

    // Take full items while possible
    while (j < n && totalWeight + items[j].weight <= W) {
        totalWeight += items[j].weight;
        result += items[j].value;
        j++;
    }

    // Take fraction of the next item (if any)
    if (j < n)
        result += (W - totalWeight) * items[j].ratio;

    return result;
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    Item items[20];
    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++)
        cin >> items[i].weight;

    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) {
        cin >> items[i].value;
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    // Sort items by ratio (value/weight) in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[j].ratio > items[i].ratio)
                swap(items[i], items[j]);
        }
    }

    // Initialize queue (simple array used as queue)
    Node queue[100];
    int front = 0, rear = 0;

    Node v, u;
    v.level = -1;
    v.profit = 0;
    v.weight = 0;
    v.bound = bound(v, n, W, items);
    queue[rear++] = v;

    int maxProfit = 0;

    // Branch and Bound logic
    while (front < rear) {
        v = queue[front++];
        if (v.level == n - 1)
            continue;

        u.level = v.level + 1;

        // Case 1: Include next item
        u.weight = v.weight + items[u.level].weight;
        u.profit = v.profit + items[u.level].value;

        if (u.weight <= W && u.profit > maxProfit)
            maxProfit = u.profit;

        u.bound = bound(u, n, W, items);
        if (u.bound > maxProfit)
            queue[rear++] = u;

        // Case 2: Exclude next item
        u.weight = v.weight;
        u.profit = v.profit;
        u.bound = bound(u, n, W, items);
        if (u.bound > maxProfit)
            queue[rear++] = u;
    }

    cout << "\nMaximum value obtained using Branch and Bound = " << maxProfit << endl;
    return 0;
}

