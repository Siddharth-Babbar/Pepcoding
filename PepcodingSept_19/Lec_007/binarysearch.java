import java.util.Scanner;


public class binarysearch
{
    public static Scanner sch=new Scanner(System.in);
    public static void main(String[] args)
    {
        int[] arr = {1,2,3,4,5,6,7,8,9};
        System.out.println("Enter the data:");
        int data=sch.nextInt();
        System.out.println(BS(arr,data));
    }
   
    public static int BS(int[] arr, int data )
    {
      int li=0;
      int ri=arr.length-1;
      while(li<=ri)
       {
         int mid=(li+ri)/2;
         if(arr[mid]==data)
         return mid;
         else if(arr[mid]<data)
         li=mid+1;
         else 
         ri=mid-1;
       }
       return -1;
    }
}