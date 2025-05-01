#include <iostream>
#include <string>
#include <climits>  
using namespace std;

int n;  
string *office;  
int **adj;  

void prims(){
    int visit[n], mincost = 0, count = n - 1, minIndex, cost = 0;

   
    for(int i = 0; i < n; i++){
        visit[i] = 0;
    }

    cout << "Shortest Path: ";
    visit[0] = 1;  
    cout << office[0] << "->";

   
    while (count--) {
        mincost = INT_MAX;

       
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                if (visit[i] == 1 && adj[i][j] != 0 && adj[i][j] < mincost && visit[j] == 0) {
                    mincost = adj[i][j];
                    minIndex = j;
                }
            }
        }

       
        visit[minIndex] = 1;
        cout << office[minIndex] << "->";
        cost += mincost;  
    }

   
    cout << "Total cost: " << cost << endl;
}

int main() {
    cout << "Enter the number of cities: ";
    cin >> n;

    office = new string[n]; 
    adj = new int*[n];  

   
    for (int i = 0; i < n; i++) {
        adj[i] = new int[n];
    }

    
    cout << "Enter the names of the cities: ";
    for (int i = 0; i < n; i++) {
        cin >> office[i];
    }

    
    cout << "Enter the cost matrix (use 0 if there's no direct connection between two cities):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Cost from " << office[i] << " to " << office[j] << ": ";
            cin >> adj[i][j];
        }
    }

    
    prims();

    
    delete[] office;
    for (int i = 0; i < n; i++) {
        delete[] adj[i];
    }
    delete[] adj;

    return 0;
}
