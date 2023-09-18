import java.util.Scanner;

//Inheritance
class A{
    int i,j;
    Scanner scn = new Scanner(System.in);
    void getdata(){
        System.out.println("Enter the value of i & j: ");
        i=scn.nextInt();
        j=scn.nextInt();
    }
    void display(){
        System.out.println("i= "+i+", j= "+j);
    }
}    
class B extends A{
    private int k=10;
    void show(){
        super.display();
        System.out.println("k= "+k);
    }
}
class Main {
    public static void main(String[] args){
        B Subobj=new B();
        Subobj.getdata();
        //Subobj.display();
        Subobj.show();
    }
}