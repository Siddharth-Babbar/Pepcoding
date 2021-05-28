import java.util.Scanner;
public class ncr
{
 public static Scanner scn=new Scanner(System.in);

 public static void main(String[] args)
 {
     System.out.print("Enter n for Factorial :");
     int n=scn.nextInt();
     System.out.println(Facto(n));
     nc_r();

 }
 public static void nc_r()
  {
    System.out.println("Enter N:");
    int n=scn.nextInt();
    System.out.println("Enter R:");
    int r=scn.nextInt();
    System.out.println((Facto(n))/(Facto(n-r)*Facto(r)));

  }
 public static int Facto(int n)
 {
     int ans=1;
     for(int i=1;i<=n;i++)
      {
         ans*=i;
      }
      return ans;
 }
}