import java.util.Scanner;


public class BS3
{
    public static Scanner sch=new Scanner(System.in);
    public static void main(String[] args)
    {
        int[] arr={5,1,2,3,4,6,7,8,9};
        System.out.println("Enter the data:");
        int data=sch.nextInt();
        System.out.println(Bs3(arr,data));

    }
    public static int BS(int[] arr,int data,int li,int ri)
    {
        int mid=0;
        while(li<=ri)
         {
              mid=(li+ri)/2;
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
         return mid;
    }
    public static int Bs3(int[] arr,int data)
    {
      int li=0;
      int ri=arr.length-1;
      int mid=0;
      while(li<=ri)
      {
          mid=(li+ri)/2;
          if(arr[mid]-arr[li]>0 && arr[ri]-arr[mid]>0)
          {
              return BS(arr,data,li,ri);
          }
          else if (arr[mid]-arr[li]<0 && arr[ri]-arr[mid]>0)
          ri=mid-1 ;
          else 
          li=mid+1;
      }
      
      if(arr[0]<=data && arr[mid]<=data)
      {
          return BS(arr,data,0,mid);
         
      }
      else 
       return BS(arr,data,mid+1,arr.length-1);
    }
}