#include <iostream>
#include <vector>
using namespace  std;

class PairSum
{

    public: 
      vector<pair<int,int>>  findPairSum( vector<int> &arr, int sum )
      {
          vector<pair<int, int>> result;

          int pivot = -1; 
          int left=0, right=arr.size() -1;

         

          while( left < right){
               int mid = left + (right - left)/2;
              if( arr[mid] > arr[right] ){
                  left = mid + 1;
              }else{
                  right = mid;
              }

          }
          //cout << arr[left] << endl;
          pivot = left;
          right =  pivot -1 ;
          while( left !=right){
              
              if( arr[left] + arr[right] ==  sum ){
                  result.push_back(make_pair(left, right));
                 
                    if(  left == right)
                         return result;
                     left = (left +1)%arr.size(); 
                   //  right = (right -1 + arr.size()) %arr.size();
                     continue;
              }
              if( arr[left] + arr[right] > sum){
                   right = (right -1 + arr.size()) %arr.size();
              }else{
                  left = (left +1)%arr.size();
              }


          }


            return result;
      }


};






int main()
{
     vector<int> arr{11, 15, 6, 7, 9, 10}; 
    //vector<int> arr{4, 5, 6, 7, 0, 1,2,3}; 
    int sum = 16; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    PairSum p;
    auto v = p.findPairSum(arr,16);
    for( auto i: v)
    cout <<  "("  << arr[i.first] << ", " <<  arr[i.second] << ")" << endl;
      
    

}