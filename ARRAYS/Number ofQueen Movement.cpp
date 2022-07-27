// Consider a N X N chessboard with a Queen and K obstacles. The Queen cannot pass through obstacles. Given the position (x, y) of Queen, the task is to find the 
// number of cells the queen can move.

// Examples: 

// Input : N = 8, x = 4, y = 4, 
//         K = 0
// Output : 27
#include<bits/stdc++.h>
using namespace std;
int range(int n ,int x,int y)
{
    return (x<=n&&x>=0&&y<=n&&y>0);
}
// this function will return the number of moves according the movement of the queen
int check(int n,int x,int y,int xx,int yy,map<pair<int , int>,int>mp)
{
    int ans=0;
    //checking valid move for the queen in the direction
    while(range(n,x,y)&&!mp[{x,y}])
    {
        x+=xx;y+=yy;ans++;
    }
    return ans;
}
// this function will return the number of positions the queen can move
int numberOfPositions(int n ,int k,int x,int y,vector<int>obstacle_x,vector<int>obstacle_y)
{
    int x1,y1,ans=0;
    map<pair<int,int>,int>mp;
    while(k--)
    {
        x1=obstacle_x[k];
        y1=obstacle_y[k];
        mp[{x1,y1}]=1;
    }
    //now calculating the number of moves according to the queen possible movements
    ans+=check(n,x+1,y,1,0,mp);
    ans+=check(n,x-1,y,-1,0,mp);
    ans+=check(n,x,y+1,0,1,mp);
    ans+=check(n,x,y-1,0,-1,mp);
    ans+=check(n,x+1,y+1,1,1,mp);
    ans+=check(n,x+1,y-1,1,-1,mp);
    ans+=check(n,x-1,y+1,-1,1,mp);
    ans+=check(n,x-1,y-1,-1,-1,mp);
    return ans;
}




int main()
{
    int n;
    int k;
    int obs_x,obs_y;
    vector<int>obstacle_x ;
    vector<int>obstacle_y;
    cout<<"enter the size of the chessboardd"; // n*n size chessboardd
    cin>>n;
    cout<<"enter the number of obstacles in the chess board";
    cin>>k;
    int Qpos_x=4,Qpos_y=4;//initial position of the queen
     cout<<"enter the positions of the obstacles ";
    while(k--)
    {
      cout<<"enter the row position of obstacle "<<k+1<<endl;
      cin>>obs_x;
      obstacle_x.push_back(obs_x);
      cout<<"enter the column positon of the obstacle "<<k+1<<endl;
      cin>>obs_y;
      obstacle_y.push_back(obs_y);
    }
    cout<<numberOfPositions(n,k,Qpos_x,Qpos_y,obstacle_x,obstacle_y)<<endl;
    return 0;
    
}
