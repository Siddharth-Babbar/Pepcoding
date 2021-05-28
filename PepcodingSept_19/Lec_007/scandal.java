public class scandal
{
    public static void main(String[] args)
    {
        int[] arr={1,1,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10};
        System.out.println("The number of scandal which is missing is:"+ arr[oddpair(arr)]);

    }
    public static int oddpair(int[] arr)
    {
      int li=0;
      int ri=arr.length-1;
      int mid=0;
      while(li<ri)
       {
           mid=(li+ri)/2;
           if(mid%2==0)
            {
                if(arr[mid]==arr[mid+1])
                 {
                   li=mid+2;
                 }
                else
                ri=mid;
            }
            else
             {
                 if(arr[mid]==arr[mid-1])
                  {
                    li=mid+1;
                  }
                 else
                 ri=mid;
             }
       }
      return li;
    }
}