import java.util.Scanner;

public class matrix {
    public static void main(String [] args){
        Scanner x=new Scanner(System.in);
        System.out.println("Enter no. of rows and columns of the first matrix: ");
        int r1=x.nextInt();
        int c1=x.nextInt();
        System.out.println("Enter no. of rows and columns of the second matrix: ");
        int r2=x.nextInt();
        int c2=x.nextInt();
        int a[][]=new int[r1][c1];
        int b[][]=new int[r2][c2];
        System.out.println("Enter 1st matrix elements: ");
        
        for(int i=0;i<r1;i++){
            for(int j=0;j<c1;j++){
                a[i][j]=x.nextInt();
            }
        }

        System.out.println("Enter 2nd matrix elements: ");
        
        for(int i=0;i<r2;i++){
            for(int j=0;j<c2;j++){
                b[i][j]=x.nextInt();
            }
        }

        System.out.println("Enter your choice \n1.Addition\n2.Multiplication:");
        int n=x.nextInt();
        x.close();
        switch(n){
            case 1:
                if(c1==r2){
                    multiply(r1, c1, r2, c2, a, b);}
                else{
                    System.out.println("Matrix multiplication cannot be done");
                }
            case 2:
                if(r1==r2 && c1==c2){addition(r1, r2, c1, c2, a, b);}
        }
    }
    static void addition(int r1, int r2, int c1, int c2, int a[][], int b[][]){
        int mat[][]=new int[r1][c1];
        for(int i=0;i<r1;i++){
            for(int j=0;j<c1;j++){
                mat[i][j]=a[i][j]+b[i][j];
            }
        }

        System.out.println("Printing Matrix elements: ");

        for(int i=0;i<r1;i++){
            for(int j=0;j<c1;j++){
                System.out.print(mat[i][j]+" ");
            }
            System.out.println();
        }
    }
    static void multiply(int r1, int c1, int r2, int c2, int a[][], int b[][]){
        int i, j, k;
        int mat[][]=new int[r1][c2];
        
        for(i=0;i<r1;i++){
            for(j=0;j<c2;j++){
                for(k=0;k<r2;k++){
                    mat[i][j]=a[i][k]*b[k][j];
               }
            }
        }
        System.out.println("Printing Matrix elements: ");
        
        for(i=0;i<r1;i++){
            for(j=0;j<c2;j++){
                System.out.print(mat[i][j]+" ");
            }
            System.out.println();
        }
    }
}