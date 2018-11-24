#include<stack>
#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
class mazegame
{
private:
    void randomObstruction()
    {
        int c=(.25*n*n);
        while(c>0)
        {
            int i=rand()%8;
            int j=rand()%8;
            if(maze[i][j]!='X' && maze[i][j]!='#' && (i!=0 || j!=0))
            {
                maze[i][j]='X';
                c--;
            }
        }
    }

public:

    int n , lives , steps;
    char **maze;
    stack<pair<int,int>> S;

    mazegame(int n)
    {
        this->n=n;
        lives=3;
        steps=0;
        maze = new char * [n];
        for (int i = 0; i < n; ++i )
            maze[i] = new char [n];

        for(int i=0;i<n;i++)
        {
          for(int j=0;j<n;j++)
             maze[i][j]=' ';
        }

        maze[0][0]='@';
        maze[n-1][n-1]='#';
        randomObstruction();
        /**maze[3][4] = 'X';
        maze[1][7] = 'X';
        maze[2][4] = 'X';
        maze[6][6] = 'X';
        maze[7][5] = 'X';**/
    }
 void drawMaze()
 {
     int i,j=0;
     cout<<"\n\n\n\n\n";
     for(i=0;i<n;i++)
     {
         cout<<"\t   "<<(i+1)<<"  ";
     }
     cout<<"\n";
    for(i=0;i<n;i++)
     {
         cout<<"\t  ___  ";
     }
     cout<<"\n";
     while(j<n)
     {
        for(i=0;i<n;i++)
        {
            if(maze[i][j]!=' ')
                printf("\t| _%c_ |",maze[i][j]);
            else
                cout<<"\t| ___ |";
        }
        cout<<"\n";
        j++;
     }
    cout<<"\n\n\n\n\n";
 }

 void move(int x,int y)
 {
     char ch;
     do
     {
         cout<<"\nUP....'W'";
         cout<<"\nLEFT....'A'";
         cout<<"\nDOWN....'S'";
         cout<<"\nRIGHT....'D'";
         cout<<"\nUNDO....'U'";
         cout<<"\nQUIT....'Q'";
         cout<<"\n\t\t\t\t Your Lives:- "<<lives;
         cout<<"\nEnter Your Move:- ";
         cin>>ch;
         switch(ch)
         {
         case 'W':
             {
                 if(y>0 && maze[x][y-1]!='X' && maze[x][y-1]!='#')
                   {
                     maze[x][y]='_';
                     S.push(make_pair(x,y));
                     y-=1;
                     maze[x][y] = '@';
                     steps++;
                   }
                else
                    cout<<"\nCan't Move up";
                break;
             }
         case 'A':
             {
                 if(x>0 && maze[x-1][y]!='X'&& maze[x-1][y]!='#')
                    {
                        maze[x][y]='_';
                        S.push(make_pair(x,y));
                        x-=1;
                        maze[x][y] = '@';
                        steps++;
                    }
                else
                    cout<<"\nCan't Move left";
                break;
             }
        case 'S':
             {
                 if(y>=0 && y+1<n && maze[x][y+1]!='X' && maze[x][y+1]!='#')
                    {
                        maze[x][y]='_';
                        S.push(make_pair(x,y));
                        y+=1;
                        maze[x][y] = '@';
                        steps++;
                    }
                else
                    cout<<"\nCan't Move Down";
                break;
             }

        case 'D':
             {
                 if(x>=0 && x+1<n && maze[x+1][y]!='X' && maze[x+1][y]!='#')
                    {
                        maze[x][y]='_';
                        S.push(make_pair(x,y));
                        x+=1;
                        maze[x][y] = '@';
                        steps++;
                    }
                else
                    cout<<"\nCan't Move Right";
                break;
             }
        case 'U':
            {
                int i,j;
                if(S.empty()==true)
                    {   cout<<"\nUNDO NOT POSSIBLE";
                        break;

                    }
                    else
                    {
                        pair<int,int> P=S.top();
                        i=P.first;
                        j=P.second;
                        S.pop();
                        maze[x][y] = '_';
                        maze[i][j] = '@';
                        x=i;
                        y=j;
                        steps--;
                    }
                if(lives==0)
                {
                    cout<<"\nYour Steps:- "<<steps;
                    exit(0);
                }
                else
                    lives--;
                break;
            }

        case 'Q':
            {
                cout<<"\nYour Steps:- "<<steps;
                exit(0);
            }
        }
        system("clear");
        drawMaze();

        }while(maze[x][y]!='#');
    }
 };

 int main()
 {
     int n=8;
     mazegame a(n);
     a.drawMaze();
     a.move(0,0);
     return 0;
 }
