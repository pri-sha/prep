#include<iostream>
using namespace std;

string words[]={".,:;","abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz","@$&","_-+"}

int keypad(string ques,string ans)
{
    if(ques.length()==0)
    {
        count<<ans<<endl;
        return 1;
    }

    int idx=ques[0]-'0';
    int count=0;
    string word=words[idx];

    for(int i=0; i<word.length(); i++)
    {
        count+=keypad(ques.substr(1),ans+word[i]);
    }

    if(ques.length()>=2)
    {
        idx=(ques[0]-'0')*10 + (ques[0]-'0');

        if(idx>=10 && idx<12)
        {
            word=words[indx];

            for(int i=0; i<word.length(); i++)
            count+=keypad(ques.substr(2),ans+word[i]);
    
        }
    }
}



int main(int args ,char** argv)
{
    keypad("456","");
}