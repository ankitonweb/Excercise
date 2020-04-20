#include<iostream>
#include <vector>
#include <queue>
using namespace std;
    int cx[4] = {0,0,1,-1};
    int cy[4] = {1,-1,0,0};
class Node
{
    public:
    int w;
    int x;
    int y;
}; 
class comp
{
    public:
        bool operator() (  const Node & a, const Node b){
                    return a.w > b.w;
        }
};

class Dijkastra
{
    vector<vector<int>>& grid;
    vector<vector<bool>> visited;
    vector<int>  dist;
    public:
            Dijkastra(vector<vector<int>>& g):grid(g){
                 vector<vector<bool>> v(grid.size(), vector<bool>(grid.size(), false));
                 visited = v;
                 int m = numeric_limits<int>::max();
                 dist.resize(grid.size(),m);
            }
             ~Dijkastra(){

             }

          int   FindMini( )
          {
                int ans=0;
                priority_queue<Node, vector<Node>, comp> pq;
                pq.push({grid[0][0],0,0} );
                visited[0][0]= true;
                dist[0] = 0;
                
                while(!pq.empty()){
                     
                    Node currNode = pq.top();
                    ans = currNode.w;
                    pq.pop();
                    int x=currNode.x;
                    int y=currNode.y;
                    if( x == grid.size() -1 && y == grid.size() -1)
                    {
                        return ans;
                    }
                    
                    for( int i=0; i< 4 ; i++){
                        int X=x+cx[i];
                        int Y=y+cy[i];
                        if( X>=0 && X< grid.size() && Y>=0 && Y< grid.size() && !visited[X][Y]){
                            visited[X][Y] = true;
                            pq.push({ans+grid[X][Y],X,Y});
                        }
                    }
                    
                }

              return  ans;
          }

};


int main()
{
    vector<vector<int>> grid{
                              {1,3,1},
  {1,5,1},
  {4,2,1}
    };
    for( auto x:grid){
        for( int i:x)
        cout << i << " " ;
        cout << endl;
    }
    Dijkastra d(grid);
    cout << d.FindMini() << endl;

}