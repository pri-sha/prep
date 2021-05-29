#include<iostream>
#include<vector>

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool> 

using namespace std;

void nqueen_comb(vector<bool>& box,int lqpl,int qpsf,int tnq,string ans){
    if(qpsf==tnq){
        cout<<ans<<endl;
        return;
    }

    for(int i=lqpl;i<=box.size();i++){

        nqueen_comb(box,i+1,qpsf+1,tnq,ans+"b"+to_string(i)+"q"+to_string(qpsf));

    }
}

int nqueen_per(vector<bool>& box,int lqpl,int qpsf,int tnq,string ans){
    if(qpsf==tnq){
        cout<<ans<<endl;
        return 1;
    }

    for(int i=0;i<=box.size();i++){
        if(!box[i]){
            box[i]=true;
            nqueen_per(box,i+1,qpsf+1,tnq,ans+"b"+to_string(i)+" "+"q"+to_string(qpsf)+"  ");
            box[i]=false;
        }
    }
}

int queen2D_com(vector<vector<bool>> & board,int lqpl,int qpsf,int tnq,string ans ){
    if(qpsf==tnq){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;

    for(int i=lqpl;i<(board.size())*(board[0].size());i++){

        int x=i/(board[0].size());
        int y=i%(board[0].size());
        
        count+=queen2D_com(board,i+1,qpsf+1,tnq,ans+"("+to_string(x)+","+to_string(y)+")");
    }

    return count;
}

int queen2D_per(vector<vector<bool>> & board,int qpsf,int tnq,string ans ){
    if(qpsf==tnq){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;

    for(int i=0;i<(board.size())*(board[0].size());i++){

        int x=i/(board[0].size());
        int y=i%(board[0].size());

        if(!board[x][y]){

            board[x][y]=true;
            count+=queen2D_per(board,qpsf+1,tnq,ans+"("+ to_string(x) + "," + to_string(y) + ")" );
            board[x][y]=false;
    
        }

        }
        return count;
}

bool IsSafeToPlaceQueen_c(vector<vector<bool>> & board,int x,int y){
    vector<vector<int>> dir={{-1,0},{0,-1},{-1,-1},{-1,1}};
    for(int i=0;i<dir.size();i++){
        for(int rad=1;rad<max((board.size()),(board[0].size()));rad++){
            int nx= x+rad*dir[i][0];
            int ny= y+rad*dir[i][1];
            if(nx<0 || ny<0 || nx>=board.size() || ny>=board[0].size()){
                break;
            }
            if(board[nx][ny])
                return false;
            
        }
    }
    return true;
    
}

bool IsSafeToPlaceQueen_p(vector<vector<bool>> & board,int x,int y){
    vector<vector<int>> dir={{-1,0},{0,-1},{-1,-1},{-1,1},{1,0},{0,1},{1,1},{1,-1}};
    for(int i=0;i<dir.size();i++){
        for(int rad=1;rad<max((board.size()),(board[0].size()));rad++){
            int nx= x+rad*dir[i][0];
            int ny= y+rad*dir[i][1];
            if(nx<0 || ny<0 || nx>=board.size() || ny>=board[0].size())
            break;
                if(board[nx][ny])
                return false;
            
        }
       
    }
     return true;

}

int chess_queen2D_com(vector<vector<bool>> & board,int lqpl,int qpsf,int tnq,string ans ){
    if(qpsf==tnq){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;

    for(int i=lqpl;i<(board.size())*(board[0].size());i++){
        
        int x=i/(board[0].size());
        int y=i%(board[0].size());

        if(IsSafeToPlaceQueen_c(board,x,y)){
        board[x][y]=true;
        count+= chess_queen2D_com(board,i+1,qpsf+1,tnq,ans+"("+to_string(x)+","+to_string(y)+")");
        board[x][y]=false;
        }
    }

    return count;
}

int chess_queen2D_per(vector<vector<bool>> & board,int lqpl,int qpsf,int tnq,string ans ){
    if(qpsf==tnq){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;

    for(int i=0;i<(board.size())*(board[0].size());i++){
        
        int x=i/(board[0].size());
        int y=i%(board[0].size());

        if( !board[x][y] && IsSafeToPlaceQueen_p(board,x,y)){
        board[x][y]=true;
        count+=chess_queen2D_per(board,i+1,qpsf+1,tnq,ans+"("+to_string(x)+","+to_string(y)+")");
        board[x][y]=false;
        }
    }

    return count;
}


int queen_bit(int n, int r, int col, int diag, int adiag, int tnq, string ans){
    if(tnq==0 ){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;

    for(int c=0; c<=n ;c++){

        int w=1<<c ;
        int x=1<<r+c;
        int y=1<<r-c+n-1;

        if(!(col&w) && !(diag&x) && !(adiag&y)){
            col  ^=w;
            diag ^=x;
            adiag^=y;

            count+=queen_bit(n,r+1,col,diag,adiag,tnq-1, ans+ "(" + to_string(r) + "," + to_string(c) + ")" );

            col   ^=w;
            diag  ^=x;
            adiag ^=y;

        }
    }
}

int sudoku(vvi &board, vi )
int main(int args,char** argv){

    vector<bool> box(4,0);
    vector<vector<bool>> board(4,vector<bool> (4,false) );

    int r=4 ,c=4 ;

    //nqueen_comb(box,0,0,3," ");
    //nqueen_per(box,0,0,3," ");
    //cout<<queen2D_com(board,0,0,4," ");
    //cout<<queen2D_per(board,0,4," ");
    //cout<<chess_queen2D_com(board,0,0,4," ");
    //cout<<chess_queen2D_per(board,0,0,4," ");
    int col=0;
    int diag=0;
    int adiag=0;

    cout<<queen_bit(r,0,col,diag,adiag,4," ");

}