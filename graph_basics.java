import java.util.Scanner;
import java.util.ArrayList;

public class graph_basics{

    public static Scanner scn=new Scanner(System.in);

    public static class Edge{

        int w=0;
        int v=0;

        Edge(int v,int w){
            this.v=v;
            this.w=w;

        }
    }

    public static ArrayList<ArrayList<Edge>> graph=new ArrayList<>();

    public static void main(String [] args){

        const_edge();

    }

    public static void const_edge(){
        int n=7;
        for(int i=0;i<n;i++){
            graph.add(new ArrayList<>());
        }

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

    public static void addEdge(int u, int v, int w){

        if(u<0 || v<0 || u>=graph.size() || u>=graph.size()){
            return;
        }

        graph.get(u).add(new Edge(v,w));
        graph.get(v).add(new Edge(u,w));
    }

    public static void display(){

        for(int j=0; j < graph.size() ;j++ ){
            System.out.print(j +"->");
            
            for(Edge e:graph.get(j)){
                System.out.print( "(" + e.v + "," + e.w + ")" );

            }
            System.out.println();
        }
    }

    /*public static void remove_edge(int u,int v){
        int i=0;
        while(i<graph.get(u).get(i)){
            Edge e=graph.get
        }
    }
    */

    
}