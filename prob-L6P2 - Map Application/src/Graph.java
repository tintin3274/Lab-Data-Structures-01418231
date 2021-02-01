import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;

public class Graph {
    private int V;
    private int [][] weight;
    private HashMap<Integer, Node> nodes = new HashMap<>();

    public Graph(int v) {
        V = v;
        weight = new int[v][v];
        for(int i = 0; i<v; i++){
            nodes.put(i, new Node(i));
        }
    }

    public void addEdge(int n1, int n2, int w) {
        nodes.get(n1).addNextNode(nodes.get(n2));
        nodes.get(n2).addNextNode(nodes.get(n1));
        weight[n1][n2] = w;
        weight[n2][n1] = w;
    }

    public void dijkstra(int start, int destination){
        LinkedList<Integer> queue = new LinkedList<>();
        int [] distance = new int[V];
        boolean [] visited = new boolean[V];

        for (int i = 0; i < V; i++) {
            distance[i] = Integer.MAX_VALUE;
            visited[i] = false;
        }

        distance[start] = 0;
        queue.add(start);
        while (!queue.isEmpty()){
            int q = queue.removeFirst();
            for (Node nextNode : nodes.get(q).getNextNode()){
                int distanceFormStart = distance[q];
                if(!visited[nextNode.getNumber()]){
                    if(distanceFormStart < distance[nextNode.getNumber()]){
                        distance[nextNode.getNumber()] = distanceFormStart;
                    }
                    queue.add(nextNode.getNumber());
                }
            }
        }
        System.out.println(distance);
    }



    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int i, n, e, w, n1, n2;

        Graph graph = new Graph(sc.nextInt());
        e = sc.nextInt();
        for(i = 0; i<e; i++){
            graph.addEdge(sc.nextInt(), sc.nextInt(), sc.nextInt());
        }
        graph.dijkstra(sc.nextInt(), sc.nextInt());
    }
}

class Node {
    private int number;
    private HashSet<Node> nextNode = new HashSet<>();

    public Node(int number) {
        this.number = number;
    }

    public void addNextNode(Node newNextNode){
        nextNode.add(newNextNode);
    }

    public int getNumber() {
        return number;
    }

    public HashSet<Node> getNextNode() {
        return nextNode;
    }
}
