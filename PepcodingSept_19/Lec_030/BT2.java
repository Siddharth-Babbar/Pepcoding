import java.util.ArrayList;
public class BT2
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
    public static ArrayList<node> rootToNodePath(node Node,int data)
    {

        if(Node==null)
         {
            ArrayList<node> base=new ArrayList<node>();
            return base;
         }
        
        if(Node.data==data)
         {
            ArrayList<node> smallans=new ArrayList<node>();
            smallans.add(Node);
            return smallans;
         }
        ArrayList<node> left=rootToNodePath(Node.left,data);
        if(left.size()!=0)
         {
             left.add(Node);
             return left;
         }
        ArrayList<node> right=rootToNodePath(Node.right,data);
        if(right.size()!=0)
         {
             right.add(Node);
             return right;
         }
        return new ArrayList<node>();
    }
    public static int LCA(node Node,int data1,int data2)
    {
        ArrayList<node> list1=rootToNodePath(Node,data1);
        ArrayList<node> list2=rootToNodePath(Node,data2);
        int i=list1.size()-1;
        int j=list2.size()-1;
        int ans=-1;
        while(i>=0 && j>=0)
         {
             if(list1.get(i)!=list2.get(j))
              {
                  break;
              }
             ans=list1.get(i).data;
             i--;
             j--;
         }
        return ans; 
    }
    public static void kDown(node Node,node PNode,int level)
    {
        if(Node==null || PNode==Node )
         {
             return;
         }
        if(level==0)
         {
             System.out.print(Node.data+" ");
             return;
         }
        kDown(Node.left,Node,level-1);
        kDown(Node.right,Node,level-1);
    }
    public static void KAway_01(node Node,int target,int k)
    {
        ArrayList<node> list=rootToNodePath(Node,target);
        node PNode=null;
        for(int i=0;i<list.size();i++)
         {
            kDown(list.get(i),PNode,k-i);
            PNode=list.get(i);
         }
    }
    public static int  KAway_02(node Node,int target,int k)
    {
        if(Node==null)
         {
             return -1;
         }
        if(Node.data==target)
         {
             kDown(Node,null,k);
             return 1;
         }
        int ld=KAway_02(Node.left,target,k);
        if(ld!=-1)
         {
             kDown(Node,Node.left,k-ld);
             return ld+1;
         }
        int rd=KAway_02(Node.right,target,k);
        if(rd!=-1)
         {
             kDown(Node,Node.right,k-rd);
             return rd+1;
         }
        return -1;

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
        System.out.println(LCA(rootNode,30,40));
        KAway_01(rootNode,10,1);
        KAway_02(rootNode,10,1);

     }
    public static void main(String[] args)
     {
         solve();
     }
}