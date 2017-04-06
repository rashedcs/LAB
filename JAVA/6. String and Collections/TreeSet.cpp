//Source  :   http://www.javatpoint.com/java-treeset

import java.util.*;  
import java.util.TreeSet;


//Duplicate element is not available
class Main
{  
    public static void main(String args[])
    {  
      //Creating and adding elements  
       TreeSet<String> al=new TreeSet<String>();  
       al.add("Ravi");  
       al.add("Vijay");  
       al.add("Ravi");  
       al.add("Ajay"); 
      
       //Traversing elements  
       for(String item : al)
       {
         System.out.printf("%s ",item);
       } 
    }  
 }  
