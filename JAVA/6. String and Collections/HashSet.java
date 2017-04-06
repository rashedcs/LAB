//Source :  http://www.javatpoint.com/java-hashset


import java.util.*;  
import java.util.HashSet;

class Main
{  
   public static void main(String args[])
   {  
       //Creating HashSet and adding elements  
       HashSet<String> set=new HashSet<String>();  
       set.add("Ravi");  
       set.add("Vijay");  
       set.add("Ravi");  
       set.add("Ajay");  
      //Traversing elements  
	     for(String item : set)
	     {
	        System.out.printf("%s ",item);
	     } 
   }  
}  
