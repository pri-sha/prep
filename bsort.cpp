#include<iostream>
#include<vector>
using namespace std;

void input(vector<int> & arr)
{for(int i=0;i<arr.size();i++)
 {cin>>arr[i];
 }
}   

void swap1(vector<int> & arr ,int  i , int  j)
{
 int temp=0;
 temp=arr[i];
 arr[i]=arr[j];
 arr[j]=temp;   
}

void display(vector<int> & arr)
{for(int i=0;i<arr.size();i++)
 {cout<<arr[i]<<" ";
 }
}   


void bs(vector<int> & arr)
{
 for(int i=0;i<arr.size();i++)
 {
  for(int j=1;j<arr.size()-i;j++)
  {
   if(arr[j-1]>arr[j])
   {
       swap1(arr,j-1,j);
     }
  }   
 }

}

int main(int args ,char** argv)
{
  int n;

  cout<<"enter array limit";
  cin>>n;

  vector<int> arr(n,0);

  cout<<"enter array elements";
  input(arr);

  bs(arr);

  display(arr);

  return(0);

}