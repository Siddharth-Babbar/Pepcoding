import java.util.Stack;
public class StackQueue
{
            public static void main(String[] args)
         {
            int[] arr1={9,1,7,3,11,-2,25,20,2,-4};
            int[] arr2={4,5,2,25};
            int[] arr3={4,1,2,5,25};
            // nextGreaterElementRight(arr3);
            // nextGreaterElementLeft(arr3);
            // nextLesserElementRight(arr3);
            nextLesserElementLeft(arr3);

         }
         public static void nextGreaterElementRight(int[] arr)
         {
            Stack<Integer> st=new Stack<>();

            for(int i=0;i<arr.length;i++)
             {
                 if(st.size()==0)
                  {
                      st.push(arr[i]);
                      continue;
                  }
                 while(st.size()!=0 && arr[i]>st.peek())
                  {
                      System.out.println(st.pop()+":->"+arr[i]);
                  }
                 st.push(arr[i]);
             }
            while(st.size()!=0)
             {
                 System.out.println(st.pop()+":-> -1");
             }
         }
         public static void nextGreaterElementLeft(int[] arr)
         {
            Stack<Integer> st=new Stack<>();

            for(int i=arr.length-1;i>=0;i--)
             {
                 if(st.size()==0)
                  {
                      st.push(arr[i]);
                      continue;
                  }
                 while(st.size()!=0 && arr[i]>st.peek())
                  {
                      System.out.println(st.pop()+":->"+arr[i]);
                  }
                 st.push(arr[i]);
             }
            while(st.size()!=0)
             {
                 System.out.println(st.pop()+":-> -1");
             }
         }
         public static void nextLesserElementRight(int[] arr)
         {
            Stack<Integer> st=new Stack<>();

            for(int i=0;i<arr.length;i++)
             {
                 if(st.size()==0)
                  {
                      st.push(arr[i]);
                      continue;
                  }
                 while(st.size()!=0 && arr[i]<st.peek())
                  {
                      System.out.println(st.pop()+":->"+arr[i]);
                  }
                 st.push(arr[i]);
             }
            while(st.size()!=0)
             {
                 System.out.println(st.pop()+":-> -1");
             }
         }
         public static void nextLesserElementLeft(int[] arr)
         {
            Stack<Integer> st=new Stack<>();

            for(int i=arr.length-1;i>=0;i--)
             {
                 if(st.size()==0)
                  {
                      st.push(arr[i]);
                      continue;
                  }
                 while(st.size()!=0 && arr[i]<st.peek())
                  {
                      System.out.println(st.pop()+":->"+arr[i]);
                  }
                 st.push(arr[i]);
             }
            while(st.size()!=0)
             {
                 System.out.println(st.pop()+":-> -1");
             }
         }
        
}