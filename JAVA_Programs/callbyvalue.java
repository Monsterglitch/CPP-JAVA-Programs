import java.util.Scanner;

public class callbyvalue {
    static int l, m;
    static Scanner a = new Scanner(System.in);
    public static void main(String[] args){
        System.out.println("Enter a value: ");
        l=a.nextInt();
        System.out.println("Enter another value: ");
        m=a.nextInt();
        System.out.println("Entered values are...");
        System.out.println("x= "+l+", y= "+m);
        value z = new value(l, m);
        z.print();
        change(l, m);
    }
    public static void change(int f, int g){
        int temp;
        temp=g;
        g=f;
        f=temp;
        System.out.println("Entered values are...");
        System.out.println("x= "+f+", y= "+g);
    }
}
class value{
    int x, y;
    value(int a, int b){
        this.x = a;
        this.y = b;
    }
    void print(){
        System.out.println("Values are "+x+", "+y);
    }
}
