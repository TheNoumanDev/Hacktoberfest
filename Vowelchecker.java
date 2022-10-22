import java.util.*;
class Vowel
{
    public static void main (String args [])
    {
        Scanner in =new Scanner (System.in);
        char ch;
        System.out.println ( " Input a character");
        ch=in.next().charAt(0);
        if ( ch=='a' | ch=='e' | ch == 'i' | ch== 'o'| ch=='u')
        {
            System.out.println ( " It is a vowel");
                    if (ch>='a' && ch<'n')
                
                   System.out.println ( " It comes in first half of the alphabet"); 
                
                else
                    System.out.println ( " It comes in second half of the alphabet");
                }
        else 
            System.out.println ( " It is not a vowel");
        }
    }
