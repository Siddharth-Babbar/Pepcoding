import java.util.Scanner;
public class Pattern5
{
    public static Scanner sch=new Scanner(System.in);
    public static void numberfullDiamond(int rows)
    {
      int nsp=rows-1;
      int nst=1;
      for(int i=1;i<=rows;i++)
       {
           for(int csp=1;csp<=nsp;csp++)
            {
                System.out.print(" ");
            }
           int val=i;
           if(i>(rows+1)/2) 
            {
                val=rows-i+1;
            }
           for(int cst=1;cst<=nst;cst++)
           
             {
                System.out.print(val);
                if(cst<=nst/2)
                 {
                     val++;
                 }
                else
                val--;
             }
            if(i<=rows/2)
             {
                 nsp--;
                 nst+=2;
                 System.out.println();
             }
            else
            {
                 nsp++;
                 nst-=2;
                 System.out.println();  
            }
       }
    }    
    public static void main(String[] args)
    {
         System.out.println("Enter the number of rows:");
         int rows=sch.nextInt();
         numberfullDiamond(rows);
    }
}