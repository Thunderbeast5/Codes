#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int itemNo, value, weight;
    Item(int no = 0, int v = 0, int w = 0) : itemNo(no), value(v), weight(w) {}
};

bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(Item arr[], int n, int capacity) {
    sort(arr, arr + n, cmp);
    
    int curWeight = 0;
    double finalValue = 0.0;
    
    cout << "\nKnapsack Filling:\n";
    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= capacity) {
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
            cout << "Item " << arr[i].itemNo << ": Full (W:" << arr[i].weight 
                 << ", V:" << arr[i].value << ")\n";
        } else {
            int remain = capacity - curWeight;
            double fraction = (double)remain / arr[i].weight;
            finalValue += arr[i].value * fraction;
            cout << "Item " << arr[i].itemNo << ": Fraction " << fraction 
                 << " (W:" << remain << ", V:" << arr[i].value * fraction << ")\n";
            break;
        }
    }
    return finalValue;
}

int main() {
    Item items[100];
    int n = 0, capacity = 0, choice;
    
    do {
        cout << "\n--- Fractional Knapsack Menu ---\n";
        cout << "1. Enter Items\n";
        cout << "2. Set Capacity\n";
        cout << "3. Solve Knapsack\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Number of items: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    items[i].itemNo = i + 1;
                    cout << "Item " << i+1 << " - Value: ";
                    cin >> items[i].value;
                    cout << "Item " << i+1 << " - Weight: ";
                    cin >> items[i].weight;
                }
                cout << "Items entered successfully!\n";
                break;
                
            case 2:
                cout << "Enter capacity: ";
                cin >> capacity;
                cout << "Capacity set to " << capacity << endl;
                break;
                
            case 3:
                if (n == 0 || capacity == 0) {
                    cout << "Enter items and capacity first!\n";
                } else {
                    double result = fractionalKnapsack(items, n, capacity);
                    cout << "\nMaximum Profit: " << result << endl;
                }
                break;
                
            case 4:
                cout << "Exiting...\n";
                break;
                
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);
    
    return 0;
}