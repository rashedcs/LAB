
import java.util.Scanner;
//import java.util.Random;

 class Ideone {

	public static double mean(double[] m)
	{
	    double sum = 0;
	    for (int i=0; i<m.length; i++)
	    {
	        sum += m[i];
	    }
	    return sum / m.length;
	}


	public static double median(double[] m)
	 {
	    int middle = m.length/2;
	    if (m.length%2 == 1)
	    {
	        return m[middle];
	    }
	    else
	    {
	        return (m[middle-1] + m[middle]) / 2.0;
	    }
	 }


	public static double standardDeviation(double[] m)
	{
	        double mean = mean(m);

	        //Variance Calculation
	        double temp = 0;
	        for(int i=0; i<m.length; i++)
	        {
	        	 temp += (i-mean)*(i-mean);
	        }

	        double variance = temp/m.length;

	        return Math.sqrt(variance);  //Standard Deviation

         }

	public static void main(String[] args)
	{
	  //5,9,10,49,48
	  Scanner s = new Scanner(System.in);
	 // System.out.println("Enter the number of Elements : ");
	  int n = s.nextInt();
	  double arr[] = new double[n];
	  //System.out.println("Enter elements :");
	 // Random rn = new Random();

      for(int i =0; i<n; i++)
      {
        //int answer = rn.nextInt(10) + 1;
        arr[i] = (int)(Math.random() * 100);
      }
   
	  for(int i=0; i<n; i++)
	  {
		   System.out.println(arr[i]);
	  }
	  
	  System.out.println("");
	  System.out.println(mean(arr));
	  System.out.println(median(arr));
	  System.out.println(standardDeviation(arr));
    }
}

	
