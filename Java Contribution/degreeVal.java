// Degree Validator 
// From : Sharjeel-Iftikhar
// Language : Java
import java.util.Scanner;
public class degreeVal{
  static boolean validateDegree(String degree)
  {
    boolean flag = false;
    if(degree.length()!=2)
    {
      return flag;
    }
    else
    {
      for(int i=0;i<degree.length();i++)
      {
        if( (degree.charAt(0)=='M'&& degree.charAt(1)=='S') || (degree.charAt(0)=='B'&& degree.charAt(1)=='S')
           || (degree.charAt(0)=='B'&& degree.charAt(1)=='E') )
        {
          flag =true;
        }
      }
    }
    return flag;
  }
  public static void main(String[] args)
  {
    Scanner me = new Scanner(System.in);
    System.out.println("Enter the Degree title : ");
    String degree = me.nextLine();
    boolean flag = validateDegree(degree);
    if(flag==true)
    {
      System.out.println("OK");
    }
    else
    {
      System.out.println("Invaid Degree title !!");
    }
  }
}