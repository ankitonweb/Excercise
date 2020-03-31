#include <iostream>     // std::cout
#include <functional>   // std::multiplies
#include <numeric>      // std::adjacent_difference
#include <vector>

int myop (int x, int y) {return x+y;}

int main()
{
  int val[] = {1,2,3,5,9,11,12};
  float vect[7];
  //std::vector<int> vect;
  //auto it = vect.begin();
  std::adjacent_difference(val,val+7, vect,std::divides<float>());
  for( int i=0; i< 7; i++)
     std::cout << vect[i] << std::endl;
  
}