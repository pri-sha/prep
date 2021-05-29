#include<iostream>
#include<vector>
using namespace std;

/*void per_rep(vector<int>& arr,int tar,string ans){

    if(tar==0){
        cout<<ans<<endl;
        return;
    }

        for(int i=0;i<arr.size();i++){
            if(tar-arr[i]>=0){

                per_rep(arr,tar-arr[i],ans+to_string(arr[i])+"");
            }
        }
}*/

void per_non_rep(vector<int>& arr,vector<bool> vis,int tar,string ans){

    if(tar==0){
        cout<<ans<<endl;
        return;
    }

        for(int i=0;i<arr.size();i++){
            if((tar-arr[i]>=0) && (!vis[i])){
                vis[i]=true;
                per_non_rep(arr,vis,tar-arr[i],ans+to_string(arr[i])+"");
                vis[i]=false;
            }
        }
}

void com_rep(vector<int>& arr,int idx,int tar,string ans){

    if(tar==0){
        cout<<ans<<endl;
        return;
    }

        for(int i=idx;i<arr.size();i++){
            if(tar-arr[i]>=0){

                com_rep(arr,i,tar-arr[i],ans+to_string(arr[i])+"");
            }
        }
}

void com_non_rep(vector<int>& arr,int idx,int tar,string ans){

    if(tar==0){
        cout<<ans<<endl;
        return;
    }

        for(int i=idx;i<arr.size();i++){
            if(tar-arr[i]>=0){

                com_non_rep(arr,i+1,tar-arr[i],ans+to_string(arr[i])+"");
            }
        }
}

void com_rep_ss(vector<int> &arr,int idx,int tar,string ans){
    if( (tar==0) ){
        cout<<ans<<endl;
        return;
    }
    if(idx==arr.size()){
        return ;
    }
    if(tar-arr[idx]>=0){
        com_rep_ss(arr,idx,tar-arr[idx],ans+to_string(arr[idx])+"");
        
    }   
    com_rep_ss(arr,idx+1,tar,ans);
}

int main(int args,char** argv){
    vector<int> arr={2,3,5,7};
    int tar=10;
    vector<bool> vis(arr.size(),0);
    //per_rep(arr,tar,"");
    //per_non_rep(arr,vis,tar,"");
    //com_rep(arr,0,tar,"");
    //com_non_rep(arr,0,tar,"");
    com_rep_ss(arr,0,tar,"");
}