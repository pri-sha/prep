#include<iostream>
#include<vector>
using namespace std;

vector<string> mazePath_D(int sr,int sc,int er,int ec)
{
 vector<string> myAns;

 if(sr==er && sc==ec)
 {
  vector<string> base;
  base.push_back(" ");
  return base;
 }

 if(sc+1<=ec)
 {
  vector<string> hori=mazePath_D(sr,sc+1,er,ec);
  for(string s:hori)
  {
   myAns.push_back("H"+s);   
  }   

 }

 if(sr+1<=er)
 {
  vector<string> vert=mazePath_D(sr+1,sc,er,ec);
  for(string r:vert)
  {
   myAns.push_back("V"+r);   
  }   

 }

 if(sr+1<=er && sc+1<=ec )
 {
  vector<string> diag=mazePath_D(sr+1,sc+1,er,ec);
  for(string t:diag)
  {
   myAns.push_back("D"+t);   
  } 

 }
 
 return myAns;
}

vector<string> mazePath_D_2(int sr,int sc,int er,int ec)
{
 vector<string> myAns;
 
 
 if(sr==er && sc==ec)
 {
  vector<string> base;
  base.push_back(" ");
  return base;
 }

 for(int jump;sc+jump<=ec;jump++)
 {
  vector<string> hori=mazePath_D_2(sr,sc+jump,er,ec);
  for(string s:hori)
  {
   myAns.push_back("H"+ to_string(jump) +s);   
  }   
  
  
 }

 for(int jump;sc+jump<=ec;jump++)
 {
  vector<string> hori=mazePath_D_2(sr,sc+jump,er,ec);
  for(string s:hori)
  {
   myAns.push_back("H"+ to_string(jump) +s);   
  }   
  
  
 }
 if(sr+1<=er && sc+1<=ec )
 {

 }


}

int main(int args,char** argv)
{
  mazePath_D(0,0,3,4);
  return 0;

}