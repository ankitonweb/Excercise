#include <iostream>
#include <vector>

using namespace std;
class Solution {
    public:
    int maxProfit(std::vector<int> prices) 
    {
         int result = 0;
         int valley=0;
         int peak=0;
         int maxprofit =0;
        for( int i=0; i< prices.size(); i++)
        {
             while( i< prices.size() -1 && prices[i] > prices[i+1] )
                    i++;
            valley = prices[i];
               while( i< prices.size() -1 && prices[i] < prices[i+1] )
                    i++;     
            peak = prices[i];
            maxprofit += peak - valley;

        }
        
        return maxprofit;

    }
};


int main()
{
   // std::vector<int> prices={7,1,5,3,6,4}; // Ans 7 

   // std::vector<int> prices={1,2,3,4,5}; // Ans 4
    std::vector<int> prices={7,6,4,3,1}; // Ans 0
    Solution s;
    std::cout << s.maxProfit(prices) << endl;

}