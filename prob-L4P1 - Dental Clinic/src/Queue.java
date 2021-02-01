import java.util.ArrayList;
import java.util.Scanner;

public class Queue {
    String name;
    int time;

    public Queue(String name, String time) {
        this.name = name.replace("+", "");
        this.time = Integer.parseInt((time.replace("time=", "")));
    }

    public static void main(String[] args) {
        ArrayList<Queue> queue = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        int i, j, n, m, timeCheck, timeSum = -1;
        n = sc.nextInt();
        for (i = 0; i < n; i++) {
            queue.add(new Queue(sc.next(), sc.next()));
        }
        m = sc.nextInt();
        for (i = 0; i < m; i++) {
            String nameDelete = sc.next().replace("-", "");
            for (j = 0; j < queue.size(); j++) {
                if (queue.get(j).name.equals(nameDelete)) {
                    queue.remove(j);
                    break;
                }
            }
        }
        timeCheck = sc.nextInt();
        for (i = 0; i < queue.size(); i++) {
            if (timeSum >= timeCheck) {
                System.out.println(queue.get(i).name);
            }
            timeSum += queue.get(i).time;
        }
    }
}