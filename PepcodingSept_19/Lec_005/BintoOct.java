import java.util.Scanner;
public class BintoOct
{
    public static Scanner sch=new Scanner(System.in);
  
    public static void main(String[] args)
     {
        System.out.print("Enter the number : ");
        int num=sch.nextInt();
        System.out.print("The number in Octal notation : " + bto(num));

     }
    public static int bto(int num)
    {
      int res=0;
      int rem=0;
      int pow=1;
      while(num!=0)
      {
        rem=btod(num%1000);
        num/=1000;

        res+=rem*pow;
        pow=10;

      }
      return res;
    }
    public static int btod(int num)
    {
       int res=0;
       int rem=0;
       int pow=1;
       while(num!=0)
        {
            rem=num%10;
            num/=10;
            res+=rem*pow;
            pow*=2;
        }
       return res;
    }
}