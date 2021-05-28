public class stack
{
    protected int[] st;
    protected int tos=-1;

    public stack()
    {
        this.st=new int[10];
    }
    public stack(int size)
    {
        this.st=new int[size];
    }
    public stack(int[] arr)
    {
        this.st=new int[2*arr.length];
        for(int i=0;i<arr.length;i++)
         {
             st[i]=arr[i];
         }
        tos=arr.length-1;
    }
    public int size()
    {
        return tos+1;
    }
    public boolean isEmpty()
    {
        return tos==-1;
    }
    public void push(int data)
    {
       if(tos+1== st.length)
        {
            System.out.println("StackOverFlow "+ tos);
            return;
        }
       st[++tos]=data;
    }
    public int top()
    {
        if(tos==-1)
         {
             System.out.println("StackIsEmpty");
             return tos;
         }
        return st[tos];
    }
    public int pop()
    {
        if(tos==-1)
         {
             System.out.println("StackIsEmpty");
             return tos;
         }
        int r=st[tos];
        st[tos]=0;
        tos--;
        return r;
    }
    public void display()
    {
        for(int i=tos;i>=0;i--)
         {
             System.out.print(st[i]+" ");
         }
    }
    public void fun1()
    {
        System.out.println("hi!");
    }
    public void fun()
    {
        System.out.println("hi Stack");
    }
}