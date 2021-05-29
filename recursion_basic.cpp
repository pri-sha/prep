#include<iostream>
#include<vector>
using namespace std;

void printInc(int st,int end)
{
  if(st==end+1)
  return;
  cout<<st<<" ";
  printInc(st+1,end);  
}

void printDec(int st,int end)
{
  if(st==end+1)
  return;
  printDec(st+1,end);  
  cout<<st<<" ";
}

//return type wale method se
int R_printInc(int st,int end)
{
  if(st==end)
  {

   return st-1;
  }

  int head=R_printInc
}

void R_printDec(int st,int end)
{
  if(st==end)
  {
   cout<<st<<" ";
   return st-1;
  }

  int head=R_printDec(st+1,end);
  cout<<head<<" ";
  return head-1;
}

int main(int args ,char** argv)
{
 int st,end;
 cout<<"enter start and end points";
 cin>>st>>end;

 printInc(st,end);
 cout<<endl;
 printDec(st,end);   

 return(0);
}