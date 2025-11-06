#include <iostream>
#include <string>
using namespace std;

class Graph {
    string cities[20];
    int time[20][20];   // time[i][j] = time from city i to j
    int fuel[20][20];   // fuel[i][j] = fuel from city i to j
    int v;
    bool isDirected;

public:
    Graph() {
        v = 0;
        // Initialize all entries to 0 (no connection)
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                time[i][j] = 0;
                fuel[i][j] = 0;
            }
        }
    }

    void readGraph() {
        cout << "Enter number of cities (vertices) [max 20]: ";
        cin >> v;

        cin.ignore();
        cout << "Enter city names:\n";
        for (int i = 0; i < v; i++) {
            cout << "City " << i << ": ";
            getline(cin, cities[i]);
        }

        cout << "Is the graph directed? (1 = Yes, 0 = No): ";
        cin >> isDirected;

        int e;
        cout << "Enter number of flights (edges): ";
        cin >> e;

        for (int i = 0; i < e; i++) {
            int v1, v2, t, f;
            cout << "\nFlight " << i + 1 << ":\n";
            cout << "Enter index of source city (0 to " << v - 1 << "): ";
            cin >> v1;
            cout << "Enter index of destination city (0 to " << v - 1 << "): ";
            cin >> v2;
            cout << "Enter time and fuel: ";
            cin >> t >> f;

            time[v1][v2] = t;
            fuel[v1][v2] = f;

            if (!isDirected) {
                time[v2][v1] = t;
                fuel[v2][v1] = f;
            }
        }
    }

    void showCities() {
        cout << "\nList of cities:\n";
        for (int i = 0; i < v; i++) {
            cout << i << " - " << cities[i] << endl;
        }
    }

    void displayMatrix() {
        cout << "\nTime Matrix (0 = No Flight):\n";
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                cout << time[i][j] << "\t";
            }
            cout << endl;
        }

        cout << "\nFuel Matrix (0 = No Flight):\n";
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                cout << fuel[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void checkDirectFlight() {
        int a, b;
        cout << "Enter source city index: ";
        cin >> a;
        cout << "Enter destination city index: ";
        cin >> b;

        if (a < 0 || a >= v || b < 0 || b >= v) {
            cout << "Invalid city index.\n";
            return;
        }

        if (time[a][b] != 0) {
            cout << "\n*** Flight available from " << cities[a] << " to " << cities[b]
                 << " | Time: " << time[a][b] << ", Fuel: " << fuel[a][b] << " ***\n";
        } else {
            cout << "\n*** No direct flight from " << cities[a] << " to " << cities[b] << " ***\n";
        }
    }

    void countFlightsFromCity() {
        int a;
        cout << "Enter city index: ";
        cin >> a;
        if (a < 0 || a >= v) {
            cout << "Invalid city index.\n";
            return;
        }

        int count = 0;
        for (int j = 0; j < v; j++) {
            if (time[a][j] != 0)
                count++;
        }
        cout << "\n*** " << cities[a] << " has " << count << " outgoing flights ***\n";
    }

    // ---------- Operation 4: Print All Routes ----------
    void printAllRoutesUtil(int src, int dest, bool visited[], string path, int totalTime, int totalFuel) {
        visited[src] = true;

        if (src == dest) {
            cout << path << " | Total Time: " << totalTime << ", Total Fuel: " << totalFuel << endl;
            visited[src] = false;
            return;
        }

        for (int i = 0; i < v; i++) {
            if (time[src][i] != 0 && !visited[i]) {
                printAllRoutesUtil(i, dest, visited, path + " -> " + cities[i],
                                   totalTime + time[src][i],
                                   totalFuel + fuel[src][i]);
            }
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

    // ---------- Operation 5: Reachable Cities ----------
    void reachableCitiesUtil(int src, bool visited[], int totalTime, int totalFuel) {
        visited[src] = true;
        cout << cities[src] << " (Time: " << totalTime << ", Fuel: " << totalFuel << ")\n";

        for (int i = 0; i < v; i++) {
            if (time[src][i] != 0 && !visited[i]) {
                reachableCitiesUtil(i, visited, totalTime + time[src][i], totalFuel + fuel[src][i]);
            }
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
        cout << "\n---- Flight Management Menu (Adjacency Matrix) ----\n";
        cout << "1. Create Flight Graph\n";
        cout << "2. Show City List\n";
        cout << "3. Display Time & Fuel Matrix\n";
        cout << "4. Check Direct Flight\n";
        cout << "5. Count Flights from a City\n";
        cout << "6. Print All Routes Between Two Cities\n";
        cout << "7. Find All Reachable Cities from a Source\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            g.readGraph();
            break;
        case 2:
            g.showCities();
            break;
        case 3:
            g.displayMatrix();
            break;
        case 4:
            g.checkDirectFlight();
            break;
        case 5:
            g.countFlightsFromCity();
            break;
        case 6:
            g.printAllRoutes();
            break;
        case 7:
            g.reachableCities();
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