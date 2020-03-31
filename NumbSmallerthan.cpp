// inserting into a vector
#include <iostream>
#include <vector>
using namespace std;
class Solution 
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        vector<int> vect(nums);
        std::sort(vect.begin(), vect.end());
        int bucket[vect[nums.size() -1] + 1];
        std::fill(bucket,bucket+vect[nums.size() -1] + 1,0);
        
        for( int index=0; index < vect.size(); index++){
              
              int number = vect[index];
              cout << "number=" << bucket[number] << endl; 
              if(bucket[number] == 0 ){
                  bucket[ number] = index;
                  
              }
        }
      
        std::vector<int> result;
        for( auto &key: nums){
            
             result.push_back( bucket[key]);
        }
        return result;
    }
};


int main(){
    Solution s;
    vector<int> vec = {8,1,2,2,3};
    /* In this problem we should find the count of all the numbers smaller than the current number in the index of array.
    */
    auto  res =  s.smallerNumbersThanCurrent(vec);
    for( auto &num: res)
        cout << num << endl; 
}