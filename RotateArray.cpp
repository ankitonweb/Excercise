#include <iostream>     
#include <algorithm>    
#include <vector>       
//g++ -std=gnu++17 -o RotateArray RotateArray.cpp 

using namespace std;
vector<int> solution(vector<int> &A, int K) 
{
    // wif( rite your code in C++14 (g++ 6.2.0)
     if( A.size() <= 1)
         return A;
         
    if( K > A.size() )
        K=K% A.size();
     std::reverse(A.begin(), A.end());
     std::reverse(A.begin()+K, A.end() ); 
     std::reverse(A.begin(), A.begin() +K);
    
    return A;
}

int main(){

  return 0;
}
