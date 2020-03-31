#include <iostream>
#include <string>
#include <vector>
using namespace std;
using namespace std;
//https://leetcode.com/problems/merge-intervals/solution/
int main(){
   vector<pair<int,int>> vect = { {6,8}, {1,9}, {2,4}, {4,7} , { 10,15}, { 15, 20 }, {19,22}};
    //vector<pair<int,int>> vect = { {6,8},} {1,3, {4,8}};
    sort(vect.begin(),vect.end());

    vector<pair<int,int>> result;
    int index = 0;



    for( int loopi = 1 ; loopi < vect.size() ; loopi++){

          if( vect[index].second >= vect[loopi].first  )   
          {
              vect[index].first = std::min(vect[index].first, vect[loopi].first);
              vect[index].second = std::max(vect[index].second, vect[loopi].second);
          }else{
              index++;
              vect[index] = vect[loopi];  
          }
    }

     for( int loopi = 0 ; loopi <= index  ; loopi++){
        cout << vect[loopi].first << ", " << vect[loopi].second << endl;

    }

}