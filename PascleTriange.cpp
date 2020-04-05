#include<iostream>
#include <vector>

//https://leetcode.com/problems/pascals-triangle/discuss/557626/100-speed-100-space-C%2B%2B
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
           
        vector<vector<int>> result;

        for( int row=1; row <=numRows ; row++ )
        {
            vector<int> r;
            result.push_back(r);
            for( int j=1; j <=row; j++)
            {
                if( j == 1 || j == row)
                    result[row-1].push_back(1);
                else
                    result[row -1 ].push_back(result[row -2 ][j-2] +  result[row -2 ][j-1]); 
            }
        }
      
        return result;
      
       
    }
};


int main()
{

}