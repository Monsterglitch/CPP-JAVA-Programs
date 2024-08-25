package JavaPrograms;
import java.util.Scanner;

class square{
    int side;
    square(int j){
        side = j;
    }
    void calculate(){
        int area = side*side;
        System.out.println("Area of circle: "+area);
    }
}
class circle{
    float radius;
    circle (float i){
        radius = i;
    }
    void calculate(){
        double area;
        area = 3.14 * radius * radius;
        System.out.println("Area of circle: "+area);
    }
}
class rectangle{
    int a, b;
    rectangle(int i, int j){
        a = i;b = j;
    }
    void calculate(){
        int area = a * b;
        System.out.println("Area of rectangle: "+area);
    }
}
public class Area {
    static int a, b, side; static float radius;
    public static void main(String[] args){
        Scanner x = new Scanner(System.in);
        System.out.println("Enter length, breadth, radius and side values: ");
        a = x.nextInt();
        b = x.nextInt();
        radius = x.nextFloat();
        side = x.nextInt();
        x.close();
        square s = new square(side);s.calculate();
        rectangle  r = new rectangle(a,b);r.calculate();
        circle c = new circle(radius);c.calculate();
    }
}