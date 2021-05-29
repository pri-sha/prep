#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> & arr,int vidx)
{
 if(vidx==arr.size())
 {return;
  }   
 cout<<arr[vidx]<<"  ";
 display(arr,vidx+1);   
}

bool find(vector<int> & arr,int vidx,int data)
{
 if(vidx==arr.size())
 {return 0 ;
  }  

 if(arr[vidx]==data)
 {return true;
  }

 find(arr,vidx+1,data);   
}

int maxm(vector<int> & arr,int vidx)
{
 if(arr[vidx]==arr.size())
 {return arr[vidx];
 }

 int res=maxm(arr,vidx+1);
}

void solve()
{
 vector<int> arr={10,6,8,10,4,5,5,6,8,-3,2,12,8,3};
 display(arr,0);
 
 cout<<endl;
 int data;

 cout<<"enter data you want to find";
 cin>>data;
 cout<<find(arr,0,data);

 cout<<endl;
 cout<<maxm(arr,0);

}

int main(int args,char** argv)
{
 solve();   
 
 return(0);

}