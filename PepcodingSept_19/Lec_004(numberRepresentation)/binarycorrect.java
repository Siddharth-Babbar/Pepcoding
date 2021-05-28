import java.util.Scanner;
public class binarycorrect
{
    public static Scanner sch=new Scanner(System.in);
    public static void main(String[] args)
    {
        System.out.println("Enter the decimal number");
        int n=sch.nextInt();
        System.out.println(DtoB(n));

    }
    public static int DtoB(int n)
    {
        int res=0;
        int pow=1;
        int rem;
        while(n!=0)
         {
           rem=n%2;
           n/=2;
           res=rem*pow + res;
           pow*=10;
         }
        return res;
    }
}