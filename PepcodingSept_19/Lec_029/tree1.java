public class tree1
{
    public static class node
    {
        int data=0;
        node left=null;
        node right=null;
        public node()
         {

         }
        public node(int data)
         {
             this.data=data;
         }
        public node(int data,node left,node right)
         {
             this.data=data;
             this.left=left;
             this.right=right;
         }
        // @Override
        // public String toString()
        //  {
        //      String str="";
        //      str+=left.data+"";
        //  }
    }
    public static int idx=0;
    public static node constructTree(int [] arr)
     {
        if(idx==arr.length || arr[idx]==-1)
         {
             idx++;
             return null;
         }
        node Node=new node(arr[idx]);
        idx++;
        Node.left=constructTree(arr);
        Node.right=constructTree(arr);

        return Node;

     }
    public static void  display(node Node)
     {
        if(Node==null)
         {
             return;
         }
        System.out.print(Node.left!=null?Node.left.data:".");
        System.out.print(":->"+Node.data+"<-:");
        System.out.println(Node.right!=null?Node.right.data:".");

        display(Node.left);
        display(Node.right);

     }
    public static int maximum(node Node)
    {
        if(Node==null)
         {
             return Integer.MIN_VALUE;
         }
        int omax=Node.data;
        int lmax= maximum(Node.left);
        int rmax=maximum(Node.right);
        return Math.max(omax,Math.max(lmax,rmax));
    }
    public static int size(node Node)
    {
        if(Node==null)
         {
             return 0;
         }
        int lsize=size(Node.left);
        int rsize=size(Node.right);
        return lsize+rsize+1;
    }
    public static int height(node Node)
    {
        if(Node==null)
         {
             return -1;
         }
        int lh=height(Node.left);
        int rh=height(Node.right);
        return Math.max(lh,rh)+1;
    }
    public static boolean find(node Node,int data)
    {
        if(Node==null)
         {
             return false;
         }
        if(Node.data==data)
         {
             return true;
         }
        return find(Node.left,data)||find(Node.right,data);
    } 
    public static void solve()
     {
         int[] arr={10,20,30,40,-1,-1,50,-1,-1,60,-1,70,-1,-1,80,90,100,120,-1,-1,130,-1,-1,110,-1,-1,140,-1,-1};
         node rootNode=constructTree(arr);
         display(rootNode);
        //  System.out.println(maximum(rootNode));
        //  System.out.println(size(rootNode));
        //  System.out.println(height(rootNode));
        //  System.out.println(find(rootNode,150));
        //  System.out.println(rootNode);
     }
    public static void main(String[] args)
     {
         solve();
     }
}