import java.util.Scanner;

public class recursion_basic_J
{
 public static Scanner scn=new Scanner(System.in);

 public static void main(String[] args)
 {
  //System.out.print("enter number whose factorial you want ");   
  //int n=scn.nextInt();

  System.out.print("enter numbers for a power b");   
  int a=scn.nextInt();
  int b=scn.nextInt();
  
  
  //System.out.println(fact(n));   
  
  //System.out.println(a_pow_b(a,b));   
 
  System.out.println(a_pow_b_2(a,b));
 }   

 public static int fact(int n)
 {if (n<=1)
  return 1;

  int res=fact(n-1);
  return res*n;
 } 


 public static int a_pow_b(int a,int b)
  {if (b<1)
   return 1;

   int res=a_pow_b(a,b-1);
   return res*a;
  } 

 public static int a_pow_b_2(int a,int b)
  {
   if (b<1)
    return 1;

   int res=a_pow_b(a,b/2);
   res*=res;
   if(b%2==0)
   {return res;
    }
   else
   {return res*a;
    }
  } 


}

