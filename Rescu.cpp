#include <iostream>
#include <vector>
#include <unordered_map>

const int cMaxBunnies = 5;
using namespace std;

struct  Value
{
      int bRescued[cMaxBunnies];
      int location;
      int tm;
};

typedef struct Value Value_t;
typedef std::vector<int> rowType;

void Rescue_Recurse(const std::vector<rowType>& mtx, rowType& result, const Value_t& state, std::unordered_map<int64_t, Value_t>& bestStates, 
int loc, int tm)
{
   Value_t newState = state;
   cout << " Rescue_Recurse loc =" << loc << endl;
   newState.location   = loc;
   if (loc == mtx.size() - 1)
   {
      int rescued = std::count(state.bRescued, state.bRescued + cMaxBunnies, 1);
      if ((tm >= 0) && (rescued > (int)result.size()))
      {
         result.clear();
         for (int i = 0; i < cMaxBunnies; i++)
            if (state.bRescued[i])
                result.push_back(i);
      }
   }
   else if (loc > 0)
      newState.bRescued[loc-1] = 1;  
  cout << " Going to find location loc =" << newState.location << endl;
   auto curVal = bestStates.find(newState.location);
   if ((curVal == bestStates.end()) || curVal->second.tm < tm)
   {
      cout <<  "HashVal=" << newState.location <<   ", tm=" << tm << endl;
      newState.tm = tm;
      
      bestStates[newState.location] = newState;
      for (int i = 0; i < (int)mtx[loc].size(); i++)
      {
           Rescue_Recurse(mtx, result, newState, bestStates, i, tm - mtx[loc][i]);
      }
   }

}

rowType Do_Rescue(const std::vector<rowType>& mtx, int tm)
{
   std::vector<int> result;
   std::unordered_map<int64_t, Value_t> bestStates;
   Rescue_Recurse(mtx, result, {0}, bestStates, 0, tm);
   printf("{");
   for (int i: result)
      printf("%d,", i);
   printf("}\n");
   return result;
}

int main()
{
  
   Do_Rescue( {
            // 0,  1, 2, 3,  4   
       /*0*/   {0, 2, 2, 2, -1}, 
       /*1*/   {9, 0, 2, 2, -1}, 
       /*2*/   {9, 3, 0, 2, -1},
       /*3*/   {9, 3, 2, 0, -1}, 
       /*4*/   {9, 3, 2, 2,  0} 
              }, 
            1); //output: {1,2}
   // Do_Rescue({ {0, 1, 1, 1, 1}, {1, 0, 1, 1, 1}, {1, 1, 0, 1, 1}, {1, 1, 1, 0, 1}, {1, 1, 1, 1, 0} }, 3); //output: {0,1,}
}