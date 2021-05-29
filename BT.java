import java.util.Scanner;
import java.util.ArrayList;

public class BT{
    public static class Node{
        int data=0;
        Node left=null;
        Node right=null;

        Node(){

        }

        public Node(int data){
            this.data=data;
        }

        public Node(int data,Node left,Node right){
            this.data=data;
            this.left=left;
            this.right=right;
        }

    }

    static int idx=0;

    public static Node create_tree(int arr[]){
        if(idx==arr.length || arr[idx]==-1){
            idx++;
            return null;
        }

        Node node= new Node(arr[idx]);
        idx++;

        node.left=create_tree(arr);
        node.right=create_tree(arr);

        return node;
    }

    public static void display(Node node){
        if(node=null){
            return ;
        }

        System.out.print(node.left!=null ? node.left.data : ".");
        System.out.print(" -> " + node.data + " <- ");
        System.out.println(node.right!=null ? node.right.data : ".");

        display(node.left);
        display(node.right);        

    }

    public static void maximum_value(Node node){
        if(node == null){
            return (int) -1e8;
        }
        int lmax=maximum_value(node.left);
        int rmax=maximum_value(node.right);
        int omax=Math.max(lmax,rmax);

        return Math.max(node.data, omax);

    }

    public static void size(){
        if(node == null){
            return 0;
        }

        return size(node.left)+size(node.right)+1;

    }

    public static void height(){

    }

    public static boolean find(Node node, int data){
        if(node.data == null){
            return false;
        }

        if(node.data == data){
            return true;
        }

        return find(node.left, data) || find(node.right,data);

        boolean res=false;
        res=res || find(node.left,data);
        res=res || find(node.right,data);

    }

    public static ArrayList<Node> root_to_node_path(Node node,int data){
        if(node.data=data){
            ArrayList<Node> base=new ArrayList<>();
            base.add(node);
            return base;
        }

        ArrayList<Node> left=root_to_node_path(node.left,data);

        ArrayList<Node> right=root_to_node_path(node.right,data);

    }

    public static int LCA(Node node,int data,int data2){
        ArrayList<Node> list1=root_to_node_path(node.left,data);
        ArrayList<Node> list2=root_to_node_path(node.right,data);
    }

    public static void k_down(Node node,Node pnode,int level){  //pnode->prevent node
        if(node== null || node == pnode){
            return;
        }

        if(level == 0){
            System.out.println(node.data+" ");
        }

        k_down(node.left,pnode,level-1);
        k_down(node.right,pnode,level-1);

    }

    public static int k_away(Node node,int k){
        ArrayList<Node> list1=root_to_node_path(node,data);
        Node pnode=null;

        for(int i=0; i < list1.size() ; i++){
            kdown(list1.get(i),pnode,k-i);
            pnode=list1.get(i);
        }
    }
    public static void solve(){
        int[] arr={10 ,20 ,30 ,40 ,-1 ,-1 ,50 ,-1 ,-1 ,60 ,-1 ,70 ,-1 ,-1 ,80 ,90 ,100 ,120 ,-1 ,-1 ,130 ,-1 ,-1 ,110 ,-1 ,-1 ,140 };
        Node root=create_tree(arr);
        display(root);
    }

    public static void main(String[] args){
        solve();
    }
}
