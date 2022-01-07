/*There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

 

Example 1:

Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 
Example 2:

Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.
Example 3:

Input: rating = [1,2,3,4]
Output: 4
 

Constraints:

n == rating.length
3 <= n <= 1000
1 <= rating[i] <= 105
All the integers in rating are unique.
*/


/*
We are using Midpoint solution where 
[a,b,c]
// for any element that can be at the middle pos, we can have teams = lowerElementsOnLeft*BiggerElementsOnRight + BiggerElementsOnLeft*LowerElementsOnRight
        // e.g. 1 2 3 4 5 6 7
        // take 4 as middle
        // teams = 3 * 3 = 9
        // how? cartesian product of following
        // {1 4}  {4 5}
        // {2 4}  {4 6}
        // {3 4}  {4 7}


*/
class Solution {
public:
    int numTeams(vector<int>& rating) {
        
        //Mid Point logic
        int count=0;
        int leftLow, rightHigh, leftHigh, rightLow;
        
        
        
        for( int mid=1; mid< rating.size(); mid++){
            leftLow = rightHigh = leftHigh = rightLow = 0;
            for(int j=0; j< mid; j++){
                
                if(rating[j]< rating[mid])
                    leftLow++;
                else
                    leftHigh++;
                
            }
            
            for(int k=mid+1; k< rating.size(); k++){
                
                if(rating[k]< rating[mid])
                    rightLow++;
                else
                    rightHigh++;
                
            }
            
            count+=leftLow*rightHigh + leftHigh*rightLow;
            
        }
        
        return count;
    }
};
