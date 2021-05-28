public class queue
{
    protected int[] que;
    protected int head=0;
    protected int tail=-1;
    protected int size=0;

    public queue()
    {
        this.que=new int[10];
    }
    public queue(int size)
    {
        this.que=new int[size];
    }
    public queue(int[] arr)
    {
        this.que=new int[2*arr.length];
        for(int i=0;i<arr.length;i++)
         {
            this.que[i]=arr[i];
            this.size++;
         }
        this.tail=arr.length-1;
    }
    public int size()
    {
        return this.size;
    }
    public boolean isEmpty()
    {
        return this.size==0;
    }
    public int front()
    {
        if(this.size==0)
         {
            System.out.print("QueueIsEmpty ");
            return -1;
         }
        return this.que[this.head];
    }
    public void push(int data)
    {
        if(this.size==que.length)
         {
             System.out.println("QueueIsFull ");
             return;
         }
        this.tail=(this.tail+1)%que.length;
        this.que[this.tail]=data;
        this.size++;
    }
    public int pop()
    {
        if(this.size==0)
         {
             System.out.print("QueueIsEmpty ");
             return -1;
         }
        int temp=this.que[this.head];
        this.que[this.head]=0;
        this.head=(this.head+1)%que.length;
        this.size--;
        return temp;

    }
    public void display()
    {
        for(int i=0;i<this.size;i++)
         {
             int val=this.que[(this.head+i)%que.length];
             System.out.print(val+" ");
         }
        System.out.println();
    }


}