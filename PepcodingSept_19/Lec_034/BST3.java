import java.util.LinkedList;
import java.util.ArrayList;
class BST3
{
    public static class Node
    {
        int data=0;
        Node left=null;
        Node right=null;
        int ht=-1;
        int bal=0;
        public Node()
        {

        }
        public Node(int data)
        {
            this.data=data;
        }
        public Node(int data,Node left,Node right) 
        {
            this.data=data;
            this.left=left;
            this.right=right;
        }
    }
    public static Node ll(Node x)
    {
        Node y=x.left;
        Node yright=y.right;

        y.right=x;
        x.left=yright;

        updateHeightAndBalance(x);
        updateHeightAndBalance(y);

        return y;
    }
    public static Node rr(Node x)
    {
        Node y=x.right;
        Node yleft=y.left;

        y.left=x;
        x.right=yleft;

        updateHeightAndBalance(x);
        updateHeightAndBalance(y);
        
        return y;
    }
    public static void updateHeightAndBalance(Node node)
    {
        int lh=-1;
        int rh=-1;
        if(node.left!=null)
         {
             lh=node.left.ht;
         }
        if(node.right!=null)
         {
             rh=node.right.ht;
         }
        node.ht=Math.max(lh,rh)+1;
        node.bal=lh-rh;
    }
    public static Node rotation(Node root)
    {
        updateHeightAndBalance(root);
        if(root.bal==2)
         {
             if(root.left.bal==1)
              {
                  return ll(root);
              }
             else
              {
                  root.left=rr(root.left);
                  return ll(root);
              }
         }
        else if(root.bal==-2)
         {
             if(root.right.bal==-1)
              {
                  return rr(root);
              }
             else
              {
                  root.right=ll(root.right);
                  return rr(root);
              }
         }
         else
         {
             return root;
         }

    }
    public static Node addData(Node node,int data)
    {
        if(node==null)
         {
             return new Node(data);
         }
        if(data<node.data)
         {
             node.left=addData(node.left,data);
         }
        else
         {
             node.right=addData(node.right,data);
         }
        node=rotation(node);
        return node;
    }
  
    public static int maxInTree(Node root)
    {
        if(root==null)
         {
             return Integer.MIN_VALUE;

         }
        Node rnode=root;
        while(rnode.right!=null)
         {
            rnode=rnode.right;   
         }
        return rnode.data;
    }
    public static Node removeData(Node node,int data)
    {
        if(node== null)
         {
             return null;
         }
        if(node.data==data)
         {
             if(node.left==null|| node.right==null)
              {
                  return node.left==null?node.right:node.left;
              }
              int maxNode=maxInTree(node.left);
              node.data=maxNode;
              node.left=removeData(node.left,maxNode);
         }
        else if(data<node.data)
         {
             node.left=removeData(node.left,data);
         }
        else
         {
             node.right=removeData(node.right,data);
         }
        node=rotation(node);
        return node;
    }
    public static void  display(Node node)
    {
        if(node==null)
         {
             return;
         }
        System.out.print(node.left!=null?node.left.data:".");
        System.out.print(":->"+node.data+"<-:");
        System.out.println(node.right!=null?node.right.data:".");

        display(node.left);
        display(node.right);

    }
    static int leftmost=-1;
    static int rightmost=-1;
    public static void width(Node node,int level)
    {
        if(node==null)
         {
             return;
         }
        leftmost=Math.min(leftmost,level);
        rightmost=Math.max(rightmost,level);
        width(node.left,level-1);
        width(node.right,level+1);
    }
    // public static void verticalOrder(Node node)
    // {
    //     LinkedList<Node> que1=new LinkedList<Node>();
    //     LinkedList<Integer> que2=new LinkedList<Integer>();

    //     width(node,0);
    //     ArrayList<Integer>[] list=new ArrayList[rightmost-leftmost+1];
    //     int[] sum=new int[rightmost-leftmost+1];

    //     que1.add(node);
    //     que2.add(-leftmost);
    //     while(que1.size()!=0)
    //      {
    //          int size=que1.size();
    //          while(size-- >0)
    //           {
    //               Node rn=que1.removeFirst();
    //               int rd=que2.removeFirst();
    //               System.out.println(rd);
    //               list[rd]=new ArrayList<Integer>();
    //               list[rd].add(rn.data);
    //               sum[rd]+=rn.data;
    //               if(node.left!=null)
    //                {
    //                    que1.addLast(node.left);
    //                    que2.addLast(rd-1);
    //                }
    //               if(node.right!=null)
    //                {
    //                    que1.addLast(node.right);
    //                    que2.addLast(rd+1);
    //                }
    //           }
    //      }
    //     System.out.println();
    //     for(int i=0;i<(rightmost-leftmost+1);i++)
    //      {
    //         System.out.print(i+":->"+list[i]);
    //         System.out.println();

    //      }

    // }
    public static void AVL()
    {
        Node root=null;
        for(int i=1;i<=6;i++)
         {
           root=addData(root,i*10);  
         }
        // root=addData(root,7);
        // root=addData(root,13);
        // root=addData(root,1);
        // root=addData(root,9);
        // root=addData(root,15);
        // root=addData(root,10);
        // root=addData(root,20);
        // root=addData(root,2);
        // root=rotation(root);
        //root=addData(root,60);
        //root=addData(root,70);
        display(root);
        //root=removeData(root,70);
        //root=removeData(root,60);
        //System.out.println();
        //display(root);
        //verticalOrder(root);
        
    }
    public static void solve()
    {
        AVL();
    }
    public static void main(String[] args)
    {
        solve();
    }
    

}