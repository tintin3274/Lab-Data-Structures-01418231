import java.util.*;

// This class represents a directed graph using adjacency list 
// representation 
public class Graph
{
    private int V;   // No. of vertices
    private int source;
    private int destination;

    // LinkedList  of LinkedList for Adjacency List Representation
    private LinkedList<LinkedList<Integer>> adj;
    private boolean visited[];
    private int pred[], dist[];
    private LinkedList<Integer> queue;
    private LinkedList<Integer> BFS;

    private char[][] map;
    private ArrayList<Character> mapArrayList;
    private int y, x;

    // Constructor
    public Graph(int y, int x, char[][] map, ArrayList<Character> mapArrayList) {
        V = y*x;
        this.y = y;
        this.x = x;
        this.map = map;
        this.mapArrayList = mapArrayList;

        adj = new LinkedList<>();
        for (int i=0; i<V; i++)
            adj.add(new LinkedList<>());
    }

    //Function to add an edge into the graph 
    void addEdge(int v, int w)
    {
        adj.get(v).add(w);  // Add w to v's list.
        adj.get(w).add(v);  // Add v to w's list.
    }

    boolean BFS(){
        visited = new boolean[V];
        pred = new int[V];
        dist = new int[V];
        for(int i = 0; i < V; i++){
            dist[i] = Integer.MAX_VALUE;
            pred[i] = -1;
        }

        visited[source] = true;
        dist[source] = 0;
        queue = new LinkedList<>();
        queue.add(source);

        while (!queue.isEmpty()){
            int u = queue.getFirst();
            queue.removeFirst();
            for(int i : adj.get(u)){
                if (!visited[i]){
                    visited[i] = true;
                    dist[i] = dist[u] + 1;
                    pred[i] = u;
                    queue.add(i);

                    if(i == destination)
                        return true;
                }
            }
        }
        return false;
    }

    void printShortestDistance(){
        if(BFS() == false){
            System.out.println("Given source and destination are not connected");
            return;
        }
        BFS = new LinkedList<>();
        int crawl = destination;
        BFS.add(crawl);
        while (pred[crawl] != -1){
            BFS.addFirst(pred[crawl]);
            crawl = pred[crawl];
        }
        System.out.println(dist[destination]);
        //System.out.println(BFS);
    }

    void createGraphFromMap(){
        int i, j;
        for(i=0; i<y; i++){
            for(j=0; j<x; j++){
                if(i-1 >= 0 && map[i-1][j] != '#'){
                    addEdge((i*x)+j, ((i-1)*x)+j);
                }
                if(i+1 < y && map[i+1][j] != '#'){
                    addEdge((i*x)+j, ((i+1)*x)+j);
                }
                if(j-1 >= 0 && map[i][j-1] != '#'){
                    addEdge((i*x)+j, (i*x)+j-1);
                }
                if(j+1 < x && map[i][j+1] != '#'){
                    addEdge((i*x)+j, (i*x)+j+1);
                }
            }
        }
    }

    boolean checkTreasure(){
        source = mapArrayList.indexOf('s');
        if(mapArrayList.indexOf('$') >= 0){
            destination = mapArrayList.indexOf('$');
        }
        else if(mapArrayList.indexOf('*') >= 0){
            destination = mapArrayList.indexOf('*');
        }
        else if(mapArrayList.indexOf('+') >= 0){
            destination = mapArrayList.indexOf('+');
        }
        else if(mapArrayList.indexOf('^') >= 0){
            destination = mapArrayList.indexOf('^');
        }
        else {return false;}
        return true;
    }

    void findTreasure(){
        if(checkTreasure()){
            createGraphFromMap();
            printShortestDistance();
        }
        else {
            System.out.println("not found treasure");
        }
    }


    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        String input;
        int i, j, x, y;
        y = sc.nextInt();
        x = sc.nextInt();
        char[][] map = new char[y][x];
        ArrayList<Character> mapArrayList = new ArrayList<>();
        for(i=0; i<y; i++){
            input = sc.next();
            for(j=0; j<x; j++){
                map[i][j] = input.charAt(j);
                mapArrayList.add(input.charAt(j));
            }
        }

        Graph g = new Graph(y, x, map, mapArrayList);
        g.findTreasure();
    }
} 