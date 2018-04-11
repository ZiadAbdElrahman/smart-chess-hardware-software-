#include <iostream>

using namespace std;
struct point {
    int x,y;
    float maxi;

};

point check(char c,int x,int y,char board[8][8],float king[8][8],float queen[8][8],float rock[8][8],float bishop[8][8],float knight[8][8], float pawn[8][8])
{
  int a1,b1;
  point ret;
  ret.x=-1;
  ret.y=-1;
  float maxi=-100000;
  ret.maxi=maxi;
  if(c=='R')
  {
    float init=rock[x][y];
    for(int i=x+1;i<8;i++)
    {
      if(board[i][y]=='e')
      {
        float current=rock[i][y];
        if(board[i][y]=='r')current+=50;
        else if(board[i][y]=='n')current+=30;
        else if(board[i][y]=='p')current+=10;
        else if(board[i][y]=='q')current+=90;
        else if(board[i][y]=='b')current+=30;
        else if(board[i][y]=='k')current+=900;
        if(current-init>maxi){
        ret.x=i;
        ret.y=y;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=current-init;
        }
      }
      else if(board[i][y]=='r' || board[i][y]=='n' || board[i][y]=='p' || board[i][y]=='q' || board[i][y]=='b' || board[i][y]=='k')
      {
        float current=rock[i][y];
        if(board[i][y]=='r')current+=50;
        else if(board[i][y]=='n')current+=30;
        else if(board[i][y]=='p')current+=10;
        else if(board[i][y]=='q')current+=90;
        else if(board[i][y]=='b')current+=30;
        else if(board[i][y]=='k')current+=900;
        if(current-init>maxi){
        ret.x=i;
        ret.y=y;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=current-init;
        }
      }
      else break;
    }
    for(int i=x-1;i>-1;i--)
    {
      if(board[i][y]=='e')
      {
        float current=rock[i][y];
        if(board[i][y]=='r')current+=50;
        else if(board[i][y]=='n')current+=30;
        else if(board[i][y]=='p')current+=10;
        else if(board[i][y]=='q')current+=90;
        else if(board[i][y]=='b')current+=30;
        else if(board[i][y]=='k')current+=900;
        if(current-init>maxi){
        ret.x=i;
        ret.y=y;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=ret.maxi;
        }
      }
      else if(board[i][y]=='r' || board[i][y]=='n' || board[i][y]=='p' || board[i][y]=='q' || board[i][y]=='b' || board[i][y]=='k')
      {
        float current=rock[i][y];
        if(board[i][y]=='r')current+=50;
        else if(board[i][y]=='n')current+=30;
        else if(board[i][y]=='p')current+=10;
        else if(board[i][y]=='q')current+=90;
        else if(board[i][y]=='b')current+=30;
        else if(board[i][y]=='k')current+=900;
        if(current-init>maxi){
        ret.x=i;
        ret.y=y;
        a1=ret.x;
        b1=ret.y;
        ret.maxi=current-init;
        maxi=ret.maxi;
        }
        break;
      }
      else break;
    }
    for(int i=y+1;i<8;i++)
    {
      if(board[x][i]=='e' )
      {
        float current=rock[x][i];
        if(board[x][i]=='r')current+=50;
        else if(board[x][i]=='n')current+=30;
        else if(board[x][i]=='p')current+=10;
        else if(board[x][i]=='q')current+=90;
        else if(board[x][i]=='b')current+=30;
        else if(board[x][i]=='k')current+=900;
        if(current-init>maxi){
        ret.x=x;
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
    for(int i=y-1;i>-1;i--)
    {
      if(board[x][i]=='e' || board[x][i]=='r'||board[x][i]=='n'||board[x][i]=='b'||board[x][i]=='p'||board[x][i]=='q'||board[x][i]=='k')
      {
        float current=rock[x][i];
        if(board[x][i]=='r')current+=50;
        else if(board[x][i]=='n')current+=30;
        else if(board[x][i]=='p')current+=10;
        else if(board[x][i]=='q')current+=90;
        else if(board[x][i]=='b')current+=30;
        else if(board[x][i]=='k')current+=900;
        if(current-init>maxi){
        ret.x=x;
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
    int a=x,b=y;
    float init = bishop[x][y];
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
    a=x;b=y;
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
    a=x;b=y;
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
    a=x;b=y;
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
    float init=knight[x][y];
    if(x+2<8 && y+1<8 && (board[x+2][y+1]=='e' || board[x+2][y+1]=='r'|| board[x+2][y+1]=='n'||board[x+2][y+1]=='p'||board[x+2][y+1]=='q'||
board[x+2][y+1]=='b'||board[x+2][y+1]=='k'))
    {
        int a=x+2,b=y+1;
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
    if(x+1<8 && y+2<8 && (board[x+1][y+2]=='e' || board[x+1][y+2]=='r'|| board[x+1][y+2]=='n'||board[x+1][y+2]=='p'||board[x+1][y+2]=='q'||
board[x+1][y+2]=='b'||board[x+1][y+2]=='k'))
    {
      int a=x+1,b=y+2;
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
    if(x-2>-1 && y+1<8 && (board[x-2][y+1]=='e' || board[x-2][y+1]=='r'|| board[x-2][y+1]=='n'||board[x-2][y+1]=='p'||board[x-2][y+1]=='q'||
board[x-2][y+1]=='b'||board[x-2][y+1]=='k'))
    {
        int a=x-2,b=y+1;
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
    if(x-1>-1 && y+2<8 && (board[x-1][y+2]=='e' || board[x-1][y+2]=='r'|| board[x-1][y+2]=='n'||board[x-1][y+2]=='p'||board[x-1][y+2]=='q'|| board[x-1][y+2]=='b'||board[x-1][y+2]=='k'))
    {
      int a=x-1,b=y+2;
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
    if(x+2<8 && y-1>-1 && (board[x+2][y-1]=='e' || board[x+2][y-1]=='r'|| board[x+2][y-1]=='n'||board[x+2][y-1]=='p'||board[x+2][y-1]=='q'|| board[x+2][y-1]=='b'||board[x+2][y-1]=='k'))
    {
      int a=x+2,b=y-1;
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
    if(x+1<8 && y-2>-1 && (board[x+1][y-2]=='e' || board[x+1][y-2]=='r'|| board[x+1][y-2]=='n'||board[x+1][y-2]=='p'||board[x+1][y-2]=='q'||
board[x+1][y-2]=='b'||board[x+1][y-2]=='k'))
    {

      int a=x+1,b=y-2;
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
    if(x-2>-1 && y-1>-1 && (board[x-2][y-1]=='e' || board[x-2][y-1]=='r'|| board[x-2][y-1]=='n'||board[x-2][y-1]=='p'||board[x-2][y-
1]=='q'||board[x-2][y-1]=='b'||board[x-2][y-1]=='k'))
    {
      int a=x-2,b=y-1;
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
    if(x-1>-1 && y-2>-1 && (board[x-2][y-1]=='e' || board[x-2][y-1]=='r'|| board[x-2][y-1]=='n'||board[x-2][y-1]=='p'||board[x-2][y-
1]=='q'||board[x-2][y-1]=='b'||board[x-2][y-1]=='k'))
    {
      int a=x-1,b=y-2;
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
    float init = king[x][y];
    if(x+1<8 && y+1<8 && (board[x+1][y+1]=='e' || board[x+1][y+1]=='r'|| board[x+1][y+1]=='n'||board[x+1][y+1]=='p'||board[x+1][y+1]=='q'||
board[x+1][y+1]=='b'||board[x+1][y+1]=='k'))
    {
      int a=x+1,b=y+1;
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
    if(x+1<8 && y-1>-1 && (board[x+1][y-1]=='e' || board[x+1][y-1]=='r'|| board[x+1][y-1]=='n'||board[x+1][y-1]=='p'||board[x+1][y-1]=='q'||
board[x+1][y-1]=='b'||board[x+1][y-1]=='k'))
    {
      int a=x+1,b=y-1;
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
    if(x-1>-1 && y+1<8 && (board[x-1][y+1]=='e' || board[x-1][y+1]=='r'|| board[x-1][y+1]=='n'||board[x-1][y+1]=='p'||board[x-1][y+1]=='q'||
board[x-1][y+1]=='b'||board[x-1][y+1]=='k'))
    {
      int a=x-1,b=y+1;
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
    if(x-1>-1 && y-1>-1 && (board[x-1][y-1]=='e' || board[x-1][y-1]=='r'|| board[x-1][y-1]=='n'||board[x-1][y-1]=='p'||board[x-1][y-
1]=='q'||board[x-1][y-1]=='b'||board[x-1][y-1]=='k'))
    {
      int a=x-1,b=y-1;
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
    if(y+1<8 && (board[x][y+1]=='e' || board[x][y+1]=='r'|| board[x][y+1]=='n'||board[x][y+1]=='p'||board[x][y+1]=='q'||board[x][y+1]=='b'||
board[x][y+1]=='k'))
    {
      int a=x,b=y+1;
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
    if(y-1>-1 && (board[x][y-1]=='e' || board[x][y-1]=='r'|| board[x][y-1]=='n'||board[x][y-1]=='p'||board[x][y-1]=='q'||board[x][y-
1]=='b'||board[x][y-1]=='k'))
    {
      int a=x,b=y-1;
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
    if(x-1>-1 && (board[x-1][y]=='e' || board[x-1][y]=='r'|| board[x-1][y]=='n'||board[x-1][y]=='p'||board[x-1][y]=='q'||board[x-1]
[y]=='b'||board[x-1][y]=='k'))
    {
      int a=x-1,b=y;
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
    if(x+1<8 && (board[x+1][y]=='e' || board[x+1][y]=='r'|| board[x+1][y]=='n'||board[x+1][y]=='p'||board[x+1][y]=='q'||board[x+1][y]=='b'||
board[x+1][y]=='k'))
    {
      int a=x+1,b=y;
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
  else if(c=='P')
  {
    float init = pawn[x][y];
    if(x==1)
    {
      for(int i=x+1;i<4;i++)
      {
        if((board[i][y]=='e' || board[i][y]=='r'|| board[i][y]=='n'||board[i][y]=='p'||board[i][y]=='q'||board[i][y]=='b'||board[i][y]=='k'))
        {
          int a=i,b=y;
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
    if(x+1<8 && (board[x+1][y]=='e' || board[x+1][y]=='r'|| board[x+1][y]=='n'||board[x+1][y]=='p'||board[x+1][y]=='q'||board[x+1][y]=='b'||
board[x+1][y]=='k'))
    {
          int a=x+1,b=y;
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
    if(x+1<8 && y+1<8 && (board[x+1][y+1]>='b'||board[x+1][y+1]>='n'||board[x+1][y+1]>='k'||board[x+1][y+1]>='r'||board[x+1][y+1]>='q'||board[x+1][y+1]>='p'))
    {
          int a=x+1,b=y+1;
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
    if(x+1<8 && y-1>-1 && (board[x+1][y-1]>='b'||board[x+1][y-1]>='n'||board[x+1][y-1]>='k'||board[x+1][y-1]>='r'||board[x+1][y-1]>='q'||
    board[x+1][y-1]>='p'))
    {
          int a=x+1,b=y-1;
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
  else if(c=='Q')
  {
    float init  = queen[x][y];
    int a=x,b=y;
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
    a=x;b=y;
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
    a=x;b=y;
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
    a=x;b=y;
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
    a=x;b=y;
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
    a=x;b=y;
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
    a=x;b=y;
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
    a=x;b=y;
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
