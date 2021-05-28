import java.util.ArrayList;
public class Graph1
{
   public static class Edge
   {
       int v=0;
       int w=0;
       Edge(int v,int w)
        {
            this.v=v;
            this.w=w;
        }
   }
   public static ArrayList<ArrayList<Edge>> graph=new ArrayList<>();
   public static void main(String[] args)
   {
      ConstructGraph();
    //   removeEdge(3,4);
      removeVtx(3);
      display();
   }
   public static void ConstructGraph()
   {
      int n=7;
      for(int i=0;i<=n;i++)
       {
           graph.add(new ArrayList<>());
       }
       addEdge(0,1,10);
       addEdge(0,3,10);
       addEdge(1,2,10);
       addEdge(2,3,40);
       addEdge(3,4,2);
       addEdge(4,5,2);
       addEdge(4,6,3);
       addEdge(5,6,8);

       display();
   } 
   
   public static void addEdge(int u,int v,int w)
   {
       if(u<0 || v<0 || u>graph.size() || v> graph.size())
        {
            return ;
        }
       graph.get(u).add( new Edge(v,w));
       graph.get(v).add(new Edge(u,w));

   }
   public static void removeEdge(int u,int v)
   {
    //    int i = 0;
    //    for(Edge e : graph.get(u))
    //     {
    //         if(e.v== v)
    //         {
    //             break;
    //         }
    //         i++;
    //     }
    //   int j=0;
    //     for(Edge e : graph.get(v)){
    //        if(e.v== u)
    //         {
    //             break;
    //         }
    //         j++;
    //     }
    int i = 0;
    for(;i<graph.get(u).size();i++)
     {
            if(graph.get(u).get(i).v== v)
            {
                break;
            }
     }
    int j=0;
    for(;j<graph.get(v).size();j++)
      {
         if(graph.get(v).get(j).v== u)
         {
           break;
         }
      }
      graph.get(u).remove(i);
      graph.get(v).remove(j);
   }
   public static void removeVtx(int u)
    {
        ArrayList<Edge> list=graph.get(u);
        int i=0;
        while(list.size()!=0)
         {
            // Edge e = list.get(i);
            // removeEdge(u, e.v);
            removeEdge(u,list.get(i).v);
         }
    }
   public static void display()
   {
       for(int i=0;i<7;i++)
        {
            System.out.print(i+":->");
            for(Edge e:graph.get(i))
             {
                 System.out.print("("+e.v+","+e.w+") ");
             }
            System.out.println();
        }

   }
}