import java.util.Stack;
class BST2
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
    public static int minInTree(node root)
    {
        if(root==null)
         {
             return Integer.MAX_VALUE;
         }
        node rnode=root;
        while(rnode.left!=null)
         {
             rnode=rnode.left;
         }
        return rnode.data;
    }
    public static int maxInTree(node root)
    {
        if(root==null)
         {
             return Integer.MIN_VALUE;

         }
        node rnode=root;
        while(rnode.right!=null)
         {
            rnode=rnode.right;   
         }
        return rnode.data;
    }
    public static node removeData(node Node,int data)
    {
        if(Node== null)
         {
             return null;
         }
        if(Node.data==data)
         {
             if(Node.left==null|| Node.right==null)
              {
                  return Node.left==null?Node.right:Node.left;
              }
              int maxNode=maxInTree(Node.left);
              Node.data=maxNode;
              Node.left=removeData(Node.left,maxNode);
         }
        else if(data<Node.data)
         {
             Node.left=removeData(Node.left,data);
         }
        else
         {
             Node.right=removeData(Node.right,data);
         }
        return Node;
    }
    // public static node rightMostOfNextleft(node leftNode, node curr) {
    //     while (leftNode.right != null && leftNode.right != curr) {
    //         leftNode = leftNode.right;
    //     }
    //     return leftNode;
    // }

    // public static void morrisInorder(node Node) {
    //     node curr = Node;
    //     while (curr != null) {
    //         node nextLeft = curr.left;
    //         if (nextLeft == null) {
    //             System.out.print(curr.data + " ");
    //             curr = curr.right;
    //         } else {

    //             node rightMost = rightMostOfNextleft(nextLeft, curr);
    //             if (rightMost.right == null) {
    //                 rightMost.right = curr; // create thread.
    //                 curr = curr.left;
    //             } else {
    //                 System.out.print(curr.data + " ");
    //                 rightMost.right = null; // break thread.
    //                 curr = curr.right;
    //             }
    //         }

    //     }

    // }
    public static node rightMostOfNextLeft(node leftNode,node curr)
    {
        while(leftNode.right !=null && leftNode.right !=curr)
         {
             leftNode = leftNode.right;
         }
        return leftNode;
    }
    public static void morrisInorder(node Node)
    {
        node curr=Node;
        while(curr!=null)
         {
             node nextLeft=curr.left;
             if(nextLeft==null)
              {
                  System.out.print(curr.data+" ");
                  curr=curr.right;
              }
             else
              {
                  node Rightmost=rightMostOfNextLeft(nextLeft,curr);
                  if(Rightmost.right==null)
                   {
                       Rightmost.right=curr;
                       curr=curr.left;
                   }
                   else
                    {
                        System.out.print(curr.data+" ");
                        Rightmost.right=null;
                        curr=curr.right;
                    }
              }
         }
    }
    public static void morrisPreorder(node Node)
    {
        node curr=Node;
        while(curr!=null)
         {
             node nextLeft=curr.left;
             if(nextLeft==null)
              {
                  System.out.print(curr.data+" ");
                  curr=curr.right;
              }
              else
               {
                   node Rightmost=rightMostOfNextLeft(nextLeft,curr);
                   if(Rightmost.right==null)
                    {
                        System.out.print(curr.data+" ");
                        Rightmost.right=curr;
                        curr=curr.left;
                    }  
                   else
                    {
                        Rightmost.right=null;
                        curr=curr.right;
                    }
               }
         }
    }
    public static class Tpair
    {
        node Node=null;
        boolean SD=false;
        boolean LD=false;
        boolean RD=false;
        public Tpair(node Node)
         {
             this.Node=Node;
         }
    }
    public static void preOrder(node Node)
    {
        Stack<Tpair> st=new Stack<Tpair>();
        st.add(new Tpair(Node));
        while(st.size()!=0)
         {
             Tpair rt=st.peek();
             if(!rt.SD)
              {
                rt.SD=true;
                System.out.print(rt.Node.data+" ");
              }
             else if(!rt.LD)
              {
                rt.LD=true;
                if(rt.Node.left!=null)
                 {
                  st.add(new Tpair(rt.Node.left));
                 }
              }
             else if(!rt.RD)
              {
                rt.RD=true;
                if(rt.Node.right!=null)
                 {
                   st.add(new Tpair(rt.Node.right));
                 }
              }
             else
              {
                st.pop();
              }
         }
    }
    public static void inOrder(node Node)
    {
        Stack<Tpair> st=new Stack<Tpair>();
        st.add(new Tpair(Node));
        while(st.size()!=0)
         {
             Tpair rt=st.peek();
             if(!rt.SD)
              {
                rt.SD=true;
              }
             else if(!rt.LD)
              {
                rt.LD=true;
                if(rt.Node.left!=null)
                 {
                  st.add(new Tpair(rt.Node.left));
                 }
              }
             else if(!rt.RD)
              {
                rt.RD=true;
                System.out.print(rt.Node.data+" ");
                if(rt.Node.right!=null)
                 {
                   st.add(new Tpair(rt.Node.right));
                 }
              }
             else
              {
                st.pop();
              }
         }
    }
    public static void postOrder(node Node)
    {
        Stack<Tpair> st=new Stack<Tpair>();
        st.add(new Tpair(Node));
        while(st.size()!=0)
         {
             Tpair rt=st.peek();
             if(!rt.SD)
              {
                rt.SD=true;
              }
             else if(!rt.LD)
              {
                rt.LD=true;
                if(rt.Node.left!=null)
                 {
                  st.add(new Tpair(rt.Node.left));
                 }
              }
             else if(!rt.RD)
              {
                rt.RD=true;
                if(rt.Node.right!=null)
                 {
                   st.add(new Tpair(rt.Node.right));
                 }
              }
             else
              {
                System.out.print(rt.Node.data+" ");
                st.pop();
              }
         }
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
        // node root=removeData(rootNode,10);
        // display(root);
        //morrisInorder(rootNode);
        System.out.println();
        morrisPreorder(rootNode); 
        System.out.print("Preorder:");
        preOrder(rootNode);
        System.out.println();
        System.out.print("Inorder:");
        inOrder(rootNode);
        System.out.println();
        System.out.print("Postorder:");
        postOrder(rootNode);      
    }
    public static void main(String[] args)
    {
        BST();
    }

}