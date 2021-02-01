import java.util.ArrayList;
import java.util.Scanner;

public class Queue {
    public static void main(String[] args) {
        ArrayList<Integer> queueTeacher = new ArrayList<>();
        ArrayList<Integer> queueSchool = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        int i, j, n, count=0;
        n = sc.nextInt();
        for(i=0; i<n; i++){
            queueTeacher.add(sc.nextInt());
        }
        for(i=0; i<n; i++){
            queueSchool.add(sc.nextInt());
        }
        for(i=0; i<n; i++){
            while(true){
                if(queueSchool.get(i) == queueTeacher.get(i)){
                    count++;
                    break;
                }
                else{
                    queueTeacher.add(queueTeacher.remove(i));
                    count++;
                }
            }
        }
        System.out.println(count);
    }
}