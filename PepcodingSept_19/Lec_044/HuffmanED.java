import java.util.PriorityQueue;
import java.util.HashMap;
public class HuffmanED
{
    private HashMap<String,String> encode=new HashMap<>();
    private HashMap<String,String> decode=new HashMap<>();
    public class Node implements Comparable<Node>
    {
        private String data="";
        private int freq=0;
        private Node left=null;
        private Node right=null;
        

        public Node(String data,int freq,Node left,Node right)
        {
           this.data=data;
           this.freq=freq;
           this.left=left;
           this.right=right;
        }

        @Override
        public int compareTo(Node o)
        {
            return this.freq-o.freq;

        }
    }
    PriorityQueue<Node> pq=new PriorityQueue<>();

    public HuffmanED(String str)
    {
         HuffManTree(str);
        //  System.out.println(str);
    }
    
    private void HuffManTree(String str)
    {
        int[] FreqMap=new int[26];
        for(int i=0;i<str.length();i++)
         {
             FreqMap[str.charAt(i)-'a']++;
         }
        // for(int ele:FreqMap)
        //  {
        //      System.out.println(ele);
        //  }
        // System.out.println(FreqMap[0]);
        for(int i=0;i<FreqMap.length;i++)
         {
             if(FreqMap[i]>0)
              {
                // System.out.println('a'+FreqMap[i]+"");
                pq.add(new Node((char)('a'+i)+"",FreqMap[i],null,null));
              }
         }
        while(pq.size()!=1)
         {
             Node one=pq.poll();
             Node two=pq.poll();

             pq.add(new Node("",one.freq+two.freq,one,two));
         }
        Node root=pq.poll();
        // System.out.println(root);
        HuffManTraversal(root,"");
        
    }
    private void HuffManTraversal(Node root,String BinaryCode)
    {
       if(root.left==null && root.right==null)
        {
            encode.put(root.data,BinaryCode);
            // System.out.println(root.data+" " + encode.get(root.data));
            decode.put(BinaryCode,root.data);
            // System.out.println(decode.get(BinaryCode));
            return ;
        }

        HuffManTraversal(root.left,BinaryCode+"0");
        HuffManTraversal(root.right,BinaryCode+"1");
    }
    public String Encoder(String str)
    {
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<str.length();i++)
         {
             String s=str.charAt(i)+"";
             sb.append(encode.get(s));
            //  System.out.println(encode.get(s));
         }
        return sb.toString();
    }
    public String Decoder(String str)
    {
        StringBuilder sb=new StringBuilder();
        int j=0;
        for(int i=0;i<str.length();i++)
         {
             String s=str.substring(j,i+1);
             if(decode.containsKey(s))
              {
                  sb.append(decode.get(s));
                  j=i+1;
              }
         }
        return sb.toString();

    }


    

}