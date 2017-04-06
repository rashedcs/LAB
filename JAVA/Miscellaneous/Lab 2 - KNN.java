
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

class Main 
{
	static class sample 
	{
		int label;
		int [] pixels;
	}
	
	private static int distance(int[] a, int[] b) 
	{
		int sum = 0;
		for(int i=0; i<a.length; i++) 
		{
			sum += (a[i] - b[i]) * (a[i] - b[i]);
		}
		return (int)Math.sqrt(sum); // euclidian distance would be sqrt(sum)...
	}
	
	/* Read All File */
	private static List<sample> readFile(String file) throws IOException
	{
		List <sample> list = new ArrayList<sample>();
		BufferedReader reader = new BufferedReader(new FileReader(file));
		try 
		{
			String line = reader.readLine(); // ignore header
			//while((line = reader.readLine()) != null)
			while(line != null)
			{
				String[] tokens = line.split(",");
				sample ob = new sample();
				ob.label = Integer.parseInt(tokens[0]);
				ob.pixels = new int[tokens.length - 1];
				for(int i = 1; i<tokens.length; i++) 
				{
					ob.pixels[i-1] = Integer.parseInt(tokens[i]);
				}
				list.add(ob);
			}	
		}
		finally 
		{ 
			reader.close();
		}
		return list;
	}
	
	
	
	/* Measurement the training set */
	private static int classify(List<sample> trainingSet, int[] pixels) 
	{
		int label = 0, bestDistance = Integer.MAX_VALUE;
		for(sample samples: trainingSet) 
		{
			int dist = distance(samples.pixels, pixels);
			if(dist < bestDistance) 
			{
				bestDistance = dist;
				label = samples.label;
			}
		}
		return label;
	}
	
	public static void main() throws IOException 
	{
		List<sample>trainingSet   = readFile("trainingsample.csv");
		List<sample>validationSet = readFile("validation.csv");
		
		int numCorrect = 0;
		
		for(sample iterator: validationSet) //For some validation data
		{
			if(classify(trainingSet, iterator.pixels)==iterator.label)
			numCorrect++;
		}
		
		System.out.println("Accuracy: " + (double)numCorrect / validationSet.size() * 100 + "%");
	}


















//  http://www.javaengineeringprograms.com/k-nearest-neighbor-program-in-java/
//  http://www.javaengineeringprograms.com/k-nearest-neighbor-program-in-java/
//  http://www.javaengineeringprograms.com/k-nearest-neighbor-program-in-java/
import java.io.*;
import java.util.*;
import java.util.Scanner;
import java.util.Collections;

class Result
{
	 private String[] group = new String[20];
	 private int index=0;
	 
	 public void set_group(String group)
	 {
		 this.group[index++]=group;
	 }
	 public String get_group(int index)
	 {
		 return this.group[index];
	 }
 }
 

class Data
{
	private String group;
	private double distance;
	
	public void setter_group(String group)
	{
		this.group=group;
	}

	public String getter_group()
	{
		return this.group;
	}
	
	public void setter_distance(double distance)
	{
		this.distance=distance;
	}
	
	public double getter_distance()
	{
		return this.distance;
	}
 }



class Checker implements Comparator<Data>
{
  public int compare(Data o1, Data o2)
   {
	   if(o1.getter_distance()==o2.getter_distance())        return 0;  
	   else if(o1.getter_distance()>o2.getter_distance())    return 1;
	   else                                                  return -1;  
   }
} 
 




class KNN
{
	
	public static void main(String args[])
	{
	           Data object[]        = new Data[80];
		   Result result_obj    = new Result();
		   String known_group[] = new String[20];
		 
         	  String str1, str2 ;
      	 
     	          double  efficiency;
     	          int class_counter_A,class_counter_B, correct=0;
		
                  try 
                  {
         	     FileInputStream fstream1 = new FileInputStream("E:\\ObservationalData.txt");
        	     BufferedReader br1       = new BufferedReader(new InputStreamReader(fstream1));
        	
        	     for(int i=0; i<20; i++)
        	     {
        		str1 = br1.readLine();
        		String Line_test_data[] = str1.split(" ");
        
        		known_group[i]=Line_test_data[4];
        		
                         FileInputStream fstream2 = new FileInputStream("E:\\NewSet.txt");
                         BufferedReader br2 = new BufferedReader(new InputStreamReader(fstream2));
             
                         for(int j=0; j<40; j++)
                         {
        			str2 = br2.readLine();
        			String Line_tested_data[] = str2.split(" ");
        			object[j] = new Data();
        			object[j].setter_group(Line_tested_data[4]);
 
        	                double temp1, temp2, distance = 0.0, dist;
                    
                                for(int k=0; k<5; k++) 
            	                {
            	                   temp1 = Double.parseDouble(Line_test_data[k]);
            	                   temp2 = Double.parseDouble(Line_tested_data[k]);
                                   distance += (temp2 - temp1)*(temp1 - temp2);
            	                }
                                dist = Math.sqrt(distance);
            	                object[j].setter_distance(dist);      
        		  } 
                
        		  class_counter_A=0;
        		  class_counter_B=0;
        		
        		  Arrays.sort(object,  new Checker());
        	 	 
        		  for(int k=0; k<5; k++)
        		  {
        			if(object[k].getter_group()=="A")  class_counter_A++;
        			else                               class_counter_B++;
        	 	  }
        		
        		  if(class_counter_A > class_counter_B)  result_obj.set_group("A");
        		  else                                   result_obj.set_group("B");
        		
        		  if(result_obj.get_group(i)==known_group[i])   correct++;
        		
        		  System.out.printf("%s %s\n", result_obj.get_group(i), known_group[i]);
                       }	
                       efficiency = (correct*100)/20;
                       System.out.printf("%lf\n",efficiency);
                  }
		
                  catch(Exception e)
                  {
        	     System.err.printf("Error %s:\n", e.getMessage());
                  }
	    }
       }

/*
import java.io.*;
import java.util.*;
import java.util.Scanner;


class Result
{
	 private String[] group = new String[20];
	 private int index=0;
	 
	 public void set_groupp(String group)
	 {
		 this.group[index++]=group;
	 }
	 public String get_groupp(int index)
	 {
		 return this.group[index];
	 }
 }
 

class DataSet
{
	private String group;
	private double distance;
	
	public void set_group(String group)
	{
		this.group=group;
	}

	public String get_group()
	{
		return this.group;
	}
	
	public void set_distance(double distance)
	{
		this.distance=distance;
	}
	
	public double get_distance()
	{
		return this.distance;
	}
 }



class Checker implements Comparator<DataSet>
{
  public int compare(DataSet o1, DataSet o2)
   {
	   if(o1.get_distance()==o2.get_distance())        return 0;  
	   else if(o1.get_distance()>o2.get_distance())    return 1;
	   else                                            return -1;  
   }
} 
 




class KNN_Problem
{
	public static void main(String args[])
	{
		 DataSet object[]  = new DataSet[80];
		 Result result_obj  = new Result();
		 String known_group[] = new String[20];
      	 String strLine,strLine1;
     	 double p1,p2,p3,p4,q1,q2,q3,q4,distant,efficiency;
     	 int class_counter_A,class_counter_B,correct=0;
		
         try 
         {
        	FileInputStream fstream1 = new FileInputStream("E:\\ObservationalData.txt");
        	BufferedReader br1 = new BufferedReader(new InputStreamReader(fstream1));
        	
        	for(int i=0; i<20; i++)
        	{
        		strLine1 = br1.readLine();
        		String[] Line_test_data = strLine1.split(" ");
        		p1=Double.parseDouble(Line_test_data[0]);
        		p2=Double.parseDouble(Line_test_data[1]);
        		p3=Double.parseDouble(Line_test_data[2]);
        		p4=Double.parseDouble(Line_test_data[3]);
        
        		known_group[i]=Line_test_data[4];
                FileInputStream fstream = new FileInputStream("E:\\NewSet.txt");
                BufferedReader br = new BufferedReader(new InputStreamReader(fstream));
             
                for(int j=0; j<80; j++)
                {
        			strLine = br.readLine();
        			String[] Line_tested_data = strLine.split(" ");
        			object[j] = new DataSet();
        			object[j].set_group(Line_tested_data[4]);
        			
        			q1=Double.parseDouble(Line_tested_data[0]);
            		q2=Double.parseDouble(Line_tested_data[1]);
            		q3=Double.parseDouble(Line_tested_data[2]);
            		q4=Double.parseDouble(Line_tested_data[3]);
            		
            		distant = Math.sqrt(((q1-p1)*(q1-p1)) + ((q2-p2)*(q2-p2)) + ((q3-p3)*(q3-p3))+ ((q4-p4)*(q4-p4)));
            		object[j].set_distance(distant);        		
        		}
                
        		class_counter_A=0;
        		class_counter_B=0;
        		
        		Arrays.sort(object,  new Checker());
    
        		 
        		String test = new String();
        		
        		for(int k=0; k<5; k++)
        		{
        			test=object[k].get_group();
        			if(test.equals("A"))  class_counter_A++;
        			else                  class_counter_B++;
        		}
        		
        		if(class_counter_A > class_counter_B)  result_obj.set_groupp("A");
        		else                                   result_obj.set_groupp("B");
        		
        		
        		if(result_obj.get_groupp(i).equals(known_group[i]))   correct++;
        		
        		System.out.printf("%s %s\n", result_obj.get_groupp(i), known_group[i]);

            }	
        	
             efficiency = (correct*100)/20;
             System.out.printf("%lf\n",efficiency);
          }
          catch(Exception e)
          {
        	 System.err.printf("Error %s:\n", e.getMessage());
          }
	}
 }
*/

