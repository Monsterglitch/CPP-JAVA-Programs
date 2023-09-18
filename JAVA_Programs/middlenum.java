import java.util.Scanner;

public class middlenum {
    public static void main(String [] args){
        int val, val1, count=0;
        Scanner x = new Scanner(System.in);
        System.out.println("Enter a value: ");
        val = x.nextInt();
        x.close();
        val1 = Math.abs(val);
        for(int i=val1;i!=0;i=i/10){
            count++;
            if(count%2==1){
                for(i=1;i<=count/2;i++){
                    val1=val1/10;
                }
                int mid=val1%10;
                System.out.println("Middle Number is "+mid);
            }
            else{
                for(i=1;i<count/2;i++){
                    val1=val1/10;
                }
                int mid=val1%100;
                System.out.println("Middle Number is "+mid);
            }
        }
    }
}
