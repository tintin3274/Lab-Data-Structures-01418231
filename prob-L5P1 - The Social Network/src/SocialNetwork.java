import java.util.HashSet;
import java.util.Objects;
import java.util.Scanner;

public class SocialNetwork {
    private char name;
    private HashSet<SocialNetwork> friend = new HashSet<>();

    public SocialNetwork(char name) {
        this.name = name;
    }

    public char getName() {
        return name;
    }

    public void addFriend(SocialNetwork newFriend){
        friend.add(newFriend);
    }

    public void removeFriend(SocialNetwork removeFriend){
        friend.remove(removeFriend);
    }

    public HashSet<SocialNetwork> getFriend() {
        return friend;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        SocialNetwork that = (SocialNetwork) o;
        return name == that.name;
    }

    @Override
    public int hashCode() {
        return Objects.hash(name);
    }

    public static void main(String[] args) {
        HashSet<SocialNetwork> socialNetworkArrayList = new HashSet<>();
        Scanner sc = new Scanner(System.in);
        int i, n;

        n = sc.nextInt();
        for(i=0; i<n; i++){
            char aName = sc.next().charAt(0);
            char bName = sc.next().charAt(0);
            SocialNetwork a = new SocialNetwork(aName);
            SocialNetwork b = new SocialNetwork(bName);


            if(socialNetworkArrayList.contains(a) && socialNetworkArrayList.contains(b)){
                for(SocialNetwork s1 : socialNetworkArrayList){
                    if(s1.equals(a)){
                        for(SocialNetwork s2 : socialNetworkArrayList){
                            if(s2.equals(b)){
                                s1.addFriend(s2);
                                s2.addFriend(s1);
                                break;
                            }
                        }
                        break;
                    }
                }
            }

            else if(socialNetworkArrayList.contains(a) && !socialNetworkArrayList.contains(b)){
                for(SocialNetwork s1 : socialNetworkArrayList){
                    if(s1.equals(a)){
                        s1.addFriend(b);
                        b.addFriend(s1);
                        socialNetworkArrayList.add(b);
                        break;
                    }
                }
            }

            else if(!socialNetworkArrayList.contains(a) && socialNetworkArrayList.contains(b)){
                for(SocialNetwork s1 : socialNetworkArrayList){
                    if(s1.equals(b)){
                        s1.addFriend(a);
                        a.addFriend(s1);
                        socialNetworkArrayList.add(a);
                        break;
                    }
                }
            }

            else {
                socialNetworkArrayList.add(a);
                socialNetworkArrayList.add(b);
                a.addFriend(b);
                b.addFriend(a);
            }
        }

        n = sc.nextInt();
        for(i=0; i<n; i++){
            char aName = sc.next().charAt(0);
            char bName = sc.next().charAt(0);
            SocialNetwork a = new SocialNetwork(aName);
            SocialNetwork b = new SocialNetwork(bName);

            for(SocialNetwork s : socialNetworkArrayList){
                if(s.equals(a)){
                    s.removeFriend(b);
                    break;
                }
            }

            for(SocialNetwork s : socialNetworkArrayList){
                if(s.equals(b)){
                    s.removeFriend(a);
                    break;
                }
            }
        }

        char cName = sc.next().charAt(0);
        SocialNetwork c = new SocialNetwork(cName);
        HashSet<Character> whoCanSee = new HashSet<>();
        HashSet<SocialNetwork> friend = null;
        HashSet<SocialNetwork> friendOfFriend = null;
        for(SocialNetwork s : socialNetworkArrayList){
            if(s.equals(c)){
                friend = s.getFriend();
                break;
            }
        }
        for(SocialNetwork f : friend){
            whoCanSee.add(f.getName());
            friendOfFriend = f.getFriend();
            for(SocialNetwork fof : friendOfFriend){
                whoCanSee.add(fof.getName());
            }
        }
        whoCanSee.remove(cName);
        for(Character w : whoCanSee){
            System.out.println(w);
        }
    }
}
