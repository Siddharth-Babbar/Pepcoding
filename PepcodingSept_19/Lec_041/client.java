public class client
{
    public static void main(String args[])
     {
         heap obj=new heap();
         obj.push_(10);
         obj.push_(20);
         obj.push_(30);
         obj.push_(-2);
         obj.push_(-3);
         obj.push_(-4);
         obj.push_(5);
         obj.push_(6);
         obj.push_(7);
         obj.push_(8);
         obj.push_(22);
         obj.push_(11);
         obj.push_(13);
        //  obj.display();
        //  System.out.println(obj.height(0));
        // for(int i=12;i>=0;i--)
        //  {
        //      obj.downheapify(i);
        //  }
        obj.display();
     }
}
