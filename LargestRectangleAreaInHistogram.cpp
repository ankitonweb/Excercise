/*
https://leetcode.com/problems/largest-rectangle-in-histogram/
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104
Accepted
467,852
Submissions
1,164,071

*/



class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int length=heights.size();
        int maxArea=0;
        
        for( int i=0;i<heights.size(); i++){
            
            while(st.top() != -1 && heights[st.top()]>=heights[i]){
                int currentHeight = heights[st.top()];
                st.pop();
                int currentWeidth =  i -st.top() -1;
                int currArea = currentHeight*currentWeidth;
                if(currArea >maxArea)
                    maxArea = currArea;
                
                
            }
            st.push(i);
            
        }
        
        while(st.top()!=-1){
             int currentHeight = heights[st.top()];
                st.pop();
                int currentWeidth =  length -st.top() -1;
                int currArea = currentHeight*currentWeidth;
                if(currArea >maxArea)
                    maxArea = currArea;
                
            
        }
        
        return maxArea;
        
    }
};
