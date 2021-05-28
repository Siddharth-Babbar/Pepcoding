import java.util.Scanner;
public class prime 
{
    public static Scanner sch=new Scanner(System.in);
    public static void main(String[] args)
     {
         int n=sch.nextInt();
         System.out.println(isprime(n));
     }

    public static boolean isprime(int n)
     {
        
         for(int i=2;i*i<=n;i++)
         {
              if (n%i==0)
             return false;

          }
          return true;
     }
}