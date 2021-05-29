import java.util.Scanner;

public class recursion_with_array


{
 public static Scanner scn=new Scanner(System.in);

 public static void input(int arr[])
  {for(int i=0;i<arr.length;i++)
   arr[i]=scn.nextInt();
  } 


 public static void main(String[] args)
 {
  System.out.println("enter number of elements you want to enter");
  int n=scn.nextInt();

  int[] arr=new int [n];
  
  System.out.println("enter array elements");
  input(arr);

  System.out.println("enter number you want to find");
  int data=scn.nextInt();
 
  all_index(arr,0,data,a);

 }

 public static int[] all_index(int[] arr,int vidx,int data,int  a)
 {   
  if(vidx==arr.length)
  {
   int[] baseArray=new int [size];
   return baseArray;   
  }
  
  if(arr[vidx]==data)
  a++;

  int[] res = all_index(arr,vidx+1,data,a);

  if(arr[vidx]==data)
  {
   res[size-1]=vidx;
  }

  return res;

 }

}