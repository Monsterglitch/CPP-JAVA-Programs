import java.util.Scanner;

public class palindrome{
    static int var;
    public static void main(String [] args){
        Scanner x = new Scanner(System.in); 
        System.out.println("Enter a number: ");
        var = x.nextInt();
        x.close();
        palindrome y = new palindrome();
        y.calculation(var);
    }
    public void calculation(int a){
        int temp = a;
        int remainder, sum = 0;
        while(a>0){
            remainder = a % 10;
            sum = (sum * 10)+remainder;
            a=a/10;
        }
        if(temp==sum){System.out.println("Entered number is a palindrome");}
        else{System.out.println("Entered number is not a palindrome");}
    }
}