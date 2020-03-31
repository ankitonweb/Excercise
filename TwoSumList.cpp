// Example program
#include <iostream>
#include <string>
#include <algorithm>  
#include <vector>  
using namespace std;
bool myfunction(int a, int b)
{
    return a<b;
}
int main()
{
  int myints[] = {4, 7, 1 , -3, 2};
  std::vector<int> v(myints,myints+5);         
  int K=5;
  auto it=v.begin();
   sort(v.begin(), v.end(),myfunction);
   for( int &a: v)
   {
      cout<< "a="<< a << endl;
   }
  while(it!=v.end() )
  {   
       int current=*it;
       int key =K - current;
       cout<< "key=" << key << ", current="<< current<<endl;
       if(std::binary_search(it, v.end(),  key,myfunction)) {
         cout<< "Yes got the value ="<< key << ", current=" << currentendl;
         break;
       }
       it++;
  }
  return 0;
   
}