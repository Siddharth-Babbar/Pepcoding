public class dynamicStack extends stack
{
    public dynamicStack()
    { 
       super();
    }
    public dynamicStack(int size)
    {
        super(size);
    }
    public dynamicStack(int[] arr)
    {
        super(arr);
    }
    @Override
    public void push(int data)
     {
         if(this.tos+1==st.length)
          {
              int[] temp=st;
              st=new int[2*temp.length];
              for(int i=0;i<temp.length;i++)
               {
                   this.st[i]=temp[i];
               }
         
          }
         super.push(data);
     }
    public void fun()
    {
         System.out.println("hi dynamic stack");
    }
    public void fun2()
    {
        System.out.println("hi!!!");
    }
}