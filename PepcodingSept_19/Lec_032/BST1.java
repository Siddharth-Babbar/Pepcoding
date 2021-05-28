class BST1
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
        @Override
        public  String toString()
         {
           String str="";
           str+=left.data+":->";
           str+=data+"";
           str+="<-:"+right.data;
           return str;
         }
    }
    public static class allSol
    {
        int height=0;
        int size=0;
        boolean find=false;

        node succ=null;
        node pred=null;
        node prev=null;

        int ceil=Integer.MAX_VALUE;
        int floor=Integer.MAX_VALUE;
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
    public static node BSTCreate(int[] arr,int si,int ei)
    {
        if(si>ei)
         {
             return null;
         }
        int mid=si+(ei-si)/2;
        node Node=new node(arr[mid]);
        Node.left=BSTCreate(arr,si,mid-1);
        Node.right=BSTCreate(arr,mid+1,ei);
        return Node;
    }
    public static boolean find_01(node Node,int data)
    {
        if(Node==null)
         {
           return false;
         }
        if(data==Node.data)
         {
             return true;
         }
        else if(data<Node.data)
         {
             return find_01(Node.left,data);
         }
        else
         {
             return find_01(Node.right,data);
         }
        
    }
    public static boolean find_02(node Node,int data)
    {
        while(Node!=null)
         {
             if(data==Node.data)
              {
                  return true;
              }
             if(data<Node.data )
              {
                  Node=Node.left;
              }
             else
              {
                  Node=Node.right;
              }
         }
        return false;
    }
    public static node addData(node Node,int data)
    {
        if(Node==null)
         {
             return new node(data);
         }
        if(data<Node.data)
         {
             Node.left=addData(Node.left,data);
         }
        else
         {
             Node.right=addData(Node.right,data);
         }
        return Node;
    }
    public static void BST()
    {
        int[] arr=new int[10];
        for(int i=0;i<10;i++)
         {
             arr[i]=(i+1)*10;
         }
        node rootNode=BSTCreate(arr,0,arr.length-1); 
        display(rootNode);
        System.out.println(find_01(rootNode,20));
        System.out.println(find_02(rootNode,12000));
        node nrootNode=addData(rootNode,12000);
        display(nrootNode);
    }
    public static void main(String[] args)
    {
        BST();
    }

}