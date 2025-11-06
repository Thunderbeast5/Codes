#include <iostream>
using namespace std;

// Heapify function to maintain max heap property
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

// Build a max heap from array
void buildHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

// Delete maximum element (topmost element in max heap)
int deleteMax(int arr[], int &n) {
    if (n <= 0) return -1;
    
    int maxVal = arr[0];
    arr[0] = arr[n - 1];
    n--;
    heapify(arr, n, 0);
    
    return maxVal;
}

// Display all marks
void display(int arr[], int n) {
    if (n == 0) {
        cout << "No marks available.\n";
        return;
    }
    
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Find minimum marks manually (O(n) operation)
int findMin(int arr[], int n) {
    if (n == 0) return -1;
    
    int minVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] < minVal)
            minVal = arr[i];
    
    return minVal;
}

// Heap sort to display marks in ascending order
void heapSort(int arr[], int n) {
    if (n == 0) {
        cout << "No marks to display.\n";
        return;
    }
    
    // Create a temporary array to preserve original data
    int temp[100];
    for (int i = 0; i < n; i++)
        temp[i] = arr[i];
    
    int size = n;
    
    // Build max heap
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(temp, size, i);
    
    // Extract elements one by one from heap
    for (int i = size - 1; i > 0; i--) {
        swap(temp[0], temp[i]);
        heapify(temp, i, 0);
    }
    
    // Display sorted marks
    cout << "Marks in Ascending order: ";
    for (int i = 0; i < size; i++)
        cout << temp[i] << " ";
    cout << endl;
}

int main() {
    int marks[100];  // Array to store student marks
    int n = 0;       // Current number of marks
    int choice, mark;
    
    do {
        cout << "\n=== Student Marks Management System ===\n";
        cout << "1. Insert student marks\n";
        cout << "2. Display Maximum and Minimum marks\n";
        cout << "3. Delete topmost (Maximum) marks\n";
        cout << "4. Display all marks\n";
        cout << "5. Display all marks in Ascending order (Heap Sort)\n";
        cout << "6. Algorithmic Analysis\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter student marks (0-100): ";
                cin >> mark;
                
                // Validate marks
                if (mark < 0 || mark > 100) {
                    cout << "Invalid marks! Please enter marks between 0 and 100.\n";
                    break;
                }
                
                marks[n] = mark;
                n++;
                buildHeap(marks, n);
                cout << "Marks inserted successfully.\n";
                break;
                
            case 2:
                if (n == 0) {
                    cout << "No marks available.\n";
                } else {
                    cout << "Maximum marks: " << marks[0] << endl;
                    cout << "Minimum marks: " << findMin(marks, n) << endl;
                }
                break;
                
            case 3:
                if (n == 0) {
                    cout << "No marks to delete.\n";
                } else {
                    int maxVal = deleteMax(marks, n);
                    cout << "Deleted topmost (maximum) marks: " << maxVal << endl;
                }
                break;
                
            case 4:
                cout << "Current student marks: ";
                display(marks, n);
                break;
                
            case 5:
                heapSort(marks, n);
                break;
                
            case 6:
                cout << "\n=== Algorithmic Analysis ===\n";
                cout << "\n1. Insertion (with heapify):\n";
                cout << "   Time Complexity: O(log n)\n";
                cout << "   - Insert at end: O(1)\n";
                cout << "   - Rebuild heap: O(log n)\n";
                
                cout << "\n2. Find Maximum:\n";
                cout << "   Time Complexity: O(1)\n";
                cout << "   - Root element is always maximum in max heap\n";
                
                cout << "\n3. Find Minimum:\n";
                cout << "   Time Complexity: O(n)\n";
                cout << "   - Must traverse all elements as min can be any leaf\n";
                
                cout << "\n4. Delete Maximum:\n";
                cout << "   Time Complexity: O(log n)\n";
                cout << "   - Remove root: O(1)\n";
                cout << "   - Heapify down: O(log n)\n";
                
                cout << "\n5. Heap Sort:\n";
                cout << "   Time Complexity: O(n log n)\n";
                cout << "   - Build heap: O(n)\n";
                cout << "   - Extract max n times: O(n log n)\n";
                
                cout << "\n6. Build Heap:\n";
                cout << "   Time Complexity: O(n)\n";
                cout << "   - Bottom-up heapify approach\n";
                
                cout << "\nSpace Complexity: O(n)\n";
                cout << "   - Array storage for n elements\n";
                
                cout << "\n=== Heap Properties ===\n";
                cout << "- Max Heap: Parent >= Children\n";
                cout << "- Complete Binary Tree structure\n";
                cout << "- Height: O(log n)\n";
                cout << "- Efficient for finding maximum marks\n";
                break;
                
            case 7:
                cout << "Exiting... Thank you!\n";
                break;
                
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);
    
    return 0;
}