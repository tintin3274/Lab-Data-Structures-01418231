import java.util.Scanner;
import java.util.Stack;

public class prob_L3P2_Game_Card {
    public static void main(String[] args) {
        int i, j, n, m, sum=0;
        String in, answer="";
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        Stack<Integer> stack = new Stack<>();

        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                in = sc.next();
                switch (in){
                    case "C": stack.pop();break;
                    case "D": stack.push(stack.peek()*2);break;
                    case "+": stack.push(stack.get(stack.size()-2)+stack.peek());break;
                    default: stack.push(Integer.parseInt(in));break;
                }
            }
            while (!stack.empty()){
                sum += stack.pop();
            }
            answer += sum+" ";
            sum = 0;
        }
        System.out.println(answer);
    }
}