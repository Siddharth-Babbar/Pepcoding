import java.util.LinkedList;

import java.util.ArrayList;

public class HashMap_<K,V>
{
    public class Node
    {
        K key;
        V value;

        public Node(K key,V value)
         {
             this.key=key;
             this.value=value;
         }
        
        @Override
        public String toString()
        {
           return this.key+"="+this.value;
        }
    }

    private LinkedList<Node>[] buckets=new LinkedList[10];
    private int size=0;

    public HashMap_()
    {
       reassign();
    }

    private void reassign()
    {
        for(int i=0;i<buckets.length;i++)
        {
            buckets[i]=new LinkedList();
        }
        this.size=0;
    }
    @Override
    public String toString()
    {
        StringBuilder sb=new StringBuilder();
        sb.append("{");
        int size=buckets.length;
        for(int i=0;i<size;i++)
         {
             LinkedList<Node> group=buckets[i];
             int size_=group.size();
             if(group!=null)
              {    
                  while(size_-- >0)
                   {
                       Node put=group.getFirst();
                       sb.append(put+",");
                       group.addLast(group.removeFirst());
                   }
              }
         }
        sb.deleteCharAt(sb.length()-1);
        sb.append("}");
        return sb.toString();
    }

    public void put(K key,V value)
    {
        int code=MyGroup(key);
        LinkedList<Node> group=buckets[code];
        // if(group== null)
        //  {
        //      group=new LinkedList<Node>();
        //      group.addLast(new Node(key,value));
        //      buckets[code]=group;
        //  }
        // else
        //  {
            //  Node pn=foundInGroup(group,key);
            //  if(pn!=null)
            //   {
            //       pn.value=value;
            //   }
            //  else
            //   {
            //       group.addLast(new Node(key,value));
            //   }
        //  }
        Node rn=foundInGroup(group,key);
        if(rn!=null)
         {
             rn.value=value;
         }
        else
         {
             Node pn=new Node(key,value);
             group.addLast(pn);

             this.size++;

             double lambda=(group.size()*1.0)/buckets.length;
             if(lambda>=0.3)
              {
                 System.out.println("Rehash :"+ group.size());
                 rehash();

              }
         }

    }   
    
    public void rehash()
    {
        LinkedList<Node>[] oldBuckets=buckets;
        buckets=new LinkedList[oldBuckets.length*2];

        reassign();

        for(int i=0;i<oldBuckets.length;i++)
         {
             LinkedList<Node> group=oldBuckets[i];
             int size=group.size();
             while(size-- >0)
              {
                  Node tnode=group.removeFirst();
                  put(tnode.key,tnode.value);
              }
         }

    }

    public int size()
    {
        return this.size();
    }

    public V get(K key)
    {
        int code=MyGroup(key);
        LinkedList<Node> group=buckets[code];
        Node rn=foundInGroup(group,key);
        return rn==null?null:rn.value;
    }

    public Node remove(K key)
    {
        int code=MyGroup(key);
        LinkedList<Node> group=buckets[code];
        Node rn=foundInGroup(group,key);
        if(rn!=null)
         {
             this.size--;
             return group.removeFirst();
         }
        else
         {
             System.out.println("ElementNotFound:-1");
             return null;
         }
    }

    public Boolean containsKey(K key)
    {
        int code=MyGroup(key);
        LinkedList<Node> group=buckets[code];
        Node rn=foundInGroup(group,key);

        return rn!=null;
    }


    public Node foundInGroup(LinkedList<Node> group,K key)
    {
        if(group==null)
         {
             return null;
         }
        Node rn=null;
        int size=group.size();
        while(size-- >0)
         {
             Node tempNode=group.getFirst();
             if(tempNode.key== key)
              {
                  rn=tempNode;
                  break;
              }

             group.addLast(group.removeFirst());
         }
        return rn;
    }
   
    public Boolean IsEmpty()
    {
        return this.size==0;
    }

    public ArrayList<K> keySet()
    {
        ArrayList<K> key=new ArrayList<>();
        int size=0;
        LinkedList<Node> group=new LinkedList<>();
        for(int i=0;i<buckets.length;i++)
         {
             if(buckets[i]!=null)
              {
                  group=buckets[i];
                  size=group.size();
                  while(size-- >0)
                   {
                     key.add(group.getFirst().key);
                     group.addLast(group.removeFirst());
                   }
              }
         }
        return key;        
    }
    
    public V getOrDefault(K key,V defaultValue)
    {
        int code=MyGroup(key);
        LinkedList<Node> group=buckets[code];
        Node rn=foundInGroup(group,key);

        return rn==null?defaultValue:rn.value;
    }

    // public Integer getOrDefault(Integer key,Integer defaultValue)
    // {
    //     Integer rn=get(key);
    //     return rn==null?defaultValue:rn;
    // } 

    public int MyGroup(K key)
    {
        return MyHashCode(key)%buckets.length;
    }

    public int MyHashCode(K key)
    {
        int val=key.hashCode();
        return Math.abs(val);
    }

    // public int MyGroup(Integer key)
    // {
    //     int val=key.hashCode();
    //     return Math.abs(val)%buckets.length;
    // }





}