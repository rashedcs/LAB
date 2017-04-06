//Source : http://www.javatpoint.com/java-arraylist
//Source : https://www.hackerrank.com/challenges/java-list

//Integers 
import java.util.*; 
import java.util.Scanner;

class Main
{  
   public static void main(String args[])
   {  
	   //Creating arraylist  
	   ArrayList<Integer> arr=new ArrayList<Integer>(); //Adding object in arraylist  
	   
	   System.out.print("Add ");
	   arr.add(0,5);
	   arr.add(1,6);
	   arr.add(2,10);
	   arr.add(3,12);  
	   arr.add(4,15);  
	     
	   //Traversing list  
	   for(int i=0; i<arr.size(); i++)
	   {
		  System.out.printf("%d ",arr.get(i));
	   } 
	   
	   System.out.print("\nRemove ");
	   
	   arr.remove(0);
	   arr.remove(0);
	  
	   //Traversing list  
	   for(int i=0; i<arr.size(); i++)
	   {
		   System.out.printf("%d ",arr.get(i));
	   } 
	   
	   Collections.sort(arr); 
	  
	   System.out.print("\nSorting ");
	   for(int i=0; i<arr.size(); i++)
	   {
		   System.out.printf("%d ",arr.get(i));
	   } 
   }  
}  











//String Problems
import java.util.*; 
import java.util.Scanner;

class Main
{  
   public static void main(String args[])
   {  
	   //Creating arraylist  
	   ArrayList<String> arr=new ArrayList<String>();
	   arr.add("Ravi");//Adding object in arraylist  
	   arr.add("Vijay");  
	   arr.add("Ravi");  
	   arr.add("Ajay");  
	   
	   //Traversing list through Iterator  
	   for(int i=0; i<arr.size(); i++)
	   {
	      System.out.println(arr.get(i));
	   } 
   }  
}  
