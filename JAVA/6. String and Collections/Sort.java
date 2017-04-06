//Sort an array


String[] fruits = new String[] {"Pineapple","Apple", "Orange", "Banana"};

Arrays.sort(fruits);

int i=0;
for(String temp: fruits)
{
	System.out.println("fruits " + ++i + " : " + temp);
}







//Sorting object of array 
import java.util.*;
import java.util.Scanner;


class Checker implements Comparator
{
   public int compare(Object o1,Object o2)
   {
     Player p1=(Player)o1;
     Player p2=(Player)o2;
     if(p1.score==p2.score)  return p1.name.compareTo(p2.name);
     else                    return p2.score-p1.score;
   }
} 



class Player
{
    String name;
    int score;
    
    Player(String name, int score)
    {
        this.name = name;
        this.score = score;
    }
}

class ArraylistSort
{
    public static void main(String[] args) 
    {
         Scanner scan = new Scanner(System.in);
         int n = scan.nextInt();

         Player player[] = new Player[n];
        //   Checker checker = new Checker();
        
         for(int i=0; i<n; i++)
         {
             player[i] = new Player(scan.next(), scan.nextInt());
         }
        
         scan.close();
      
         Arrays.sort(player,  new Checker());
        //Arrays.sort(player,  checker);
         for(int i=0; i<player.length; i++)
         {
           System.out.printf("%s %d\n", player[i].name, player[i].score);
         }
         
         
         
         System.out.printf("\nSorting using Array List \n");
         
         /*
          We can put the player data using ArrayList or List - Just for learn 
          ArrayList<Player> myList = new ArrayList<Player>();
	      for(int i=0; i<n; i++)
          {
		    myList.add(player[i]);
		  }
		  
		  Collections.sort(myList, new Checker());
	     */
         
         
	      List<Player> myList  = Arrays.asList(player);
	      Collections.sort(myList,new Checker());
	     
	  
		 for(Player st : myList) 
		 {
		 	System.out.printf("%s %d\n", st.name, st.score);
		 }
     }
  }






































import java.util.*; 
import java.util.Scanner;

class Main
{  
   public static void main(String args[])
   {  
	   //Creating arraylist  
	   ArrayList<Integer> arr=new ArrayList<Integer>(); //Adding object in arraylist  
	   
	   arr.add(0,50);
	   arr.add(1,16);
	   arr.add(2,10);
	   arr.add(3, 2);  
	   arr.add(4,15);  
	  // al.add(Integer.valueOf(201));  
	  // al.add(Integer.valueOf(101));  
	
	   
	   Collections.sort(arr); 
	  
	   System.out.print("\nSorting ");
	   for(int i=0; i<arr.size(); i++)
	   {
		   System.out.printf("%d ",arr.get(i));
	   } 
    }  
}  
















import java.util.*;
import java.util.Scanner;




class NameComparator implements Comparator
{  
   public int compare(Object o1,Object o2)
   {  
     Student s1=(Student)o1;  
     Student s2=(Student)o2;  
     return s1.name.compareTo(s2.name);  
   }  
}
 


class Student
{  
   int rollno;  
   String name;  
   int age;  
   
   Student(int rollno,String name,int age)
   {  
     this.rollno=rollno;  
     this.name=name;  
     this.age=age;  
   }  
}



class ArraylistSort
{  
  public static void main(String args[])
   {  
     ArrayList<Student> al = new ArrayList<Student>();  
     
     al.add(new Student(101,"Vijay",23));  
     al.add(new Student(106,"Ajay",27));  
     al.add(new Student(105,"Jai",21));  
  
     System.out.println("Sorting by Name...");  
  
     //If we sor array list we use Sollection.sort(name, .....(comparator optional))
     Collections.sort(al, new NameComparator());  
     
     
     for(Student st : al)
     {
         System.out.printf("%d %d %s\n",st.rollno, st.age, st.name);
     } 

     
   } 
}
   
  
