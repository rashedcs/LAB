//Even and odd Component
//even(t)=(x(t)+x(-t))/2  odd(t)=(x(t)-x(-t))/2

#include<stdio.h>
int main()
{
    int x_start,x_end,i,j;
    printf("Enter starting point of signal: ");
    scanf("%d",&x_start);
    printf("Enter ending point of signal: ");
    scanf("%d",&x_end);
    int x_size=x_end-x_start+1;
    double x[x_size],xn[x_size],xN[x_size],e[x_size],o[x_size];  //x for input signal, xn signal after padding 0, xN signal after reflection, e for even component, o for odd component
    printf("Enter sequences: ");
    for(i=0;i<x_size;i++)
    {
        scanf("%lf",&x[i]);
    }

    int temp_end=x_end,temp_start=x_start,z_start=0,z_end=0,z_size=0;
    //finding maximum distance of sample either in negative side or in positive side
    if(x_end<0)
    {
         temp_end=x_end*(-1);

    }

    else if(x_start<0)
    {

        temp_start=x_start*(-1);
    }

    else
    {

        temp_start=x_start;
        temp_end=x_end;
    }

//finding the sample range of even signal and odd signal
    if(temp_start<temp_end)
    {

            z_start=temp_end*-1;
        z_end=temp_end;
    }

    else
    {

        z_start=temp_start*-1;
        z_end=temp_start;
    }

    z_size=z_end-z_start+1;

    for(i=0;i<z_size;i++)
    {
        xn[i]=0.0;
        xN[i]=0.0;
        e[i]=0.0;
        o[i]=0.0;
    }
//calculate xn after padding necessary 0 and xN after reflection and padding necessary 0
      if(temp_start<temp_end)
      {
            j=0;

            for(i=(z_size-x_size);i<z_size;i++)
            {
                xn[i]=x[j];
                j=j+1;
            }

            j=x_size-1;
            for(i=0;i<x_size;i++)
            {
                 xN[i]=x[j];
                 j=j-1;
            }

      }


  else
  {
       for(i=0;i<x_size;i++)
       {
           xn[i]=x[i];
       }
        j=x_size;
        for(i=(z_size-x_size);i<z_size;i++)
        {
            xN[i]=x[j];
            j=j-1;
        }

  }


//calculating even and odd component
    for(i=0;i<z_size;i++)
    {
         e[i]=((xn[i]+xN[i])/2);

         o[i]=(xn[i]-xN[i])/2;
    }
    printf("\nOriginal signal: ");
    for(i=0;i<z_size;i++)
    {
         printf("%0.1f  ",xn[i]);
    }
     printf("\n\nReflected signal: ");
     for(i=0;i<z_size;i++)
    {
         printf("%0.1f  ",xN[i]);
    }
    printf("\n\nEven:  ");
   for(i=0;i<z_size;i++)
    {
         printf("%.1f  ",e[i]);
    }
     printf("\n\nOdd:  ");
   for (i=0;i<z_size;i++)
    {
         printf("%.1f  ",o[i]);
    }
    printf("\n");
  return 0;
}


