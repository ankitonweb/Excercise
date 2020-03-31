#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    
    int numRollsToTarget(int d, int f, int target) {
        int dp[31][1001];

        for( int i=0; i < 31 ; i++)
             for( int j=0; j< 1001; j++){
                 dp[i][j]  =0;
             }
        
        if (target > d * f) {
            return 0;
        }
        
        if (d == 1) {
            return (target > f ? 0 : 1);
        }
        
         
        
        return rollDice( d, f, target, dp);
        
    }
    
   static long long int rollDice(int d, int &f, int  curSum, int dp[31][1001]){
        if (dp[d][curSum]) {
            return dp[d][curSum];
        } 
       
       if (d == 1) {
    	   return (curSum > 0 && f >= curSum ? 1 : 0);
    	}
       
        long long int res = 0;
       
       for (int i = 1; i <= f; i++) {
            res += rollDice(d - 1, f, curSum - i, dp);
            res = res % 1000000007;
        }
        dp[d][curSum] = res;
        return res;
       
   }
};

int main()
{
    Solution  s;
    std::cout << s.numRollsToTarget(30,30, 500) << endl;

}