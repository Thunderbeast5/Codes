#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;

    int values[20], weight[20];
    double ratio[20]; 

    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    for (int i = 0; i < n; i++) {
        cout << "Enter value and weight of item " << i + 1 << ": ";
        cin >> values[i] >> weight[i];
        ratio[i] = (double)values[i] / weight[i]; 
    }

    cout << "\nCalculating value/weight ratio for each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": value = " << values[i]
             << ", weight = " << weight[i]
             << ", ratio = " << ratio[i] << endl;
    }

    cout << "\nSorting items by value/weight ratio in descending order:\n";

    // Bubble sort based on ratio
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                swap(ratio[i], ratio[j]);
                swap(values[i], values[j]);
                swap(weight[i], weight[j]);
                cout << "Swapped item " << i + 1 << " with item " << j + 1 << endl;
            }
        }
    }

    //Selection Sort based on ratio
    /*for (int i = 0; i < n - 1; i++) {
    int maxIndex = i;
    for (int j = i + 1; j < n; j++) {
        if (ratio[j] > ratio[maxIndex]) {
            maxIndex = j;
        }
    }

    if (maxIndex != i) {
        swap(ratio[i], ratio[maxIndex]);
        swap(values[i], values[maxIndex]);
        swap(weight[i], weight[maxIndex]);
        cout << "Swapped item " << i + 1 << " with item " << maxIndex + 1 << endl;
    }
}*/

    cout << "\nItems after sorting:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": value = " << values[i]
             << ", weight = " << weight[i]
             << ", ratio = " << ratio[i] << endl;
    }

    float totalValue = 0, currentWeight = 0;

    cout << "\nFilling the knapsack:\n";
    for (int i = 0; i < n; i++) {
        if (currentWeight + weight[i] <= capacity) {
            currentWeight += weight[i];
            totalValue += values[i];
            cout << "Taking full item " << i + 1
                 << " (weight = " << weight[i]
                 << ", value = " << values[i]
                 << "). Current weight: " << currentWeight
                 << ", total value: " << totalValue << endl;
        } else {
            float remain = capacity - currentWeight;
            totalValue += ratio[i] * remain;
            cout << "Taking fractional part of item " << i + 1
                 << " (weight = " << remain
                 << ", value = " << ratio[i] * remain
                 << "). Knapsack is full now." << endl;
            break;
        }
    }

    cout << "\nMaximum value that can be obtained = " << totalValue << endl;

    return 0;
}