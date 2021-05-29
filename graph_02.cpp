#include<iostream>
#include<vector>
#include<queue>

using namespace std;

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

class pair_
{
    int vtx=0;
    int parent=0;
    int w=0;
    int wsf=0;

    pair_(int vtx, int parent, int w, int wsf)
    {
        this->vtx=vtx;
        this->parent=parent;
        this->w=w;
        this->wsf=wsf;

    }

}

void main(int args,char** argv)
{
    const_edge();
}