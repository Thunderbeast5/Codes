/*Flight management: There are flight paths between cities. If there is a flight between city A and city B, then there is an edge between the cities. The cost of the edge can be the time that flight takes to reach city B from A, or the amount of fuel used for the journey.
Write a menu driven C++ program to represent this as a graph using adjacency matrix and adjacency list. The node can be represented by the airport name or name of the city. Check whether cities are connected through flight or not. Compare the storage representation.*/
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int vertex;
    int time;
    int fuel;
    string city;
    Node* next;

    Node(int v = 0, int t = 0, int f = 0, string c = "") {
        vertex = v;
        time = t;
        fuel = f;
        city = c;
        next = NULL;
    }
};

class Graph {
    Node* head[20];
    string cities[20];
    int e;
    int v;

public:
    Graph() {
        for (int i = 0; i < 20; i++) {
            head[i] = new Node(i);
        }
        e = 0;
        v = 0;
    }

    void readGraph() {
        cout << "Enter the number of vertices (cities) [max 20]: ";
        cin >> v;

        cin.ignore();
        cout << "Enter city names:\n";
        for (int i = 0; i < v; i++) {
            cout << "City " << i << ": ";
            getline(cin, cities[i]);
            head[i]->city = cities[i];
        }

        cout << "Enter the number of flights (edges): ";
        cin >> e;

        for (int i = 0; i < e; i++) {
            int v1, v2, time, fuel;
            cout << "\nFlight " << i + 1 << ":\n";
            cout << "Enter index of source city (0 to " << v - 1 << "): ";
            cin >> v1;
            cout << "Enter index of destination city (0 to " << v - 1 << "): ";
            cin >> v2;
            cout << "Enter time and fuel for this flight: ";
            cin >> time >> fuel;

            Node* curr1 = new Node(v2, time, fuel, cities[v2]);

            Node* temp1 = head[v1];
            while (temp1->next != NULL) {
                temp1 = temp1->next;
            }
            temp1->next = curr1;

            //If graph is undirected, add the reverse edge as well
            // Node* curr2 = new Node(v1, time, fuel, cities[v1]); 
    
            // // Find the end of v2's list
            // Node* temp2 = head[v2];
            // while (temp2->next != NULL) {
            //     temp2 = temp2->next;
            // }
            // // Attach the return flight to v2's list
            // temp2->next = curr2;
        }
    }

    void checkDirectFlight() {
        int a, b;
        cout << "Enter the index of the source city: ";
        cin >> a;
        cout << "Enter the index of the destination city: ";
        cin >> b;

        if (a < 0 || a >= v || b < 0 || b >= v) {
            cout << "Invalid city index.\n";
            return;
        }

        Node* temp = head[a]->next;
        while (temp != NULL) {
            if (temp->vertex == b) {
                cout << "\n*** Flight is AVAILABLE from " << cities[a] << " to " << cities[b] << " ***\n"
                     << "    Time: " << temp->time << ", Fuel: " << temp->fuel << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "\n*** No direct flight from " << cities[a] << " to " << cities[b] << " ***\n";
    }

    void displayAllFlights() {
        cout << "\n---------- All Available Flights ----------\n";
        for (int i = 0; i < v; i++) {
            Node* temp = head[i]->next;
            cout << cities[i] << " -> ";
            while (temp != NULL) {
                cout << "[" << cities[temp->vertex] << " (T:" << temp->time << ", F:" << temp->fuel << ")] -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
        cout << "-------------------------------------------\n";
    }

    void countTotalFlights() {
        int a;
        cout << "Enter the index of the source city to count flights: ";
        cin >> a;

        if (a < 0 || a >= v) {
            cout << "Invalid city index.\n";
            return;
        }

        int count = 0;
        Node* temp = head[a]->next;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        cout << "\n*** There are " << count << " outgoing flights from " << cities[a] << " ***\n";
    }

    void showCities() {
        cout << "\nList of cities:\n";
        for (int i = 0; i < v; i++) {
            cout << i << " - " << cities[i] << endl;
        }
    }

    // ---------------- Operation 4: Print All Routes ----------------
    void printAllRoutesUtil(int src, int dest, bool visited[], string path, int totalTime, int totalFuel) {
        visited[src] = true;

        if (src == dest) {
            cout << path << " | Total Time: " << totalTime << ", Total Fuel: " << totalFuel << endl;
            visited[src] = false;
            return;
        }

        Node* temp = head[src]->next;
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                printAllRoutesUtil(temp->vertex, dest, visited,
                                   path + " -> " + cities[temp->vertex],
                                   totalTime + temp->time,
                                   totalFuel + temp->fuel);
            }
            temp = temp->next;
        }

        visited[src] = false;
    }

    void printAllRoutes() {
        int src, dest;
        cout << "Enter source city index: ";
        cin >> src;
        cout << "Enter destination city index: ";
        cin >> dest;

        if (src < 0 || src >= v || dest < 0 || dest >= v) {
            cout << "Invalid city index.\n";
            return;
        }

        bool visited[20] = {false};
        cout << "\nAll possible routes from " << cities[src] << " to " << cities[dest] << ":\n";
        printAllRoutesUtil(src, dest, visited, cities[src], 0, 0);
    }

    // ---------------- Operation 5: Reachable Cities with Cost ----------------
    void reachableCitiesUtil(int src, bool visited[], int totalTime, int totalFuel) {
        visited[src] = true;
        cout << cities[src] << " (Time: " << totalTime << ", Fuel: " << totalFuel << ")\n";

        Node* temp = head[src]->next;
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                reachableCitiesUtil(temp->vertex, visited, totalTime + temp->time, totalFuel + temp->fuel);
            }
            temp = temp->next;
        }
    }

    void reachableCities() {
        int src;
        cout << "Enter source city index: ";
        cin >> src;

        if (src < 0 || src >= v) {
            cout << "Invalid city index.\n";
            return;
        }

        bool visited[20] = {false};
        cout << "\nReachable cities from " << cities[src] << ":\n";
        reachableCitiesUtil(src, visited, 0, 0);
    }
};

int main() {
    Graph g;
    int choice;

    do {
        cout << "\n---- Flight Management Menu ----\n";
        cout << "1. Create Flight Graph\n";
        cout << "2. Check Direct Flight (Operation 1)\n";
        cout << "3. Display All Flights (Operation 2)\n";
        cout << "4. Print All Routes Between Two Cities (Operation 4)\n";
        cout << "5. Find All Reachable Cities from a Source with cost (Operation 5)\n";
        cout << "6. Count Flights from a City (Operation 3)\n";
        cout << "7. Show City List (Helper)\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            g.readGraph();
            break;
        case 2:
            g.checkDirectFlight();
            break;
        case 3:
            g.displayAllFlights();
            break;
        case 4:
            g.printAllRoutes();
            break;
        case 5:
            g.reachableCities();
            break;
        case 6:
            g.countTotalFlights();
            break;
        case 7:
            g.showCities();
            break;
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 8);

    return 0;
}