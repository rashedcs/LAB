//A string is a line of all character
import java.util.Scanner;

class string
{

	   public static void main(String[] args) 
	   {
	     Scanner sc = new Scanner(System.in);
	     System.out.println("Write line a Text");
	     String str = sc.nextLine();
	     System.out.println("Output : "+str);
	   }
}

/*
Input  : i like u
Output : i like u
*/








/** Input some string in a single line : /A string is a line of all character. 
But we can a line of all words consides all strings in a single .
**/

import java.util.Scanner;

public class string
{
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		
		System.out.print("Enter how many friends: ");
		
	//	int numOfFriends = Integer.parseInt(scan.nextLine());
		int numOfFriends = scan.nextInt(); 
 
		String arrayOfNames[] = new String[numOfFriends];
		
		for (int i=0; i<arrayOfNames.length; i++) 
		{
		     arrayOfNames[i] = scan.next();  //If we take several lines of string scan.nextLine() ;
		}

		for (int i=0; i<arrayOfNames.length; i++) 
		{
		     System.out.print(arrayOfNames[i] + " ");
		}
	}
 
} 

/*
Enter how many friends: 5
rashed nazmul hasan islam man
rashed nazmul hasan islam man 
*/
