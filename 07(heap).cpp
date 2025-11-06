#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Build a max heap
void buildHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

// Delete max element (topmost)
int deleteMax(int arr[], int &n) {
    if (n <= 0) return -1;
    int maxVal = arr[0];
    arr[0] = arr[n - 1];
    n--;
    heapify(arr, n, 0);
    return maxVal;
}

// Display all prices
void display(int arr[], int n) {
    if (n == 0) {
        cout << "No prices available.\n";
        return;
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Find minimum manually
int findMin(int arr[], int n) {
    if (n == 0) return -1;
    int minVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] < minVal)
            minVal = arr[i];
    return minVal;
}

int main() {
    int arr[100];
    int n = 0;
    int choice, price;

    do {
        cout << "\n--- Stock Prices Menu ---\n";
        cout << "1. Insert daily stock price\n";
        cout << "2. Display Maximum and Minimum stock price\n";
        cout << "3. Delete topmost (Maximum) price\n";
        cout << "4. Display all prices\n";
        cout << "5. Display all prices in Ascending order (Heap Sort)\n";
        cout << "6. Algorithmic Analysis\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter stock price: ";
            cin >> price;
            arr[n] = price;
            n++;
            buildHeap(arr, n);
            cout << "Price inserted successfully.\n";
            break;

        case 2:
            if (n == 0)
                cout << "No prices available.\n";
            else {
                cout << "Maximum price: " << arr[0] << endl;
                cout << "Minimum price: " << findMin(arr, n) << endl;
            }
            break;

        case 3:
            if (n == 0)
                cout << "No prices to delete.\n";
            else {
                int maxVal = deleteMax(arr, n);
                cout << "Deleted topmost (maximum) price: " << maxVal << endl;
            }
            break;

        case 4:
            cout << "Current stock prices: ";
            display(arr, n);
            break;

        case 5:
            if (n == 0) {
                cout << "No prices to display.\n";
            } else {
                int temp[100];
                for (int i = 0; i < n; i++)
                    temp[i] = arr[i];
                int size = n;

                // Heap sort in ascending order
                for (int i = size / 2 - 1; i >= 0; i--)
                    heapify(temp, size, i);
                for (int i = size - 1; i > 0; i--) {
                    swap(temp[0], temp[i]);
                    heapify(temp, i, 0);
                }

                cout << "Prices in Ascending order: ";
                for (int i = 0; i < size; i++)
                    cout << temp[i] << " ";
                cout << endl;
            }
            break;

        case 6:
            cout << "\n--- Algorithmic Analysis ---\n";
            cout << "Insertion (heapify): O(log n)\n";
            cout << "Find Max: O(1)\n";
            cout << "Find Min: O(n)\n";
            cout << "Delete Max: O(log n)\n";
            cout << "Heap Sort: O(n log n)\n";
            cout << "Space Complexity: O(n)\n";
            break;

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 7);

    return 0;
}

