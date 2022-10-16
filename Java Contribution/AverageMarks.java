import java.util.Scanner;
public class home1{
   public static void main(String[] args) {
 int n;
 int avg=0;
 int sum=0;
 Scanner scanner = new Scanner(System.in);
 System.out.print("Enter no. of subjects to enter marks:");
 n = scanner.nextInt();
 if(n>=8){
   
  int arr[]=new int[n];
  for(int i = 0; i < n; i++)
 {
  arr[i] = scanner.nextInt();
  sum=sum+arr[i];
  avg=sum/n;
  }
System.out.print("Average of marks:"+avg);
if(avg>=80){
  System.out.print("");
  System.out.print("\nGrade:A");
}
else if(avg<80&&avg>=70){
  System.out.print("\nGrade:B");
}
else if(avg<70&&avg>=60){
  System.out.print("\nGrade:C");
}
else if(avg<60&&avg>=50){
  System.out.print("\nGrade:D");
}
else if(avg<50){
  System.out.print("\nGrade:F");
}
   }
 else{
   System.out.print("Invalid Subjects \n Please add 8 or more subjects");
 }
   }
}