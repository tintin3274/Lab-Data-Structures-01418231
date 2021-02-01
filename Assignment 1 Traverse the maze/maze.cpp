// C++ program to print DFS traversal from 
// a given vertex in a  given graph 
#include<iostream> 
#include<list> 
using namespace std; 

// Graph class represents a directed graph 
// using adjacency list representation 
class Graph 
{ 
    int V;    // No. of vertices 
  
    // Pointer to an array containing 
    // adjacency lists 
    list<int> *adj; 
  
    // A recursive function used by DFS 
    void DFSUtil(int v, bool visited[]); 
public: 
    int target;
    bool found;

    Graph(int V);   // Constructor 
  
    // function to add an edge to graph 
    void addEdge(int v, int w); 
  
    // DFS traversal of the vertices 
    // reachable from v 
    void DFS(int v, int t); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
    adj[w].push_back(v); // Add v to w’s list. 
} 
  
void Graph::DFSUtil(int v, bool visited[]) 
{ 
    // Mark the current node as visited and 
    // print it 
    visited[v] = true; 
    //cout << v << " ";
    if(target == v){
        found = true;
    }

  
    // Recur for all the vertices adjacent 
    // to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil() 
void Graph::DFS(int v, int t) 
{ 
    target = t;
    found = false;
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function 
    // to print DFS traversal 
    DFSUtil(v, visited); 
} 
  
// Driver code 
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(38);
    g.addEdge(0, 1);
    g.addEdge(0, 7);
    g.addEdge(1, 2);
    g.addEdge(1, 8);
    g.addEdge(2, 3);
    g.addEdge(2, 14);
    g.addEdge(3, 6);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(5, 16);
    g.addEdge(7, 8);
    g.addEdge(9, 10);
    g.addEdge(10, 15);
    g.addEdge(11, 12);
    g.addEdge(11, 17);
    g.addEdge(12, 22);
    g.addEdge(13, 14);
    g.addEdge(13, 18);
    g.addEdge(14, 15);
    g.addEdge(14, 24);
    g.addEdge(16, 17); 
    g.addEdge(16, 32);
    g.addEdge(17, 26);
    g.addEdge(19, 29);
    g.addEdge(20, 21); 
    g.addEdge(21, 36);
    g.addEdge(23, 28);
    g.addEdge(24, 25);
    g.addEdge(25, 31);
    g.addEdge(27, 33);
    g.addEdge(28, 29);
    g.addEdge(29, 35);
    g.addEdge(30, 31);
    g.addEdge(32, 33);
    g.addEdge(33, 37);
    g.addEdge(34, 35);
    g.addEdge(35, 36);
    g.addEdge(36, 37);                 

    g.DFS(0, 34);

    if(g.found){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
  
    return 0; 
} 