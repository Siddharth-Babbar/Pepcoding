import java.util.Scanner;
public class PascalTri
{
    public static Scanner sch=new Scanner(System.in);
    public static void main(String[] args)
    {
        System.out.println("Enter the number of rows");
        int rows=sch.nextInt();
        pascaltriangle(rows);
    }
    public static  void pascaltriangle(int rows)
    {
         for(int n=0;n<=rows;n++)
         {
             int val=1;
             for(int r=0;r<=n;r++)
              {
                  System.out.print(val +" ");
                  val=val*(n-r)/(r+1);
              }
            
            System.out.println();
         }
    }

}