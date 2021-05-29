#include<iostream>
#include<vector>

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

void remove_edge(int u,int v){
    int i=0;
    while(i<graph[u].size()){
        Edge* e=graph[u][i];
        if(e->v==v){
            break;
        }
        i++;
    }

    int j=0;
    while(j<graph[v].size()){
        Edge* e=graph[v][j];
        if(e->v==u){
            break;
        }
        j++;
    }

    graph[u].erase(graph[u].begin()+i);
    graph[u].erase(graph[v].begin()+j);
}

void remove_vtx(int u,int v,int w){

    while(graph[u].size()!=0){

        Edge* e=graph[u][graph[u].size()-1];
        erase(Edge(u,e->v));

    }

}

void has_path(int src,int dest,vector<bool> & vis,string psf){
    cout<<psf<<endl;
    vis[src]=true;

    for(Edge* e:graph[src]){

        if(!vis[e->v]){
            has_path(e->v ,dest ,vis ,psf + to_string(e->v));

        }
        vis[src]=false;
    }

}

void all_path(int src,int dest,vector<bool> & vis,string psf){
    cout<<psf<<endl;
    vis[src]=true;

    for(Edge* e:graph[src]){

        if(!vis[e->v]){
            has_path(e->v ,dest ,vis ,psf + to_string(e->v));

        }
        vis[src]=false;
    }

}

int swsf=1e8;
string spsf=" ";

int lwsf=-1;
string lpsf=" ";

if(wsf<swsf){
    swsf=wsf;
    spsf=psf;
}

if(wsf>lwsf){
    lwsf=wsf;
    lpsf=psf;
}

void allsolution(int src,vector<bool> & vis, int wsf ,string psf){
    if(src== dest)
    vis[src]=true;

    for(Edge* e:graph[src]){

        if(!vis[e->v]){
            allsolution(e->v,vis,wsf + e->w ,psf + to_string(e->v));

        }
        vis[src]=false;
    }
}

void dfs(int src,vector<bool> &vis){
    vis[src]=true;

    for(Edge* e:graph[src]){

        if(!vis[e->v])
            dfs(e->v,vis);
    }
}

//gcc -> get connected component

int main(int args,char** argv){

    const_edge();
}
