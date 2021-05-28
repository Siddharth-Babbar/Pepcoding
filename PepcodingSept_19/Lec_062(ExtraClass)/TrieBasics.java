public class TrieBasics
{
    public class Node
    {
        int WordEnd=0;
        Node[] childs;
        //String Word="";

        Node()
         {
             this.WordEnd=0;
             this.childs=new Node[26];
         }
    }

    Node root=null;

    public void insert(String Word)
     {
         Node curr=root;
         int n=Word.length();
         for(int i=0;i<n;i++)
          {
              int idx=Word.charAt(i)-'a';
              if(curr.childs[idx]==null) 
               {
                   curr.childs[idx]=new Node();
               }
              curr=curr.childs[idx];
          }
         curr.WordEnd++;
     }
    
    public boolean search(String Word)
      {
         Node curr=root;
         int n=Word.length();
         for(int i=0;i<n;i++)
          {
              int idx=Word.charAt(i)-'a';
              curr=curr.childs[idx];

              if(curr == null)
               {
                   return false;
               }
          }
        
         return curr.WordEnd>0?true:false;
      }

    public boolean startWith(String prefix)
      {
         Node curr=root;
         int n=prefix.length();
         for(int i=0;i<n;i++)
          {
              int idx=prefix.charAt(i)-'a';
              curr=curr.childs[idx];

              if(curr == null)
               {
                   return false;
               }
          }
        
         return true;
      }
}