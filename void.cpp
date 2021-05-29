#include<iostream>
#include<vector>
using namespace std;



void subseq(string ques,string ans){
    if(ques.length()==0){
        cout<<ans<<endl;
        return;
    }

    subseq(ques.substr(1),ans+ques[0]);
    subseq(ques.substr(1),ans);
}

/*void subseq_1(string ques,string ans){
    if(ques.length()==0){
        cout<<ans<<endl;
        return;
    }

    subseq(ques.substr(1),ans+ques[0]);
    subseq(ques.substr(1),ans);

    if(ques.length()==2){
        if()
    }
}

void keypad(string ques,string ans){

    string words[] = {"","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
    if(ques.length()==0){
        cout<<ans<<endl;
        return;
    }

    int idx=ques[0]-'0';
    string word=words[idx];


    for(int i=0;i<word.length();i++){
        keypad( ques.substr(1) , ans+word[i]);
    }
}

void keypad_1(string ques,string ans){

    string words[] = {"","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz",".,",";:"};
    if(ques.length()==0){
        cout<<ans<<endl;
        return;
    }

    int idx=ques[0]-'0';
    string word=words[idx];


    for(int i=0;i<word.length();i++){
        keypad_1( ques.substr(1) , ans+word[i]);
    }

    if(ques.length()>=2){
        int idx1= idx*10 +(ques[1-'0']);
        
        if(idx1>=10 && idx1<=11){

            word=words[idx1];
            for(int i=0;i<word.length();i++){
            keypad_1(ques.substr(1) , ans+word[i]);}
        }

    }
}

*/

void per(string ques,string ans){

    if(ques.length()==0){
        cout<<ans<<endl;
        return;
    }
    
    for(int i=0;i<ques.length();i++){
    string nques=ques.substr(0,i)+ques.substr(i+1);
    per(nques,ans+ques[i]);
    }
}

void per_1(string ques,string ans){

    if(ques.length()==0){
        cout<<ans<<endl;
        return;
    }

    vector<bool> vis(26,0);
    
    for(int i=0;i<ques.length();i++){

        if(!vis[ques[i]-'a']){

            vis[ques[i]-'a']=true;
            string nques=ques.substr(0,i)+ques.substr(i+1);
            per_1(nques,ans+ques[i]);
        }
    }
}

void per_bool(string ques,string ans){

    if(ques.length()==0){
        cout<<ans<<endl;
        return;
    }

    int vis=0;
    
    
    for(int i=0;i<ques.length();i++){
        int mask = 1<<(ques[i]-'a');
        if((vis&mask)==0){
            vis |= mask;
            string nques=ques.substr(0,i)+ques.substr(i+1);
            per_bool(nques,ans+ques[i]);
        }
    }
}


int main(int args,char** argv){
    //subseq("abc","");
    //keypad("74","");
    //keypad_1("675","");
    //per("abc","");
    // per_1("aba","");
    per_bool("aba","");


}