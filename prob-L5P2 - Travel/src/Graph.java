// Java program to print DFS traversal from a given given graph 
import java.util.*;

// This class represents a directed graph using adjacency list 
// representation 
public class Graph
{
    private int V;   // No. of vertices
    private int target;

    // LinkedList  of LinkedList for Adjacency List Representation
    private LinkedList<LinkedList<Integer>> adj;
    private boolean visited[];
    private LinkedList<Integer> DPS;

    // Constructor 
    Graph(int v)
    {
        V = v;
        adj = new LinkedList<>();
        for (int i=0; i<v; i++)
            adj.add(new LinkedList<>());
    }

    //Function to add an edge into the graph 
    void addEdge(int v, int w)
    {
        adj.get(v).add(w);  // Add w to v's list.
        adj.get(w).add(v);  // Add v to w's list.
    }

    // A function used by DFS 
    void DFSUtil(int v)
    {
        // Mark the current node as visited and print it 
        visited[v] = true;
        DPS.add(v);

        // Recur for all the vertices adjacent to this vertex
        for(int i : adj.get(v)){
            if (!visited[i])
                DFSUtil(i);
        }
    }

    // The function to do DFS traversal. It uses recursive DFSUtil() 
    void DFS(int v, int t)
    {
        // Mark all the vertices as not visited(set as 
        // false by default in java) 
        visited = new boolean[V];
        DPS = new LinkedList<>();
        target = t;

        // Call the recursive helper function to print DFS traversal 
        DFSUtil(v);
        if(DPS.contains(target)){
            System.out.println("go go!");
        }
        else {
            System.out.println("stay home");
        }
    }

    public LinkedList<Integer> getDPS() {
        return DPS;
    }

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int i, n;
        Graph g = new Graph(sc.nextInt());
        n = sc.nextInt();
        for(i=0; i<n; i++){
            g.addEdge(sc.nextInt(), sc.nextInt());
        }
        g.DFS(sc.nextInt(), sc.nextInt());
    }
} 