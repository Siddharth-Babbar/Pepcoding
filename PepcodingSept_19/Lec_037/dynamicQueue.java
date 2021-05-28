public class dynamicQueue extends queue
{
    public dynamicQueue()
    {
        super();
    }
    public dynamicQueue(int size)
    {
        super(size);
    }
    public dynamicQueue(int[] arr)
    {
        super(arr);
    }
    @Override
    public void push(int data)
    {
        if(this.size==que.length)
         {
             int[] temp=this.que;
             this.que=new int[2*temp.length];
             for(int i=0;i<temp.length;i++)
              {
                  int val=temp[(this.head+i)%temp.length];
                  this.que[i]=val;
              }
             this.head=0;
             this.tail=temp.length-1;
         }
        super.push(data);
    }
}