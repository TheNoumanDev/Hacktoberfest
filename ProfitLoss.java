import java.util.*;
class ProfitLoss
{
public static void main (String args[])
{
   Scanner in= new Scanner (System.in);
   double cp,sp,p,l;
   System.out.println ("Enter the cost price");
   cp=in.nextDouble();
   System.out.println ("Enter the selling price");
   sp=in.nextDouble();
   if (sp>cp)
   {
       p=sp-cp;
       System.out.println ("Profit: " + p);
    }
    else if (cp>sp)
    {
        l=cp-sp;
        System.out.println ("Loss: " + l);
    }
    else
        System.out.println ("Neither loss nor profit");
    }
}
