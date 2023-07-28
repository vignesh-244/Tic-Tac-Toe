#include<bits/stdc++.h>
using namespace std;
//To check for condition
int ischeck(vector<vector<char>>mat,int n,int x,int y,int ch){
    if(ch%2==0){
     int col=0,row=0,dig1=0,dig2=0;
     for(int i=0;i<n;i++){
            if(mat[x][i]=='X')row++;//checking the row wise for X
            if(mat[i][y]=='X')col++;//checking the column wise for X
            if(x==y){
                if(mat[i][i]=='X')dig1++;//checking the primary diagonal for x
             }else if(x+y==n-1){
                if(mat[i][n-i-1]=='X')dig2++;//checking the secondary diagonal for X
            }
      }
      if(col==n||row==n||dig1==n||dig2==n)return 1;
      else return 0;
    }
    else{
       int col=0,row=0,dig1=0,dig2=0;
       for(int i=0;i<n;i++){
            if(mat[x][i]=='O')row++;//checking the row wise for O
            if(mat[i][y]=='O')col++;//checking the column wise for O
            if(x==y){
                if(mat[i][i]=='O')dig1++;//checking the primary diagonal for x
             }else if(x+y==n-1){
                 if(mat[i][n-i-1]=='O')dig2++;//checking the secondary diagonal for X
             }
      }
      if(col==n||row==n||dig1==n||dig2==n)return 1;
      else return 0;
    }
}

// To print the grid

void printdata(vector<vector<char>>mat,int n){
    cout<<"HI! THIS IS THE RESULTANT GRID:"<<endl;
    cout<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j];
            if(j!=n-1)cout<<"| ";
        }cout<<"\n";
        if(i!=n-1){
            for(int i=0;i<2*n;i++){
                cout<<"-";
            }cout<<"\n";
        }
    }
    cout<<"\n";
}
int isvalid(int x,int y,vector<vector<char>>mat){
    if(mat[x][y]==' ')return 1;
    else return 0;
}
int getdata(vector<vector<char>>&mat,int ch,int n){
    int x,y;
    if(ch%2==0){
        cout<<"Hi X it's your chance:"<<endl;
         cout<<"enter the position of x and y:"<<endl;
          cin>>x>>y;
          int check=isvalid(x,y,mat);
          if(check==1)mat[x][y]='X';
          else {
            cout<<"poistion is already taken choose another position:"<<endl;
            getdata(mat,ch,n);
          }
          int finalcheck=ischeck(mat,n,x,y,ch);
          if(finalcheck==1){
            cout<<"Hurray X won the game"<<endl;
            return 0;
          }

    }else{
         cout<<"Hi O it's your chance:"<<endl;
         cout<<"enter the position of x and y:"<<endl;
          cin>>x>>y;
          int check=isvalid(x,y,mat);
          if(check==1)mat[x][y]='O';
          else {
            cout<<"poistion is already taken choose another position:"<<endl;
            getdata(mat,ch,n);
          }
        int finalcheck=ischeck(mat,n,x,y,ch);
          if(finalcheck==1){
            cout<<"Hurray O won the game"<<endl;
            return 0;
          }
    }
}
int main(){
    int n;
    cout<<"enter the size of the matrix:";
    cin>>n;
    vector<vector<char>>mat(n,vector<char>(n,0));
    //inistalise all the element in the matrix with null character
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=' ';
        }
    }
    printdata(mat,n);
    int ch=(n*n);
    while(ch--){
        int res= getdata(mat,ch,n);
        printdata(mat,n);
        if(res==0)break;
    }
    if(ch==-1){
        cout<<"\n";
        cout<<"Game Draw"<<endl;
    }
}