public class power
{
    public static void main(String[] args)
    {
      
      System.out.println(power_better(2,10));

    }
    public static int powera_b(int a,int b)
    {
        if(b==1)
        return a;

        int smallans=powera_b(a,b-1);
        return smallans*a;
    }
    public static int power_better(int a,int b)
    {
        if(b==1)
        return a;
        int smallans=power_better(a,b/2);
        smallans*=smallans;
        return ((b%2)!=0)?smallans*a:smallans;
    }
}