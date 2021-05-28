import java.util.Scanner;
public class Factorial
{
 public static Scanner scn=new Scanner(System.in);

 public static void main(String[] args)
 {
     System.out.print("Enter n for Factorial :");
     int n=scn.nextInt();
     System.out.println(Facto(n));

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