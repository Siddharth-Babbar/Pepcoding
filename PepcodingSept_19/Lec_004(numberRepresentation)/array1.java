import java.util.Scanner;
import java.util.Arrays;
public class array1
{
    public static Scanner sch=new Scanner(System.in);
    public static void main(String[] args)
    {
        System.out.println("Enter the size");
        int n=sch.nextInt();
        int[] arr=new int[n];
        input(arr);
        Arrays.sort(arr);
        output(arr);

    }
    public static void input(int[] arr)
    {
      for(int i=0;i<arr.length;i++)
       {
           arr[i]=sch.nextInt();
       }
    }
    public static void output(int[] arr)
    {
        for(int i=0;i<arr.length;i++)
         {
           System.out.println(arr[i]);
         }

    }
    
}