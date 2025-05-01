#include<iostream>
#include<iomanip>
#include<string>
#include<stack>
using namespace std;

void createGraph(int **graph, string cities[], int n){
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int t;
            cout << "Enter time required to flight between " + cities[i] + " to " + cities[j] + " : ";
            cin >> t;
            graph[i][j] = t;
            graph[j][i] = t;
            cout << endl;
        }
    }
}

void printGraph(int **graph, string *cities, int n){
    cout << setw(10) << " ";
    for(int i = 0; i < n; i++){
        cout << setw(10) << cities[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << setw(10) << cities[i] << " ";
        for(int j = 0; j < n; j++){
            cout << setw(8) << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void DFS(int **graph, string cities[], int n, int start, bool *visited){
    stack<int> s;
    s.push(start);  
    visited[start] = true;
    
    cout << "DFS Traversal: ";
    
    while(!s.empty()){
        int node = s.top();
        s.pop();
        cout << cities[node] << " "; 
        
       
        for(int i = 0; i < n; i++){
            
            if(graph[node][i] != 0 && !visited[i]){
                visited[i] = true; 
                s.push(i);  
            }
        }
    }
    cout << endl;
}

int main(){
    int n;
    cout << "Enter no of cities: ";
    cin >> n;
    string *cities = new string[n];
    
    cout << "Enter cities: ";
    for(int i = 0; i < n; i++){
        cin >> cities[i];
    }
    
    int **graph = new int*[n];
    for (int i = 0; i < n; ++i) {
        graph[i] = new int[n]();
    }
    
    createGraph(graph, cities, n);
    printGraph(graph, cities, n);
    
    bool *visited = new bool[n]();  
    

    cout << "Starting DFS from city: " << cities[0] << endl;
    DFS(graph, cities, n, 0, visited);

   
    delete[] cities;
    for(int i = 0; i < n; i++){
        delete[] graph[i];
    }
    delete[] graph;
    delete[] visited;
    
    return 0;
}
