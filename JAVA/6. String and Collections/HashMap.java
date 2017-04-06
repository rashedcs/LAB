//Source :  http://www.javatpoint.com/java-hashmap


import java.util.*;  
import java.util.HashMap;

class Main
{  
   public static void main(String args[])
   {  
      HashMap<Integer,String> hm=new HashMap<Integer,String>();  
      hm.put(100,"Amit");  
      hm.put(101,"Vijay");  
      hm.put(102,"Rahul");  
     
      for(Map.Entry m: hm.entrySet())
      { 
        System.out.printf("%d %s\n",m.getKey(), m.getValue());  
      }  
   }
}
