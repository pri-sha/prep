#include<iostream>
#include<vector>
#include<queue>

using namespace std;
class Edge{

    public:
    int w=0;
    int v=0;

    Edge(int v,int w){
        this->v=v;
        this->w=w;

    }
};

int n=7;
vector<vector<Edge*>> graph(n,vector<Edge*>());

void display(){

for(int j=0; j < graph.size() ;j++ ){
    cout<<j <<"->";
            
    for(Edge* e:graph[j]){
        cout<< "(" << e->v << "," << e->w << ")" ;

        }
        cout<<endl;
    }
}

void addEdge(int u, int v, int w){

    if(u<0 || v<0 || u>=graph.size() || u>=graph.size()){
        return;
    }

    graph[u].push_back(new Edge(v,w));
    graph[v].push_back(new Edge(u,w));
}

void const_edge(){

    addEdge(0,1,10);
    addEdge(1,2,10);
    addEdge(0,3,10);
    addEdge(2,3,40);
    addEdge(3,4,2);
    addEdge(5,6,8);
    addEdge(4,5,2);
    addEdge(4,6,3);

    display();

}

void bfs(int src){
    queue<int> que;

    vector<bool> vis(n,false);
    que.push(src);
    que.push(-1);

    int cycle=0;
    int level=0;

    int dest=6;

    while(que.size()!=1){
        int rvtx=que.front();
        que.pop();

        if(vis[rvtx]){
            cout<<"cycle:"<<++cycle<<" @ "<<rvtx<<endl;
            continue;
        }

        if(rvtx==dest){
            cout<<"destination reached in :"<<level<<endl;
        }
           
        vis[rvtx]=true;
        for(Edge* e:graph[rvtx]){
            if(!vis[e->v]){
                que.push(e->v);
            }
        }

        if(que.front()==-1){
            level++;
            que.pop();
            que.push(-1);
        }
    }

}

void bfs2(int src){

    queue<int> que;

    vector<bool> vis(n,false);
    que.push(src);
    que.push(-1);

    int cycle=0;
    int level=0;

    int dest=6;
    bool isDest=false;

    while(que.size()!=0){
        int size=que.size();


        while(size-->0){
            int rvtx=que.front();
            que.pop();
            
            if(que.front()==-1){
            level++;
            que.pop();
            que.push(-1);
            }
        
            if(vis[rvtx]){
                cout<<"cycle:"<<++cycle<<" @ "<<rvtx<<endl;
                continue;
            }

            if(rvtx==dest){
                cout<<"destination reached in :"<<level<<endl;
            }
   
            vis[rvtx]=true;
            for(Edge* e:graph[rvtx]){
                if(!vis[e->v]){
                    que.push(e->v);
                }
            }
            level++;
        }
    }
}

int hamintonain_path(int vtx , int osrc , int count_vtx , vector<bool>& vis , string ans){
    if(count_vtx == graph.size()-1)
    {   
        bool flag=false;

        for(Edge* e:graph[vtx])
        {
            if(e->v == osrc)
            {
                cout<<"cycle:"<<ans+to_string(vtx)<<endl;
                flag=true;
            }
        }

        if(!flag)
        cout<<"path:"<<ans+to_string(vtx)<<endl;
            
        return 1;
    }

    vis[vtx]=true;

    for(Edge *e : graph[vtx] ){

        if(!vis[e->v])
        {
            hamintonain_path(e->v , osrc , count_vtx++ , vis , ans+to_string(vtx));
        }
        vis[vtx]=false;

    }
} 

/*class ques{

    public:
    int v=0;
    int def=0;

    Edge(int v,int def){
        this->v=v;
        this->def=def;

    } 
}q;
*/

int bi_part(int i, vector<int> &vis)
{   
    queue<pair<int,int>> que;
    bool flag=true;
    que.push({i,0});

    while(que.size()!=0)
    {
        pair<int,int> rvtx = que.front();
        que.pop();

        if(vis[rvtx.first]!=-1)
        {
            if(vis[rvtx.first] != rvtx.second)
            {
                cout<<"conflict"<<endl;
                flag=false;
            }

            continue;
        }

        vis[rvtx.first]=rvtx.second;

        for(Edge* e:graph[rvtx.first])
        {
            if(!vis[e->v])
            que.push({e->v,(rvtx.second+1)%2});
        }

        que.clear();
    }
    return flag;
}

void bi_part0()
{
    vector<int> vis(graph.size(),-1);
    int count=0;

    for(int i=0; i<graph.size(); i++)
    {
        if(vis[i] == -1)
        {
            cout<< count <<" "<<(boolalpha)<<bi_part(i,vis);
            count++;
        }
    }

}

int main(int args,char** argv){

    vector<bool> vis(n,false);
    const_edge();
    //hamintonain_path(0,0,0,vis," ");
    //bfs(0);
    //bfs2(0);
    bi_part0();
}
