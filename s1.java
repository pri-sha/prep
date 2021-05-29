import java.util.Scanner;

public class s1{

    private int[10] arr;
    private int idx;
    private long size;

    public stack(){
        this.arr[0]=50;
        this.idx=0;
    }

    public stack(int ar){
        this.arr[]=ar;
    }

    protected void stack_push_(){
        this.arr[++idx]=val;
        this.size++;
    }

    public void stack_push(int val){
        if(this.size== 0{
            throw new Exception("Stack is empty" + -1);
        }
        
        return stack_push_();
    }

    protected int stack_top_(){
        return this.arr[this.idx];
    }


    public int stack_top() throws Exception{
        if(this.size== 0{
            throw new Exception("Stack is empty" + -1);
        }
        return stack_top_();
    }

    public int stack_pop(){
        if(this.size== maxSize()){
        throw new Exception("Stack is empty" + -1);
    }

    this.arr[this.idx]=0;
    this.idx--;
    this.size--;

    }

    public long stack_size(){
        /*for(int i=0 ; idx!=-1 ;i++){
            this.idx--;
        }

        return i;*/
    
        return this.size;
    }

    public boolean stack_isEmpty(){
        
        return this.size==0;
    }
}

    stack st = new  stack();
}