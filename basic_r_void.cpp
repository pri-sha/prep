#include<iostream>
using namespace std;

void subseq(string ques,string ans)
{
 if (ques.length()==0)
 {
  cout<<ans<<endl;
  return;   
 }

 char ch=ques[0];
 subseq(ques.substr(1),ans+ch);
 subseq(ques.substr(1),ans);

}

void subseq_a(string ques,string ans)
{
 if (ques.length()==0)
 {
  cout<<ans<<endl;
  return;   
 }

 char ch=ques[0];
 //here change ch into a char with it's ascii value
 int ch_=ques[0];
 subseq_a(ques.substr(1),ans+ch);
 subseq_a(ques.substr(1),ans);
 subseq_a(ques.substr(1),ans+ to_string(ch_));

}

void permutation(string ques,string ans)
{
 if (ques.length()==0)
 {
  cout<<ans<<endl;
  return;   
 }

 int i;
 for( i ; i<ques.length(); i++)
 {
  string nques=ques.substr(0,i)+ques.substr(i+1);
  permutation(nques,ans+ques[i]);
 }
}

void permutation_non_rep(string ques,string ans)
{
 if (ques.length()==0)
 {
  cout<<ans<<endl;
  return;   
 }

 int i;
 int arr[26]={0};
 for( i ; i<ques.length(); i++)
 {
  if(arr[ques[i]-'a']==0)
  {   
   arr[ques[i]-'a']=1;
   string nques=ques.substr(0,i)+ques.substr(i+1);
   permutation_non_rep(nques,ans+ques[i]);
  } 
 }
}

int main(int args ,char** argv)
{
 subseq();
 subseq_a();
 permutation();
 permutation_non_rep();

}