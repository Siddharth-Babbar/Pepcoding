public class facto
{
    public static void main(String[] args)
    {
       int ans=1;
       Factorial(4,ans);

    }
    public static void Factorial(int n,int ans)
    {
        if(n==0)
        return;
        ans*=n;
        Factorial(n-1,ans);
        if(n==1)
        System.out.println(ans);
    }
}