#include <iostream>

using namespace std;
struct point {
    int x,y;
    float maxi;

};

point check(char board[8][8],float king[8][8],float queen[8][8],float rock[8][8],float bishop[8][8],float knight[8][8], float pawn[8][8])
{

  int a1,b1;
  point ret; //where we put the best move
  ret.x=-1;
  ret.y=-1;
  float maxi=-100000;
  ret.maxi=maxi;
for (int m=0;m<8;m++)
    for (int n=0;n<8;n++)
  if(board[m][n]=='R')
  {
    float init=rock[m][n];
    for(int i=m+1;i<8;i++)
    {
      if(board[i][n]=='e')
      {
        float current=rock[i][n];
        if(board[i][n]=='r')current+=50;
        else if(board[i][n]=='n')current+=30;
        else if(board[i][n]=='p')current+=10;
        else if(board[i][n]=='q')current+=90;
        else if(board[i][n]=='b')current+=30;
        else if(board[i][n]=='k')current+=900;
        if(current-init>maxi){
        ret.x=i;
        ret.y=n;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=current-init;
        }
      }
      else if(board[i][n]=='r' || board[i][n]=='n' || board[i][n]=='p' || board[i][n]=='q' || board[i][n]=='b' || board[i][n]=='k')
      {
        float current=rock[i][n];
        if(board[i][n]=='r')current+=50;
        else if(board[i][n]=='n')current+=30;
        else if(board[i][n]=='p')current+=10;
        else if(board[i][n]=='q')current+=90;
        else if(board[i][n]=='b')current+=30;
        else if(board[i][n]=='k')current+=900;
        if(current-init>maxi){
        ret.x=i;
        ret.y=n;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=current-init;
        }
      }
      else break;
    }
    for(int i=m-1;i>-1;i--)
    {
      if(board[i][n]=='e')
      {
        float current=rock[i][n];
        if(board[i][n]=='r')current+=50;
        else if(board[i][n]=='n')current+=30;
        else if(board[i][n]=='p')current+=10;
        else if(board[i][n]=='q')current+=90;
        else if(board[i][n]=='b')current+=30;
        else if(board[i][n]=='k')current+=900;
        if(current-init>maxi){
        ret.x=i;
        ret.y=n;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=ret.maxi;
        }
      }
      else if(board[i][n]=='r' || board[i][n]=='n' || board[i][n]=='p' || board[i][n]=='q' || board[i][n]=='b' || board[i][n]=='k')
      {
        float current=rock[i][n];
        if(board[i][n]=='r')current+=50;
        else if(board[i][n]=='n')current+=30;
        else if(board[i][n]=='p')current+=10;
        else if(board[i][n]=='q')current+=90;
        else if(board[i][n]=='b')current+=30;
        else if(board[i][n]=='k')current+=900;
        if(current-init>maxi){
        ret.x=i;
        ret.y=n;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=ret.maxi;
        }
        break;
      }
      else break;
    }
    for(int i=n+1;i<8;i++)
    {
      if(board[m][i]=='e' )
      {
        float current=rock[m][i];
        if(board[m][i]=='r')current+=50;
        else if(board[m][i]=='n')current+=30;
        else if(board[m][i]=='p')current+=10;
        else if(board[m][i]=='q')current+=90;
        else if(board[m][i]=='b')current+=30;
        else if(board[m][i]=='k')current+=900;
        if(current-init>maxi){
        ret.x=m;
        ret.y=i;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=ret.maxi;
        }
      }
      //else if(board[x][i]=='r'||board[x][i]=='n'||board[x][i]=='b'||board[x][i]=='p'||board[x][i]=='q'||board[x][i]=='k')
      else break;
    }
    for(int i=n-1;i>-1;i--)
    {
      if(board[m][i]=='e' || board[m][i]=='r'||board[m][i]=='n'||board[m][i]=='b'||board[m][i]=='p'||board[m][i]=='q'||board[m][i]=='k')
      {
        float current=rock[m][i];
        if(board[m][i]=='r')current+=50;
        else if(board[m][i]=='n')current+=30;
        else if(board[m][i]=='p')current+=10;
        else if(board[m][i]=='q')current+=90;
        else if(board[m][i]=='b')current+=30;
        else if(board[m][i]=='k')current+=900;
        if(current-init>maxi){
        ret.x=m;
        ret.y=i;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=ret.maxi;
        }
      }
      else break;
    }
  }
  else if(c=='B')
  {
    int a=m,b=n;
    float init = bishop[m][n];
    while(a<7 && b<7)
    {
      a++;b++;
      if(board[a][b]=='e' || board[a][b]=='r'|| board[a][b]=='n'||board[a][b]=='p'||board[a][b]=='q'||board[a][b]=='b'||board[a][b]=='k')
      {
        float current=bishop[a][b];
        if(board[a][b]=='r')current+=50;
        else if(board[a][b]=='n')current+=30;
        else if(board[a][b]=='p')current+=10;
        else if(board[a][b]=='q')current+=90;
        else if(board[a][b]=='b')current+=30;
        else if(board[a][b]=='k')current+=900;
        if(current-init>maxi){
        ret.x=a;
        ret.y=b;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=ret.maxi;
        }
      }
    else break;
    }
    a=m;b=n;
    while(a<7 && b>0)
    {
      a++;b--;
      if(board[a][b]=='e' || board[a][b]=='r'|| board[a][b]=='n'||board[a][b]=='p'||board[a][b]=='q'||board[a][b]=='b'||board[a][b]=='k')
      {
        float current=bishop[a][b];
        if(board[a][b]=='r')current+=50;
        else if(board[a][b]=='n')current+=30;
        else if(board[a][b]=='p')current+=10;
        else if(board[a][b]=='q')current+=90;
        else if(board[a][b]=='b')current+=30;
        else if(board[a][b]=='k')current+=900;
        if(current-init>maxi){
        ret.x=a;
        ret.y=b;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=ret.maxi;
        }
      }
    else break;
    }
    a=m;b=n;
    while(a>0 && b<7)
    {
      a--;b++;
      if(board[a][b]=='e' || board[a][b]=='r'|| board[a][b]=='n'||board[a][b]=='p'||board[a][b]=='q'||board[a][b]=='b'||board[a][b]=='k')
      {
        float current=bishop[a][b];
        if(board[a][b]=='r')current+=50;
        else if(board[a][b]=='n')current+=30;
        else if(board[a][b]=='p')current+=10;
        else if(board[a][b]=='q')current+=90;
        else if(board[a][b]=='b')current+=30;
        else if(board[a][b]=='k')current+=900;
        if(current-init>maxi){
        ret.x=a;
        ret.y=b;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=ret.maxi;
        }
      }
    else break;
    }
    a=m;b=n;
    while(a>0 && b>0)
    {
      a--;b--;
      if(board[a][b]=='e' || board[a][b]=='r'|| board[a][b]=='n'||board[a][b]=='p'||board[a][b]=='q'||board[a][b]=='b'||board[a][b]=='k')
      {
        float current=bishop[a][b];
        if(board[a][b]=='r')current+=50;
        else if(board[a][b]=='n')current+=30;
        else if(board[a][b]=='p')current+=10;
        else if(board[a][b]=='q')current+=90;
        else if(board[a][b]=='b')current+=30;
        else if(board[a][b]=='k')current+=900;
        if(current-init>maxi){
        ret.x=a;
        ret.y=b;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=ret.maxi;
        }
      }
    else break;
    }
  }
  else if(c=='N')
  {
    float init=knight[m][n];
    if(m+2<8 && n+1<8 && (board[m+2][n+1]=='e' || board[m+2][n+1]=='r'|| board[m+2][n+1]=='n'||board[m+2][n+1]=='p'||board[m+2][n+1]=='q'||
board[m+2][n+1]=='b'||board[m+2][n+1]=='k'))
    {
        int a=m+2,b=n+1;
        float current=knight[a][b];
        if(board[a][b]=='r')current+=50;
        else if(board[a][b]=='n')current+=30;
        else if(board[a][b]=='p')current+=10;
        else if(board[a][b]=='q')current+=90;
        else if(board[a][b]=='b')current+=30;
        else if(board[a][b]=='k')current+=900;
        if(current-init>maxi){
        ret.x=a;
        ret.y=b;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=ret.maxi;
        }
    }
    if(m+1<8 && n+2<8 && (board[m+1][n+2]=='e' || board[m+1][n+2]=='r'|| board[m+1][n+2]=='n'||board[m+1][n+2]=='p'||board[m+1][n+2]=='q'||
board[m+1][n+2]=='b'||board[m+1][n+2]=='k'))
    {
      int a=m+1,b=n+2;
      float current=knight[a][b];
        if(board[a][b]=='r')current+=50;
        else if(board[a][b]=='n')current+=30;
        else if(board[a][b]=='p')current+=10;
        else if(board[a][b]=='q')current+=90;
        else if(board[a][b]=='b')current+=30;
        else if(board[a][b]=='k')current+=900;
        if(current-init>maxi){
        ret.x=a;
        ret.y=b;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=ret.maxi;
        }
    }
    if(m-2>-1 && n+1<8 && (board[m-2][n+1]=='e' || board[m-2][n+1]=='r'|| board[m-2][n+1]=='n'||board[m-2][n+1]=='p'||board[m-2][n+1]=='q'||
board[m-2][n+1]=='b'||board[m-2][n+1]=='k'))
    {
        int a=m-2,b=n+1;
        float current=knight[a][b];
        if(board[a][b]=='r')current+=50;
        else if(board[a][b]=='n')current+=30;
        else if(board[a][b]=='p')current+=10;
        else if(board[a][b]=='q')current+=90;
        else if(board[a][b]=='b')current+=30;
        else if(board[a][b]=='k')current+=900;
        if(current-init>maxi){
        ret.x=a;
        ret.y=b;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=ret.maxi;
        }
    }
    if(m-1>-1 && n+2<8 && (board[m-1][n+2]=='e' || board[m-1][n+2]=='r'|| board[m-1][n+2]=='n'||board[m-1][n+2]=='p'||board[m-1][n+2]=='q'|| board[m-1][n+2]=='b'||board[m-1][n+2]=='k'))
    {
      int a=m-1,b=n+2;
        float current=knight[a][b];
        if(board[a][b]=='r')current+=50;
        else if(board[a][b]=='n')current+=30;
        else if(board[a][b]=='p')current+=10;
        else if(board[a][b]=='q')current+=90;
        else if(board[a][b]=='b')current+=30;
        else if(board[a][b]=='k')current+=900;
        if(current-init>maxi){
        ret.x=a;
        ret.y=b;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=ret.maxi;
        }
    }
    if(m+2<8 && n-1>-1 && (board[m+2][n-1]=='e' || board[m+2][n-1]=='r'|| board[m+2][n-1]=='n'||board[m+2][n-1]=='p'||board[m+2][n-1]=='q'|| board[m+2][n-1]=='b'||board[m+2][n-1]=='k'))
    {
      int a=m+2,b=n-1;
        float current=knight[a][b];
        if(board[a][b]=='r')current+=50;
        else if(board[a][b]=='n')current+=30;
        else if(board[a][b]=='p')current+=10;
        else if(board[a][b]=='q')current+=90;
        else if(board[a][b]=='b')current+=30;
        else if(board[a][b]=='k')current+=900;
        if(current-init>maxi){
        ret.x=a;
        ret.y=b;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=ret.maxi;
        }
    }
    if(m+1<8 && n-2>-1 && (board[m+1][n-2]=='e' || board[m+1][n-2]=='r'|| board[m+1][n-2]=='n'||board[m+1][n-2]=='p'||board[m+1][n-2]=='q'||
board[m+1][n-2]=='b'||board[m+1][n-2]=='k'))
    {

      int a=m+1,b=n-2;
      float current=knight[a][b];
        if(board[a][b]=='r')current+=50;
        else if(board[a][b]=='n')current+=30;
        else if(board[a][b]=='p')current+=10;
        else if(board[a][b]=='q')current+=90;
        else if(board[a][b]=='b')current+=30;
        else if(board[a][b]=='k')current+=900;
        if(current-init>maxi){
        ret.x=a;
        ret.y=b;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=ret.maxi;
        }
    }
    if(m-2>-1 && n-1>-1 && (board[m-2][n-1]=='e' || board[m-2][n-1]=='r'|| board[m-2][n-1]=='n'||board[m-2][n-1]=='p'||board[m-2][n-
1]=='q'||board[m-2][n-1]=='b'||board[m-2][n-1]=='k'))
    {
      int a=m-2,b=n-1;
      float current=knight[a][b];
        if(board[a][b]=='r')current+=50;
        else if(board[a][b]=='n')current+=30;
        else if(board[a][b]=='p')current+=10;
        else if(board[a][b]=='q')current+=90;
        else if(board[a][b]=='b')current+=30;
        else if(board[a][b]=='k')current+=900;
        if(current-init>maxi){
        ret.x=a;
        ret.y=b;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=ret.maxi;
        }
    }
    if(m-1>-1 && n-2>-1 && (board[m-2][n-1]=='e' || board[m-2][n-1]=='r'|| board[m-2][n-1]=='n'||board[m-2][n-1]=='p'||board[m-2][n-
1]=='q'||board[m-2][n-1]=='b'||board[m-2][n-1]=='k'))
    {
      int a=m-1,b=n-2;
      float current=knight[a][b];
        if(board[a][b]=='r')current+=50;
        else if(board[a][b]=='n')current+=30;
        else if(board[a][b]=='p')current+=10;
        else if(board[a][b]=='q')current+=90;
        else if(board[a][b]=='b')current+=30;
        else if(board[a][b]=='k')current+=900;
        if(current-init>maxi){
        ret.x=a;
        ret.y=b;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=ret.maxi;
        }
    }
  }
  else if(c=='K')
  {
    float init = king[m][n];
    if(m+1<8 && n+1<8 && (board[m+1][n+1]=='e' || board[m+1][n+1]=='r'|| board[m+1][n+1]=='n'||board[m+1][n+1]=='p'||board[m+1][n+1]=='q'||
board[m+1][n+1]=='b'||board[m+1][n+1]=='k'))
    {
      int a=m+1,b=n+1;
      float current=king[a][b];
        if(board[a][b]=='r')current+=50;
        else if(board[a][b]=='n')current+=30;
        else if(board[a][b]=='p')current+=10;
        else if(board[a][b]=='q')current+=90;
        else if(board[a][b]=='b')current+=30;
        else if(board[a][b]=='k')current+=900;
        if(current-init>maxi){
        ret.x=a;
        ret.y=b;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=ret.maxi;
        }
    }
    if(m+1<8 && n-1>-1 && (board[m+1][n-1]=='e' || board[m+1][n-1]=='r'|| board[m+1][n-1]=='n'||board[m+1][n-1]=='p'||board[m+1][n-1]=='q'||
board[m+1][n-1]=='b'||board[m+1][n-1]=='k'))
    {
      int a=m+1,b=n-1;
      float current=king[a][b];
        if(board[a][b]=='r')current+=50;
        else if(board[a][b]=='n')current+=30;
        else if(board[a][b]=='p')current+=10;
        else if(board[a][b]=='q')current+=90;
        else if(board[a][b]=='b')current+=30;
        else if(board[a][b]=='k')current+=900;
        if(current-init>maxi){
        ret.x=a;
        ret.y=b;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=ret.maxi;
        }
    }
    if(m-1>-1 && n+1<8 && (board[m-1][n+1]=='e' || board[m-1][n+1]=='r'|| board[m-1][n+1]=='n'||board[m-1][n+1]=='p'||board[m-1][n+1]=='q'||
board[m-1][n+1]=='b'||board[m-1][n+1]=='k'))
    {
      int a=m-1,b=n+1;
      float current=king[a][b];
        if(board[a][b]=='r')current+=50;
        else if(board[a][b]=='n')current+=30;
        else if(board[a][b]=='p')current+=10;
        else if(board[a][b]=='q')current+=90;
        else if(board[a][b]=='b')current+=30;
        else if(board[a][b]=='k')current+=900;
        if(current-init>maxi){
        ret.x=a;
        ret.y=b;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=ret.maxi;
        }
    }
    if(m-1>-1 && n-1>-1 && (board[m-1][n-1]=='e' || board[m-1][n-1]=='r'|| board[m-1][n-1]=='n'||board[m-1][n-1]=='p'||board[m-1][n-
1]=='q'||board[m-1][n-1]=='b'||board[m-1][n-1]=='k'))
    {
      int a=m-1,b=n-1;
      float current=king[a][b];
        if(board[a][b]=='r')current+=50;
        else if(board[a][b]=='n')current+=30;
        else if(board[a][b]=='p')current+=10;
        else if(board[a][b]=='q')current+=90;
        else if(board[a][b]=='b')current+=30;
        else if(board[a][b]=='k')current+=900;
        if(current-init>maxi){
        ret.x=a;
        ret.y=b;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=ret.maxi;
        }
    }
    if(n+1<8 && (board[m][n+1]=='e' || board[m][n+1]=='r'|| board[m][n+1]=='n'||board[m][n+1]=='p'||board[m][n+1]=='q'||board[m][n+1]=='b'||
board[m][n+1]=='k'))
    {
      int a=m,b=n+1;
      float current=king[a][b];
        if(board[a][b]=='r')current+=50;
        else if(board[a][b]=='n')current+=30;
        else if(board[a][b]=='p')current+=10;
        else if(board[a][b]=='q')current+=90;
        else if(board[a][b]=='b')current+=30;
        else if(board[a][b]=='k')current+=900;
        if(current-init>maxi){
        ret.x=a;
        ret.y=b;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=ret.maxi;
        }
    }
    if(n-1>-1 && (board[n][m-1]=='e' || board[n][m-1]=='r'|| board[m][n-1]=='n'||board[m][n-1]=='p'||board[m][n-1]=='q'||board[m][n-
1]=='b'||board[m][n-1]=='k'))
    {
      int a=m,b=n-1;
      float current=king[a][b];
        if(board[a][b]=='r')current+=50;
        else if(board[a][b]=='n')current+=30;
        else if(board[a][b]=='p')current+=10;
        else if(board[a][b]=='q')current+=90;
        else if(board[a][b]=='b')current+=30;
        else if(board[a][b]=='k')current+=900;
        if(current-init>maxi){
        ret.x=a;
        ret.y=b;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=ret.maxi;
        }
    }
    if(m-1>-1 && (board[m-1][n]=='e' || board[m-1][n]=='r'|| board[m-1][n]=='n'||board[m-1][n]=='p'||board[m-1][n]=='q'||board[m-1]
[n]=='b'||board[m-1][n]=='k'))
    {
      int a=m-1,b=n;
      float current=king[a][b];
        if(board[a][b]=='r')current+=50;
        else if(board[a][b]=='n')current+=30;
        else if(board[a][b]=='p')current+=10;
        else if(board[a][b]=='q')current+=90;
        else if(board[a][b]=='b')current+=30;
        else if(board[a][b]=='k')current+=900;
        if(current-init>maxi){
        ret.x=a;
        ret.y=b;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=ret.maxi;
        }
    }
    if(m+1<8 && (board[m+1][n]=='e' || board[m+1][n]=='r'|| board[m+1][n]=='n'||board[m+1][n]=='p'||board[m+1][n]=='q'||board[m+1][n]=='b'||
board[m+1][n]=='k'))
    {
      int a=m+1,b=n;
      float current=king[a][b];
        if(board[a][b]=='r')current+=50;
        else if(board[a][b]=='n')current+=30;
        else if(board[a][b]=='p')current+=10;
        else if(board[a][b]=='q')current+=90;
        else if(board[a][b]=='b')current+=30;
        else if(board[a][b]=='k')current+=900;
        if(current-init>maxi){
        ret.x=a;
        ret.y=b;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=ret.maxi;
        }
    }
  }
  else if(board[m][n]=='P')
  {
    float init = pawn[m][n];
    if(m==1)
    {
      for(int i=m+1;i<4;i++)
      {
        if((board[i][n]=='e' || board[i][n]=='r'|| board[i][n]=='n'||board[i][n]=='p'||board[i][n]=='q'||board[i][n]=='b'||board[i][n]=='k'))
        {
          int a=i,b=n;
          float current=pawn[a][b];
          if(board[a][b]=='r')current+=50;
          else if(board[a][b]=='n')current+=30;
          else if(board[a][b]=='p')current+=10;
          else if(board[a][b]=='q')current+=90;
          else if(board[a][b]=='b')current+=30;
          else if(board[a][b]=='k')current+=900;
          if(current-init>maxi){
          ret.x=a;
          ret.y=b;
          a1=ret.x;
          b1=ret.y;
          ret.maxi=current-init;
          maxi=ret.maxi;
        }
      }
    else break;
    }
    }
    if(m+1<8 && (board[m+1][n]=='e' || board[m+1][n]=='r'|| board[m+1][n]=='n'||board[m+1][n]=='p'||board[m+1][n]=='q'||board[m+1][n]=='b'||
board[m+1][n]=='k'))
    {
          int a=m+1,b=n;
          float current=pawn[a][b];
          if(board[a][b]=='r')current+=50;
          else if(board[a][b]=='n')current+=30;
          else if(board[a][b]=='p')current+=10;
          else if(board[a][b]=='q')current+=90;
          else if(board[a][b]=='b')current+=30;
          else if(board[a][b]=='k')current+=900;
          if(current-init>maxi){
          ret.x=a;
          ret.y=b;
          a1=ret.x;
          b1=ret.y;
          ret.maxi=current-init;
          maxi=ret.maxi;
    }
    }
    if(m+1<8 && n+1<8 && (board[m+1][n+1]>='b'||board[m+1][n+1]>='n'||board[m+1][n+1]>='k'||board[m+1][n+1]>='r'||board[m+1][n+1]>='q'||board[m+1][n+1]>='p'))
    {
          int a=m+1,b=n+1;
          float current=pawn[a][b];
          if(board[a][b]=='r')current+=50;
          else if(board[a][b]=='n')current+=30;
          else if(board[a][b]=='p')current+=10;
          else if(board[a][b]=='q')current+=90;
          else if(board[a][b]=='b')current+=30;
          else if(board[a][b]=='k')current+=900;
          if(current-init>maxi){
          ret.x=a;
          ret.y=b;
          a1=ret.x;
          b1=ret.y;
          ret.maxi=current-init;
          maxi=ret.maxi;
    }
    }
    if(m+1<8 && n-1>-1 && (board[m+1][n-1]>='b'||board[m+1][n-1]>='n'||board[m+1][n-1]>='k'||board[m+1][n-1]>='r'||board[m+1][n-1]>='q'||
    board[m+1][n-1]>='p'))
    {
          int a=m+1,b=n-1;
          float current=pawn[a][b];
          if(board[a][b]=='r')current+=50;
          else if(board[a][b]=='n')current+=30;
          else if(board[a][b]=='p')current+=10;
          else if(board[a][b]=='q')current+=90;
          else if(board[a][b]=='b')current+=30;
          else if(board[a][b]=='k')current+=900;
          if(current-init>maxi){
          ret.x=a;
          ret.y=b;
          a1=ret.x;
          b1=ret.y;
          ret.maxi=current-init;
          maxi=ret.maxi;
    }
  }
  }
  else if(board[m][n]=='Q')
  {
    float init  = queen[m][n];
    int a=m,b=n;
    while(a<7 && b<7)
    {
      a++;b++;
      if(board[a][b]=='e' || board[a][b]=='b' || board[a][b]=='n' || board[a][b]=='k' || board[a][b]=='r' || board[a][b]=='q' || board[a]
      [b]=='p')
      {
          float current=queen[a][b];
          if(board[a][b]=='r')current+=50;
          else if(board[a][b]=='n')current+=30;
          else if(board[a][b]=='p')current+=10;
          else if(board[a][b]=='q')current+=90;
          else if(board[a][b]=='b')current+=30;
          else if(board[a][b]=='k')current+=900;
          if(current-init>maxi){
          ret.x=a;
          ret.y=b;
          a1=ret.x;
          b1=ret.y;
          ret.maxi=current-init;
          maxi=ret.maxi;
      }
    }
    else break;
    }
    a=m;b=n;
    while(a<7 && b>0)
    {
      a++;b--;
      if(board[a][b]=='e' || board[a][b]=='b' || board[a][b]=='n' || board[a][b]=='k' || board[a][b]=='r' || board[a][b]=='q' || board[a]
[b]=='p')
      {
          float current=queen[a][b];
          if(board[a][b]=='r')current+=50;
          else if(board[a][b]=='n')current+=30;
          else if(board[a][b]=='p')current+=10;
          else if(board[a][b]=='q')current+=90;
          else if(board[a][b]=='b')current+=30;
          else if(board[a][b]=='k')current+=900;
          if(current-init>maxi){
          ret.x=a;
          ret.y=b;
          a1=ret.x;
          b1=ret.y;
          ret.maxi=current-init;
          maxi=ret.maxi;
      }
    }
    else break;
    }
    a=m;b=n;
    while(a>0 && b<7)
    {
      a--;b++;
      if(board[a][b]=='e' || board[a][b]=='b' || board[a][b]=='n' || board[a][b]=='k' || board[a][b]=='r' || board[a][b]=='q' || board[a]
[b]=='p')
      {
          float current=queen[a][b];
          if(board[a][b]=='r')current+=50;
          else if(board[a][b]=='n')current+=30;
          else if(board[a][b]=='p')current+=10;
          else if(board[a][b]=='q')current+=90;
          else if(board[a][b]=='b')current+=30;
          else if(board[a][b]=='k')current+=900;
          if(current-init>maxi){
          ret.x=a;
          ret.y=b;
          a1=ret.x;
          b1=ret.y;
          ret.maxi=current-init;
          maxi=ret.maxi;
      }
    }
    else break;
    }
    a=m;b=n;
    while(a>0 && b>0)
    {
      a--;b--;
      if(board[a][b]=='e' || board[a][b]=='b' || board[a][b]=='n' || board[a][b]=='k' || board[a][b]=='r' || board[a][b]=='q' || board[a]
[b]=='p')
      {
          float current=king[a][b];
          if(board[a][b]=='r')current+=50;
          else if(board[a][b]=='n')current+=30;
          else if(board[a][b]=='p')current+=10;
          else if(board[a][b]=='q')current+=90;
          else if(board[a][b]=='b')current+=30;
          else if(board[a][b]=='k')current+=900;
          if(current-init>maxi){
          ret.x=a;
          ret.y=b;
          a1=ret.x;
          b1=ret.y;
          ret.maxi=current-init;
          maxi=ret.maxi;
      }
    }
    else break;
    }
    a=m;b=n;
    while(a>0)
    {
      a--;
      if(board[a][b]=='e' || board[a][b]=='b' || board[a][b]=='n' || board[a][b]=='k' || board[a][b]=='r' || board[a][b]=='q' || board[a]
[b]=='p')
      {
          float current=king[a][b];
          if(board[a][b]=='r')current+=50;
          else if(board[a][b]=='n')current+=30;
          else if(board[a][b]=='p')current+=10;
          else if(board[a][b]=='q')current+=90;
          else if(board[a][b]=='b')current+=30;
          else if(board[a][b]=='k')current+=900;
          if(current-init>maxi){
          ret.x=a;
          ret.y=b;
          a1=ret.x;
          b1=ret.y;
          ret.maxi=current-init;
          maxi=ret.maxi;
      }
    }
    else break;
    }
    a=m;b=n;
    while(b>0)
    {
      b--;
      if(board[a][b]=='e' || board[a][b]=='b' || board[a][b]=='n' || board[a][b]=='k' || board[a][b]=='r' || board[a][b]=='q' || board[a]
[b]=='p')
      {
          float current=king[a][b];
          if(board[a][b]=='r')current+=50;
          else if(board[a][b]=='n')current+=30;
          else if(board[a][b]=='p')current+=10;
          else if(board[a][b]=='q')current+=90;
          else if(board[a][b]=='b')current+=30;
          else if(board[a][b]=='k')current+=900;
          if(current-init>maxi){
          ret.x=a;
          ret.y=b;
          a1=ret.x;
          b1=ret.y;
          ret.maxi=current-init;
          maxi=ret.maxi;
      }
    }
    else break;
    }
    a=m;b=n;
    while(a<7)
    {
      a++;
        if(board[a][b]=='e' || board[a][b]=='b' || board[a][b]=='n' || board[a][b]=='k' || board[a][b]=='r' || board[a][b]=='q' || board[a]
[b]=='p')
        {
          float current=king[a][b];
          if(board[a][b]=='r')current+=50;
          else if(board[a][b]=='n')current+=30;
          else if(board[a][b]=='p')current+=10;
          else if(board[a][b]=='q')current+=90;
          else if(board[a][b]=='b')current+=30;
          else if(board[a][b]=='k')current+=900;
          if(current-init>maxi){
          ret.x=a;
          ret.y=b;
          a1=ret.x;
          b1=ret.y;
          ret.maxi=current-init;
          maxi=ret.maxi;
        }
      }
    else break;
    }
    a=m;b=n;
    while(b<7)
    {
      b++;
      if(board[a][b]=='e' || board[a][b]=='b' || board[a][b]=='n' || board[a][b]=='k' || board[a][b]=='r' || board[a][b]=='q' || board[a]
[b]=='p')
      {
          float current=king[a][b];
          if(board[a][b]=='r')current+=50;
          else if(board[a][b]=='n')current+=30;
          else if(board[a][b]=='p')current+=10;
          else if(board[a][b]=='q')current+=90;
          else if(board[a][b]=='b')current+=30;
          else if(board[a][b]=='k')current+=900;
          if(current-init>maxi){
          ret.x=a;
          ret.y=b;
          a1=ret.x;
          b1=ret.y;
          ret.maxi=current-init;
          maxi=ret.maxi;
      }
      }
    else break;
      }
    }
  return ret;
}

int main()
{
    char board[8][8] =
{
  {'R','N','B','Q','K','B','N','R'},
  {'P','P','P','P','P','P','P','P'},
  {'e','e','e','e','e','e','e','e'},
  {'e','e','e','e','e','e','e','e'},
  {'e','e','e','e','e','e','e','e'},
  {'e','e','e','e','e','e','e','e'},
  {'p','p','p','p','p','p','p','p'},
  {'r','n','b','k','q','b','n','r'}
};
float king[8][8] =
{
  {-3.0,-4.0,-4.0,-5.0,-5.0,-4.0,-4.0,-3.0},
  {-3.0,-4.0,-4.0,-5.0,-5.0,-4.0,-4.0,-3.0},
  {-3.0,-4.0,-4.0,-5.0,-5.0,-4.0,-4.0,-3.0},
  {-3.0,-4.0,-4.0,-5.0,-5.0,-4.0,-4.0,-3.0},
  {-2.0,-3.0,-3.0,-4.0,-4.0,-3.0,-3.0,-2.0},
  {-1.0,-2.0,-2.0,-2.0,-2.0,-2.0,-2.0,-1.0},
  {2.0,2.0,0.0,0.0,0.0,0.0,2.0,2.0},
  {2.0,3.0,1.0,0.0,0.0,1.0,3.0,2.0},
};

float queen[8][8] =
{
  {-2.0,-1.0,-1.0,-0.5,-0.5,-1.0,-1.0,-2.0},
  {-1.0,0.0,0.0,0.0,0.0,0.0,0.0,-1.0},
  {-1.0,0.0,0.5,0.5,0.5,0.5,0.0,-1.0},
  {-0.5,0.0,0.5,0.5,0.5,0.5,0.0,-0.5},
  {0.0,0.0,0.5,0.5,0.5,0.5,0.0,-0.5},
  {-1.0,0.5,0.5,0.5,0.5,0.5,0.0,-1.0},
  {-1.0,0.0,0.5,0.0,0.0,0.0,0.0,-1.0},
  {-2.0,-1.0,-1.0,-0.5,-0.5,-1.0,-1.0,-2.0},
};
float rock[8][8] =
{
  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0},
  {0.5,1.0,1.0,1.0,1.0,1.0,1.0,0.5},
  {-0.5,0.0,0.0,0.0,0.0,0.0,0.0,-0.5},
  {-0.5,0.0,0.0,0.0,0.0,0.0,0.0,-0.5},
  {-0.5,0.0,0.0,0.0,0.0,0.0,0.0,-0.5},
  {-0.5,0.0,0.0,0.0,0.0,0.0,0.0,-0.5},
  {-0.5,0.0,0.0,0.0,0.0,0.0,0.0,-0.5},
  {0.0,0.0,0.0,0.5,0.5,0.0,0.0,0.0},
};
float bishop[8][8] =
{
  {-2.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-2.0},
  {-1.0,0.0,0.0,0.0,0.0,0.0,0.0,-1.0},
  {-1.0,0.0,0.5,1.0,1.0,0.5,0.0,-1.0},
  {-1.0,0.5,0.5,1.0,1.0,0.5,0.5,-1.0},
  {-1.0,0.5,0.5,1.0,1.0,0.5,0.5,-1.0},
  {-1.0,0.0,1.0,1.0,1.0,1.0,0.0,-1.0},
  {-1.0,0.5,0.0,0.0,0.0,0.0,0.5,-1.0},
  {-2.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-2.0},
};
float knight[8][8] =
{
  {-5.0,-4.0,-3.0,-3.0,-3.0,-3.0,-4.0,-5.0},
  {-4.0,-2.0,0.0,0.0,0.0,0.0,-2.0,-4.0},
  {-3.0,0.0,1.0,1.5,1.5,1.0,0.0,-3.0},
  {-3.0,0.5,1.5,2.0,2.0,1.5,0.5,-3.0},
  {-3.0,0.0,1.5,2.0,2.0,1.5,0.0,-3.0},
  {-3.0,0.5,1.0,1.5,1.5,1.0,0.5,-3.0},
  {-4.0,-2.0,0.0,0.5,0.5,0.0,-2.0,-4.0},
  {-5.0,-4.0,-3.0,-3.0,-3.0,-3.0,-4.0,-5.0},
};
float pawn[8][8] =
{
  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0},
  {5.0,5.0,5.0,5.0,5.0,5.0,5.0,5.0},
  {1.0,1.0,2.0,3.0,3.0,2.0,1.0,1.0},
  {0.5,0.5,1.0,2.5,2.5,1.0,0.5,0.5},
  {0.0,0.0,0.0,2.0,2.0,0.0,0.0,0.0},
  {0.5,-0.5,-1.0,0.0,0.0,-1.0,-0.5,0.5},
  {0.5,1.0,1.0,-2.0,-2.0,1.0,1.0,0.5},
  {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0},
};


    return 0;
}
