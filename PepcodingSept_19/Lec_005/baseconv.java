import java.util.Scanner;
public class baseconv
{
    public static Scanner sch=new Scanner(System.in);
    public static void main(String[] args)
    {
        System.out.print("Enter the number : ");
        int n=sch.nextInt();
        System.out.print("Enter base1 : ");
        int b1=sch.nextInt();
        System.out.print("Enter base2 : ");
        int b2=sch.nextInt();
        B1toD(n,b1,b2);

    }
    public static void B1toD(int n,int b1,int b2)
    {
        int res=0;
        int rem=0;
        int pow=1;
        while(n!=0)
         {
             rem=n%10;
             n/=10;
             res+=rem*pow;
             pow*=b1;
         }
         
        DtoB2(res,b2);
    }
    public static void DtoB2(int n,int b2)
    {
        int res=0;
        int rem=0;
        int pow=1;
        while(n!=0)
         {
            rem=n%b2;
            n/=b2;
            res+=rem*pow;
            pow*=10;
         } 
        System.out.println("The number : "+res);
    }
}