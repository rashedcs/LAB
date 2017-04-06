 import java.util.*;
 import java.util.Arrays;
 import java.util.Collections;
 import java.util.Random;

 
 
 class StringUtility 
 {
	//Case 1 : Sort the array to ascending order
	public void sortArray(String[] str)
	{
		Arrays.sort(str, String.CASE_INSENSITIVE_ORDER);
	}
	 
    //Case 2 : Sort the array to ascending order
	public void sortArrayFull(String[] str)
	{
		String s;
		char [] c;
		
		for(int i=0; i<str.length; i++)
		{
			c = str[i].toCharArray(); //Convert to array of chars 
			Arrays.sort(c);           //Sort
			str[i] = new String(c);  //Assign to array
		}
		//this.sortArray(str);   //sort the array of strings
		Arrays.sort(str);
	 }
}



public class main
{
	public static void main(String [] args) 
	{
		StringUtility  str = new StringUtility ();
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		String [] str1 = new String[num];
		for(int i=0; i<num; i++)
		{
			str1[i]= sc.next();
		}
		str.sortArray(str1);
		String [] str2 = str1.clone();
		str.sortArrayFull(str2);
		for(int i=0; i<num; i++)
		{
			System.out.println(str1[i]+ " "+str2[i]);
		}
	}
}





/*
   3
   rashed ishi nazmul
 */


















import java.util.*;
import java.util.Arrays;




public class StringUtility 
{
	public String sortSingle(String str)
	{
		//char[] chars = str.toCharArray();
        //Arrays.sort(chars);
        //return new String(chars);
		String[] split= str.split("");
		Arrays.sort(split, String.CASE_INSENSITIVE_ORDER);
		String sorted = "";
	    for (int i = 0; i < split.length; i++)
	    {
	      sorted += split[i];
	    }
	    return sorted;
	}
	
	
	 public void sortArray(String [] str)
	 {
		Arrays.sort(str, String.CASE_INSENSITIVE_ORDER);
	 }
	 
	 public void sortFull(String str[])
	 {
		for(int i=0; i<str.length; i++)
		{
			str[i] = this.sortSingle(str[i]);
		}
		this.sortArray(str) ;
	 }
}
	





public class Main
{
	public static void main(String[] args) 
	{
		StringUtility  str = new StringUtility ();
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		String [] str1 = new String[num];
		for(int i=0; i<num; i++)
		{
			str1[i]= sc.next();
		}
		String [] str2 = str1.clone();
		str.sortArray(str1);
		str.sortFull(str2);
		for(int i=0; i<num; i++)
		{
	            System.out.println(str1[i]+ " "+str2[i]);
		}
		
	}

}
