import java.util.Scanner;
public class bulb
{
    public static Scanner sch=new Scanner(System.in);
    public static void main(String[] args)
    {
       System.out.println("Enter number of bulb");
       int n=sch.nextInt();
       for(int i=1;i*i<=n;i++)
        {
          System.out.println(i*i);
        } 
    } 
}