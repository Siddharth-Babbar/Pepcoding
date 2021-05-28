import java.util.Scanner;
public class RotateNumber {

  public static Scanner scn = new Scanner(System.in);
  public static void main(String[] args) {
    int n=0,r=0;
    System.out.print("Enter the number: ");
    n=scn.nextInt();
    System.out.print("Enter the number of digits to be rotated clockwise: ");
    r=scn.nextInt();
    System.out.print("The number after rotation is: " + rotate(n,r));
  }
  public static int rotate(int n,int r) {

    int digits=0,multipler=1,divisor=1,fdigit=0,sdigit=0;
    digits=digit(n);
    r=r%digits;
    r=(r<0)?(r+digits):r;
    for(int i=1;i<=digits;i++) {

       if(i<=r) {

        multipler*=10;
        }
       else {

        divisor*=10;
       }
     }
    fdigit=n%divisor;
    sdigit=n/divisor;

    return fdigit*multipler + sdigit;

  }
  public static int digit(int n) {
    
    int ans=0;
    while(n!=0) {
      ans++;
      n/=10;
    }
    return ans;
  }
}