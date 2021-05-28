import java.util.ArrayList;
public class heap
{
    private ArrayList<Integer> arr;
    public heap()
    {
         this.arr=new ArrayList<>();
    }
    public heap(int[] ar)
    {
        this.arr=new ArrayList<>();
        for(int ele:ar)
         {
             this.arr.add(ele);
         }
        for(int i=arr.size()-1;i>=0;i--)
         {
             downheapify(i);
         }
    }
    //API===========================================
    public void display()
    {
        for(int i=0;i<this.arr.size();i++)
          {
              System.out.println(this.arr.get(i));
          }
    }
    public int height(int par)
    {
        if(par>=arr.size())
         {
             return -1;
         }
        int lh=height(2*par +1);
        int rh=height(2*par +2);

        return Math.max(lh,rh)+1;
    }
    public void push_(int data)
    {
        this.arr.add(data);
        upheapify(arr.size()-1);
    }
    public void pop()
    {
        swap(0,arr.size()-1);
        arr.remove(arr.size()-1);
        downheapify(0);
    }
    public int top()
    {
        return arr.get(0);
    }
    public void update(int data,int idx)
    {
        arr.set(idx,data);
        upheapify(idx);
        downheapify(idx);
    }
    //util=======================================================
    public void upheapify(int cidx)
    {
       int pidx=(cidx-1)/2;
       if(pidx>=0 && arr.get(pidx)<arr.get(cidx))
        {
            swap(pidx,cidx);
            upheapify(pidx);
        }     
    }
    public void downheapify(int idx)
    {
          int maxidx=idx;
          int lchild=2*idx + 1;
          int rchild=2*idx + 2;
          if(lchild<arr.size() && arr.get(maxidx)<arr.get(lchild) )
           {
               maxidx=lchild;
           }
          if(rchild<arr.size() && arr.get(maxidx)<arr.get(rchild))
           {
               maxidx=rchild;
           }
          if(maxidx!= idx)
           {
             swap(maxidx,idx);
             downheapify(maxidx);
           }
    }
     public void swap(int i,int j)
    {
          int val1=arr.get(i);
          int val2=arr.get(j);

          arr.set(i,val2);
          arr.set(j,val1);
    }
}