import java.util.Scanner;

public class noOfSetBit_1
{
    public static Scanner sch=new Scanner(System.in);
    public static void main(String[] args)
    {
        int a=sch.nextInt();
        noOfSetBits_1(a);
        Optimised(a);
    }
    public static void noOfSetBits_1(int a)
    {
        int count=0;
        while(a!=0)
         {
           if((a&1)!=0)
           count++;
           a>>>=1;
         }
        System.out.println(count);
    }
    public static void Optimised(int a)
    {
        int count=0;
        while(a!=0)
         {
           a&=(a-1);
           count++;
         }
        System.out.println(count);         
    }
}