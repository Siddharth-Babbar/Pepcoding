import java.util.NoSuchElementException;
public class LinkedList
{
    private class Node
    {
        int data=0;
        Node next=null;
        
        Node(int data)
        {
            this.data=data;
        }
        @Override
        public String toString()
        {
           return this.data+"";
        }

    }
    private Node head=null;
    private Node tail=null;
    private int nodeCounter=0;

    //basic functions==================================== 
    public int size()
    {
        return this.nodeCounter;
    }

    public boolean IsEmpty()
    {
        return this.nodeCounter==0;
    }

    public Node getNodeAt(int idx)
    {
        if(idx<0 || idx>=this.nodeCounter)
         {
             throw new NullPointerException();
         }
        
        Node curr=this.head;
        while(idx-->0)
         {
             curr=curr.next;
         }
        
        return curr;
    }

    //Add================================================

    // private void addFirstNode(Node node)
    // {
    //     if(this.nodeCounter==0)
    //      {
    //          this.tail=node;
    //      }
    //     node.next=this.head;
    //     this.head=node;

    //     this.nodeCounter++;

    // }
    private void addFirstNode(Node node)
    {
        if(this.nodeCounter==0)
         {
             this.head=node;
             this.tail=node;
         }
        else
         {
           node.next=this.head;
           this.head=node;
         }
    }

    public void addFirst(int data)
    {
        Node node=new Node(data);
        addFirstNode(node);
    }

    private void addLastNode(Node node)
    {
        if(this.nodeCounter==0)
         {
            this.head=node;
            this.tail=node;   
         }
        else
         {
             this.tail.next=node;
             this.tail=node;
         }

        this.nodeCounter++;
    }

    private void addAtNode(Node node,int idx)
    {
        if(idx ==0)
         {
             addFirstNode(node);
         }
        else if(idx == this.nodeCounter)
         {
             addLastNode(node);  
         }
        Node prev=getNodeAt(idx);
        Node forw=prev.next;


         
    }

    public void addAt(int data,int idx)
    {
        
        if(idx<0 || idx>this.nodeCounter)
         {
            throw new NullPointerException();
         }
        
        Node node = new Node(data);
        addAtNode(node,idx);

    }
    

    //get================================================

    public int getFirst()
    {
        if(this.nodeCounter == 0)
         {
             throw new NoSuchElementException();
         }
        return this.head.data;
    }

    public int getLast()
    {
        if(this.nodeCounter == 0)
         {
             throw new NoSuchElementException();
         }
        return this.tail.data;
    }

    public int getAt(int idx)
    {
        return getNodeAt(idx).data;
    }

    //remove======================================================

    private Node removeFirstNode()
    {
        Node rn=this.head;
        if(this.nodeCounter == 1)
         {
             this.head=null;
             this.tail=null;
         }
        else
         {
             this.head=rn.next;
             rn.next=null;
         }

        this.nodeCounter--;
        return rn;
    }
    
    public int removeFirst()
    {
        if(this.nodeCounter==0)
         {
             throw new NoSuchElementException();
         }
        return removeFirstNode().data;

    }

    private Node removeLastNode()
    {
        Node rn=this.tail;
        if(this.nodeCounter == 1)
         {
             this.head=null;
             this.tail=null;
         }
        else
         {
             Node secondLast=getNodeAt(this.nodeCounter-2);
             this.tail=secondLast;
             this.tail.next=null;
         }

        this.nodeCounter--;
        return rn;
    }

    public int removeLast()
    {
        if(this.nodeCounter == 0)
         {
             throw new NoSuchElementException();
         }
        return removeLastNode().data;
    }

}