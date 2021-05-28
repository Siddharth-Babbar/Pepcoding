import java.util.Scanner;
public class Fibonaci
{
    public static Scanner sch=new Scanner(System.in);
    public static void main(String[] args)
    {
      System.out.println("Enter the value of n");
      int n=sch.nextInt();
      fibbo(n);
    }
    public static void fibbo(int n)
    {   
        
        if(n<=1)
         {
                System.out.print(n);
         } 
              
        int a=0;
        int b=1;
        System.out.print("0 ");
        for(int i=0;i<n-1;i++ )
         {
           int sum=a+b;
           System.out.print(b+" ");
           a=b;
           b=sum;
         }
    }
}