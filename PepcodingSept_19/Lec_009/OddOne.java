import java.util.Scanner;

public class OddOne
{
    public static Scanner sch=new Scanner(System.in);
    public static void main(String[] args)
    {

       // int n=sch.nextInt();
        int k=sch.nextInt();
        int[] arr={1,1,2,2,3,4,4,5,5};
       // input(arr);
        odd(arr);
        uniqueFork(arr,k);

    }
    public static void input(int[] arr)
    {
        for(int i=0;i<arr.length;i++)
        arr[i]=sch.nextInt();
    }
    public static void odd(int[] arr)
    {
        int ans=0;
        for(int i=0;i<arr.length;i++)
         {
             ans^=arr[i];
         }
        System.out.println(ans);
    }
    public static void uniqueFork(int[] arr,int k)
    {
        int[] bit=new int[32];
        for(int ele:arr)
        {
          for(int i=0;i<32;i++)
          {
              int mask=(1<<i);
              if((ele&mask)!=0)
              bit[i]++;
          }
        }
        int ans=0;
        for(int i=0;i<32;i++)
        {
            if(bit[i]%k==1)
            {
                int carr=(1<<i);
                ans|=carr;
            }   
        }
        System.out.println(ans);
    }

}