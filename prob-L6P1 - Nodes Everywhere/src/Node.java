import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;

public class Node {
    private int number;
    private HashSet<Node> childNode = new HashSet<>();

    public Node(int number) {
        this.number = number;
    }

    public void addChildNode(Node newChildNode){
        childNode.add(newChildNode);
    }

    public int getNumber() {
        return number;
    }

    public HashSet<Node> getChildNode() {
        return childNode;
    }

    public static void main(String[] args) {
        HashMap<Integer, Node> nodes = new HashMap<>();
        Scanner sc = new Scanner(System.in);
        int i, n, q, k1, k2;

        n = sc.nextInt();
        for(i = 1; i<=n; i++){
            nodes.put(i, new Node(i));
        }

        n = sc.nextInt();
        for(i = 0; i<n; i++){
            k1 = sc.nextInt();
            k2 = sc.nextInt();
            nodes.get(k1).addChildNode(nodes.get(k2));
        }

        int numInternalNode = 0;
        LinkedList<Integer> queue = new LinkedList<>();
        n = sc.nextInt();
        queue.add(n);
        while (!queue.isEmpty()){
            q = queue.removeFirst();
            for(Node child : nodes.get(q).getChildNode()){
                queue.add(child.getNumber());
                numInternalNode++;
            }
        }
        System.out.println(numInternalNode);
    }
}
