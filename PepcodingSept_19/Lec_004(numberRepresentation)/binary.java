import java.util.Scanner;
public class binary
{
    public static Scanner sch=new Scanner(System.in);
    public static void bin(int n)
    {
        int[] arr=new int[100];
        int j = 0;
          for(int i=0;n!=0;i++)
            { 
                arr[i]=n%2;
                n=n/2;
                j++;
            }
        display(arr,j);
    }
    public static void display(int[] arr,int j)
    {
        for(int i=j-1;i>=0;i--)
         {
             System.out.print(arr[i] + " ");
         }
    }
    public static void main(String[] args)
    {
        System.out.println("Enter the number");
        int n=sch.nextInt();
       
        bin(n);
 


    }
}