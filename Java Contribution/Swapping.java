import java.util.*;
 public class Swap
 {
     public static void main (String args[])
     {
         Scanner in =new Scanner (System.in);
         int a,b,c=0;
         System.out.println (" Enter your number") ;
         a=in.nextInt ();
         b=in.nextInt ();
         c=a;
         a=b;
         b=c;
         System.out.println (" The value of a:" + a);
         System.out.println (" The value of b:" + b);
     }
 }
