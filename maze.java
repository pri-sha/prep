import java.util.ArrayList;
class maze{

   static ArrayList<String> maze01(int r,int c,int er,int ec){
     if(r==er && c==ec){
         ArrayList<String> base=new ArrayList<>();
         base.add("");
         return base;
     }


      ArrayList<String> H=new ArrayList<>();
      ArrayList<String> V=new ArrayList<>();
      ArrayList<String> D=new ArrayList<>();
      ArrayList<String> ans=new ArrayList<>();

      if(c<=ec){
          
        H=maze01(r,c+1,er,ec);//hori
         for(String s:H){
          ans.add("H"+s);
        }
      }
      if(r<=er){
        V=maze01(r+1,c,er,ec);//vert
         for(String s:V){
          ans.add("V"+s);
       }

      }
      if(r<=er && c<=ec){
        D=maze01(r+1,c+1,er,ec);//vert
         for(String s:D){
          ans.add("D"+s);
        }

      }


     
     
     

      return ans;


   }

  
//============================================================================================

static ArrayList<String> maze02(int r,int c,int er,int ec){
     if(r==er && c==ec){
         ArrayList<String> base=new ArrayList<>();
         base.add("");
         return base;
     }

     
      ArrayList<String> H=new ArrayList<>();
      ArrayList<String> V=new ArrayList<>();
      ArrayList<String> D=new ArrayList<>();

      ArrayList<String> ans=new ArrayList<>();
      
      for(int i=1;i<=2;i++)
      if(c<=ec){
          
        H=maze02(r,c+i,er,ec);//hori

         for(String s:H){
          ans.add("H"+i+s);
          }
      }

      for(int j=1;j<=2 ;j++)  
      if(r<=er){
        V=maze02(r+j,c,er,ec);//vert
         for(String s:V){
          ans.add("V"+j+s);
      }

      }

      for(int i=1;i<=2;i++)
      if(c<=ec && r<=er){
          
        D=maze02(r+i,c+i,er,ec);//diag

         for(String s:D){
          ans.add("D"+i+s);
          }
      }

      return ans;


   }

   //============================================================
   static ArrayList<String> flood_fill_01(int r,int c,int er,int ec,boolean[][] check,int[][] board){
     if(r==er && c==ec){
         ArrayList<String> base=new ArrayList<>();
         base.add("");
         return base;
     }

        int[][]   dir={{0,1},{0,-1},{1,0},{-1,0}};
        char[]    dir1={'R','L','D','U'};

        

      
      ArrayList<String> ans=new ArrayList<>();


      for(int i=0;i<4;i++)
      {
         int x=r+dir[i][0];
         int y=c+dir[i][1];
         check[r][c]=true;


         if(x>=0 && y>=0 && x<=er && y<=ec && !check[x][y] && board[x][y]==0)
         {
            ArrayList<String> rec= flood_fill_01(x,y,er,ec,check,board);

            for(String s:rec)
            {
                ans.add(dir1[i]+s);
            }
         }

            check[r][c]=false;


      }
      
      return ans;


   }

   //============================================================
   static ArrayList<String> flood_fill_8dir(int r,int c,int er,int ec,boolean[][] check){
     if(r==er && c==ec){
         ArrayList<String> base=new ArrayList<>();
         base.add("");
         return base;
     }

        int[][]   dir={{0,1},{0,-1},{1,0},{-1,0},{-1,1},{-1,-1},{1,-1},{1,1}};
        char[]    dir1={'R','L','D','U','1','2','3','4'};

        

      
      ArrayList<String> ans=new ArrayList<>();


      for(int i=0;i<8;i++)
      {
         int x=r+dir[i][0];
         int y=c+dir[i][1];
         check[r][c]=true;


         if(x>=0 && y>=0 && x<=er && y<=ec && !check[x][y])
         {
            ArrayList<String> rec= flood_fill_8dir(x,y,er,ec,check);

            for(String s:rec)
            {
                ans.add(dir1[i]+s);
            }
         }

            check[r][c]=false;


      }
      
      return ans;


   }
   //===========================================================================
   static ArrayList<String> knight_move(int r,int c,int er,int ec,boolean[][] check){
     if(r==er && c==ec){
         ArrayList<String> base=new ArrayList<>();
         base.add("");
         return base;
     }

        int[][]   dir={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
        char[]    dir1={'1','2','3','4','5','6','7','8'};

        

      
      ArrayList<String> ans=new ArrayList<>();


      for(int i=0;i<8;i++)
      {
         int x=r+dir[i][0];
         int y=c+dir[i][1];
         check[r][c]=true;


         if(x>=0 && y>=0 && x<=er && y<=ec && !check[x][y])
         {
            ArrayList<String> rec= knight_move(x,y,er,ec,check);

            for(String s:rec)
            {
                ans.add(dir1[i]+s);
            }
         }

            check[r][c]=false;


      }
      
      return ans;


   }
   //=====================================================================================

    public static void main(String[] args){
      //System.out.println(  maze01(0,0,2,2));
       //System.out.println(  maze02(0,0,2,2)); 

      // int[][] board={
      //     {0,0,0,0},
      //     {0,0,1,0},
      //     {0,1,0,0},
      //     {0,1,0,0},
      // };
       boolean[][] check=new boolean[3][3];
      // System.out.println((flood_fill_01(0,0,3,3,check,board)).size());
      // System.out.println(flood_fill_01(0,0,3,3,check,board));

      // System.out.println((flood_fill_8dir(0,0,2,2,check)).size() );
      // System.out.println(flood_fill_8dir(0,0,2,2,check));

       System.out.println((knight_move(0,0,2,2,check)).size() );
       System.out.println(knight_move(0,0,2,2,check));


    }
}