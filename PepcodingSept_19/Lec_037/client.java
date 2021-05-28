public class client
{
    public static void main(String[] args)
    {
        int[] arr={1,2,3,4,5};
        stack st=new stack(arr);
        System.out.println(st.isEmpty());
        System.out.println(st.pop());
        st.push(10);
        st.push(20);
        st.push(30);
        st.push(40);
        st.push(50);
        st.push(60);
        st.push(70);
        st.push(80);
        st.push(90);
        st.push(100);
        System.out.println(st.isEmpty());
        System.out.println("Size:"+st.size());
        System.out.println(st.pop());
        for(int ele:st.st)
         {
            System.out.print(ele+" ");               
         }
        st.display();

        // queue qu=new queue(arr);
        // System.out.println(qu.isEmpty());
        // System.out.println(qu.size());
        // System.out.println(qu.pop());
        // System.out.println(qu.front());
        // qu.push(10);
        // qu.push(20);
        // qu.push(30);
        // qu.push(40);
        // qu.push(50);
        // System.out.println(qu.size());
        // qu.push(60);
        // System.out.println(qu.front());
        // qu.push(70);
        // qu.push(80);
        // System.out.println(qu.pop());
        // qu.push(90);
        // qu.push(100);
        // qu.push(110);
        // System.out.println(qu.isEmpty());
        // System.out.println(qu.size());
        // qu.display();

        // dynamicStack st=new dynamicStack(arr);
        // System.out.println(st.isEmpty());
        // System.out.println(st.pop());
        // st.push(10);
        // st.push(20);
        // st.push(30);
        // st.push(40);
        // st.push(50);
        // st.push(60);
        // st.push(70);
        // st.push(80);
        // st.push(90);
        // st.push(100);
        // System.out.println(st.isEmpty());
        // System.out.println("Size:"+st.size());
        // System.out.println(st.pop());
        // st.display();

        // dynamicStack st=new stack(10);
        // stack st=new dynamicStack(10);
        // st.fun();
        // st.fun1();
        // st.fun2();

        // dynamicQueue qu=new dynamicQueue(arr);
        // System.out.println(qu.isEmpty());
        // System.out.println(qu.size());
        // System.out.println(qu.pop());
        // System.out.println(qu.front());
        // qu.push(10);
        // qu.push(20);
        // qu.push(30);
        // qu.push(40);
        // qu.push(50);
        // // System.out.println(qu.size());
        // qu.push(60);
        // // System.out.println(qu.front());
        // qu.push(70);
        // qu.push(80);
        // System.out.println(qu.pop());
        // qu.push(90);
        // qu.push(100);
        // qu.push(110);
        // System.out.println(qu.isEmpty());
        // System.out.println(qu.size());
        // qu.display();


    }
}