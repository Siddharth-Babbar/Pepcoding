import java.util.Scanner;


public class BSub_lb
{
    public static Scanner sch=new Scanner(System.in);
    public static void main(String[] args)
    {
        int[] arr = {1,2,2,2,2,2,2,2,2,2,3,4,5,6,7,8,9};
        System.out.println("Enter the data:");
        int data=sch.nextInt();
        System.out.println("Lower bound:"+BSlow(arr,data));
        System.out.println("Upper bound:"+BSup(arr,data));
    }
   
    public static int BSlow(int[] arr, int data )
    {
      int li=0;
      int ri=arr.length-1;
      while(li<=ri)
       {
         int mid=(li+ri)/2;
         if(arr[mid]==data)
         {
             if(mid-1>0&& arr[mid]==arr[mid-1])
             ri=mid-1;
             else
             return mid;

         }
        
         else if(arr[mid]<data)
         li=mid+1;
         else 
         ri=mid-1;
       }
       return -1;
    }
    public static int BSup(int[] arr, int data )
    {
      int li=0;
      int ri=arr.length-1;
      while(li<=ri)
       {
         int mid=(li+ri)/2;
         if(arr[mid]==data)
         {
             if(mid+1<arr.length && arr[mid]==arr[mid+1])
             li=mid + 1;
             else
             return mid;

         }
        
         else if(arr[mid]<data)
         li=mid+1;
         else 
         ri=mid-1;
       }
       return -1;
    }
}

