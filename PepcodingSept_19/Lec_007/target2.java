import java.util.Scanner;

public class target2
{
    public static Scanner sch=new Scanner(System.in);
    public static void main(String[] args)
    {
        int[] arr={1,2,3,4,10,12,14,15};
        System.out.println("Enter the sum:");
        int sum=sch.nextInt();
        Targetsum(arr,sum);

    }
    public static void targetsum1(int[] arr,int sum,int fi,int li,int ri)
    {
        while(li<ri)
         {
             int data=arr[li]+arr[ri];
             if(data==sum)
              {
                  System.out.print("("+arr[fi]+","+arr[li]+","+arr[ri]+"),");
                  li++;
                  ri--;
              }
            else if(data<sum)
            li++;
            else 
            ri--;
         }
    }
    public static void Targetsum(int[] arr,int sum)
    {
        int fi=0;
        int ri=arr.length-1;
        while(fi<ri)
        {
          targetsum1(arr,sum-arr[fi],fi,fi+1,ri);
          fi++;
        }
    }
}