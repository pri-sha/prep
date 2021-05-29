import java.util.ArrayList;

class keypad_encoding{

    static String[] keys={".","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};

    static ArrayList<String> key(String str,int idx){
         
        if(str.length()==idx){

            ArrayList<String> base= new ArrayList<> ();
            base.add("");
            return base;
        } 
        ArrayList<String> rec=key(str,idx+1);
        char ch=str.charAt(idx);

        String temp=keys[ch-48];
        ArrayList<String> ans=new ArrayList<> ();

        for(int i=0;i<rec.size();i++){
            for(int j=0;j<temp.length();j++){

                ans.add(temp.charAt(j)+ rec.get(i));


            }
        }

        return ans;
    }
//========================================================================

static ArrayList<String> per(String str){


        if(str.length()==0){

            ArrayList<String> base= new ArrayList<> ();
            return base;

        }
         
        if(str.length()==1){

            ArrayList<String> base= new ArrayList<> ();
            base.add(str);
            return base;
        } 

        ArrayList<String> rec=per(str.substring(1));
        
        ArrayList<String> ans=new ArrayList<> ();

        for(int i=0;i<rec.size();i++){
            String temp=rec.get(i);
            for(int j=0;j<=temp.length();j++){

                ans.add(temp.substring(0,j) + str.charAt(0) + temp.substring(j,temp.length()));


            }
        }

        return ans;
    }

    public static ArrayList<String> encoding(String ques){
        if(ques.length()==0){
            ArrayList<String> base=new ArrayList<>();
            base.add("");
            return base;
        }

        char ch=ques.charAt(0);
        ArrayList<String> myAns=new ArrayList<>();

        if(ch=='0'){
            return encoding(ques.substring(1));
        }else{
            ArrayList<String> recAns=encoding(ques.substring(1));
            for(String s: recAns){
              char ch1=(char)('a'+ ch-'1');
                myAns.add(ch1+s);
            }
        }

        if(ques.length()>1){
            // char ch1 = ques.charAt(1);
            // int num  = (ch-'0')*10 + (ch1-'0');
             int num=Integer.parseInt(ques.substring(0,2));
            
            
            if(num<27){
                ArrayList<String> recAns=encoding(ques.substring(2));
                for(String s: recAns){
                  char ch1=(char)('a'+ num-1);
                    myAns.add(ch1+s);
                }   
            } 

        }

        return myAns;
    }



    public static void main(String[] args){

        //System.out.println(key("765",0));
       // System.out.println(per("abc"));
        System.out.println(encoding("1023"));
    
    }
}