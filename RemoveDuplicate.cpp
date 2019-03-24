#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <algorithm>  

/*
   using lamda function and STL to remove the duplicates, it helps us in keeping the order of elements
*/


int main() 
{
 // a list of ints
   set<int> myset;
int myInts[] = {1,2,3,4,5,6,7,1,5,2,4,6};
vector<int> v;
 
v.insert(v.begin(), myInts, myInts + 10);
  
v.erase(std::remove_if(v.begin(), v.end(),  
  [&](int i) {
                   auto it = myset.find(i);
                   if( it != myset.end()){
                        return true;
                  }else
                  {
                      myset.insert( i);
                       return false;
                  }
          } 
  ),v.end()); 
  
  
  
  auto it = v.begin();
  while(it != v.end()) 
  {

     cout << *it <<  " " ; 
     it++;
    
  }
  return 0;
}
