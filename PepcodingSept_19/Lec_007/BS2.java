import java.util.Scanner;
public class BS2
{
    public static Scanner sch=new Scanner(System.in);
    public static int BS(int[] arr,int data)
    {
        int li=0;
        int ri=arr.length-1;
        if(arr[ri]<data)
        return arr[ri];
        if(arr[li]>data)
        return arr[li];
        while(li<=ri)
         {
             int mid=(li+ri)/2;
             if(arr[mid]==data)
             {
                 return mid;
             }
             else if (arr[mid]<data)
             {
                 li=mid+1;
             }
             else 
             ri=mid-1;
         }
         if(arr[li]<=arr[ri])
         return arr[li];
         else
         return arr[ri];

    }
    public static void main(String[] args)
    {
        int[] arr={-2,-1,0,2,2,2,2,2,2,2,4,6,8,7,8,9};
        System.out.println("Enter the data:");
        int data=sch.nextInt();
        System.out.println(BS(arr,data));

    }
}