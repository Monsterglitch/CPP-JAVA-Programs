import java.util.Scanner;

interface a{
    void Studentdetails();
}
public class Interface implements a{
    Scanner x= new Scanner(System.in);
    String name;int rollno;
    public void Studentdetails(){
        System.out.println("Enter rollno and name of the student: ");
        rollno = x.nextInt();
        name = x.nextLine();
        System.out.println("Rollno: "+ rollno +"\nName: "+ name);
    }
    public static void main(String [] args){
        Interface y = new Interface();
        y.Studentdetails();
    }
}