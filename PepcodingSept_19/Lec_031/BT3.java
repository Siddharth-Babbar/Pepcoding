import java.util.ArrayList;
public class BT3
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
    public static int diameter_01(node Node)
    {
        if(Node==null)
         {
             return 0;
         }
        int ld=diameter_01(Node.left);
        int rd=diameter_01(Node.right);

        int lh=height(Node.left);
        int rh=height(Node.right);

        return Math.max(Math.max(ld,rd),lh+rh+2);
    }
    public static int[] diameter_02(node Node)
    {
        if(Node==null)
         {
             return new int[] {0,-1};
         }
        int[] ld=diameter_02(Node.left);
        int[] rd=diameter_02(Node.right);
        int[] myans=new int[2];
        myans[0]=Math.max(Math.max(ld[0],rd[0]),ld[1]+rd[1]+2);
        myans[1]=Math.max(ld[1],rd[1])+1;
        return myans;
    }
    public static boolean targetSum(node Node,int target)
    {
        if(Node.left==null && Node.right==null)
         {
            if(target-Node.data==0)
             {
              return true;
             }
            return false;
         }
        boolean res=false;
        if(target-Node.data>=0)
         {
             if(Node.left!=null)
              {
                res=res||targetSum(Node.left,target-Node.data);
              }
             if(Node.right!=null)
              {
               res=res||targetSum(Node.right,target-Node.data);
              }
         }
        return res;
    }
    static int MaxSum=Integer.MIN_VALUE;
    public static int leafToLeafSum(node Node)
    {
        if(Node==null)
         {
             return Integer.MIN_VALUE;
         }
        if(Node.left==null && Node.right==null)
         {
             return Node.data;
         }
        int lsum=leafToLeafSum(Node.left);
        int rsum=leafToLeafSum(Node.right);

        if(Node.left!=null && Node.right!=null)
         {
             MaxSum=Math.max(MaxSum,lsum+rsum+Node.data);
         }
        return Math.max(lsum,rsum)+Node.data;
    }
    public static void solve()
    {
         int[] arr={10,20,30,40,-1,-1,50,-1,-1,60,-1,70,-1,-1,80,90,100,120,-1,-1,130,-1,-1,110,-1,-1,140,-1,-1};
         node rootNode=constructTree(arr);
         display(rootNode);
        //  System.out.println(diameter_01(rootNode));
        //  int[] ans=diameter_02(rootNode);
        //  System.out.println(ans[0]);
        System.out.println(targetSum(rootNode,350));
    }
    public static void main(String[] args)
    {
        solve();
    } 
}    