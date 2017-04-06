import java.util.Scanner;
 
class Main
{
   public static void main(String args[])
   {
      String str, sub;
      int i, c, length;
 
      Scanner in = new Scanner(System.in);
      System.out.println("Enter a string to print it's all substrings");
      str  = in.nextLine();
 
      length = str.length();   
 
      System.out.println("Substrings of \""+str+"\" are :-");
 
      for(c=0 ; c<length ; c++)
      {
         for(i=1 ; i<=length-c ; i++)
         {
            sub = str.substring(c, c+i);
            System.out.println(sub);
         }
      }
   }
}
