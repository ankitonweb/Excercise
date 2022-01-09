/*

//https://leetcode.com/problems/cut-off-trees-for-golf-event/

You are asked to cut off all the trees in a forest for a golf event. The forest is represented as an m x n matrix. In this matrix:

0 means the cell cannot be walked through.
1 represents an empty cell that can be walked through.
A number greater than 1 represents a tree in a cell that can be walked through, and this number is the tree's height.
In one step, you can walk in any of the four directions: north, east, south, and west. If you are standing in a cell with a tree, you can choose whether to cut it off.

You must cut off the trees in order from shortest to tallest. When you cut off a tree, the value at its cell becomes 1 (an empty cell).

Starting from the point (0, 0), return the minimum steps you need to walk to cut off all the trees. If you cannot cut off all the trees, return -1.

You are guaranteed that no two trees have the same height, and there is at least one tree needs to be cut off.

 

Example 1:


Input: forest = [[1,2,3],[0,0,4],[7,6,5]]
Output: 6
Explanation: Following the path above allows you to cut off the trees from shortest to tallest in 6 steps.
Example 2:


Input: forest = [[1,2,3],[0,0,0],[7,6,5]]
Output: -1
Explanation: The trees in the bottom row cannot be accessed as the middle row is blocked.
Example 3:

Input: forest = [[2,3,4],[0,0,5],[8,7,6]]
Output: 6
Explanation: You can follow the same path as Example 1 to cut off all the trees.
Note that you can cut off the first tree at (0, 0) before making any steps.
 

Constraints:

m == forest.length
n == forest[i].length
1 <= m, n <= 50
0 <= forest[i][j] <= 109
Accepted
51,314
Submissions
144,642
Seen this question in a real interview before?

Yes

No
*/

import java.util.*;
class Node{
    
    public int x,y,height;
    
    public Node(int x,int y,int height){
        this.x = x;
        this.y = y;
        this.height = height;
    }
    
}



class Solution {
    
    int dx[]= {1,-1,0,0};
    int dy[]={0,0,1,-1};
   
    public int cutOffTree(List<List<Integer>> forest) {
        PriorityQueue<Node> pq = new PriorityQueue<>((a,b)->a.height - b.height);
        for( int i=0; i < forest.size(); i++){
            for( int j=0; j<forest.get(i).size(); j++){
                  Node node = new Node(i,j,forest.get(i).get(j));
                if(node.height>1)
                    pq.add(node);          
            }
        }
        
    
        
        int totalDistance = 0;
        Node current = new Node(0,0,forest.get(0).get(0));
        while(!pq.isEmpty()){
            Node next = pq.poll();
            int dist = findShortestDistance(forest,current,next);
            
            if( dist == -1){
                return -1;
            }
            totalDistance+=dist;
            current = next;
        }
        return totalDistance;
      
    }
    
    public int findShortestDistance(List<List<Integer>> forest, Node current, Node dst){
        int distance = 0;
        boolean visited[][] = new boolean[forest.size()][forest.get(0).size()];
        visited[current.x][current.y] = true;
        Queue<Node> queue = new LinkedList<Node>();
        queue.add(current);
        int steps=0;
        while(!queue.isEmpty()){
            int qsize = queue.size();
            
            for( int i=0;i<qsize; i++){
                 Node next = queue.poll();
                 if( next.x == dst.x && next.y == dst.y){
                     return steps;
                 }
                
                 for( int idx=0; idx < 4; idx++){
                     int X=next.x + dx[idx];
                     int Y=next.y + dy[idx];
                     if(isValid(forest,X,Y,visited)){
                         Node nbr = new Node(X,Y,forest.get(X).get(Y));
                         queue.add(nbr);
                         visited[X][Y] = true;
                     }
                 }
                
            }
            
            steps++;
            
        }
        
        return -1;
    }
    
    public boolean isValid(List<List<Integer>> forest,int x, int y,boolean visited[][]){
        if( x>= forest.size() || x< 0 || y>= forest.get(0).size() || y< 0)
            return false;
        if( visited[x][y] == true || forest.get(x).get(y) == 0)
            return false;
        
        return true;
    }
}
