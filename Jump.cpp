// C++ program for Minimum number of jumps to reach end 

#include <iostream>
using namespace std; 

int min(int x, int y) { return (x < y) ? x : y; } 

// Returns minimum number of jumps 
// to reach arr[n-1] from arr[0] 
int* jumps = NULL;

int *arr;
int minJumps( int curr, int target) 
{ 
    
  if (target == 0 || arr[0] == 0) 
		return INT_MAX; 
   if( curr > target)
        return 1; 
  if( jumps[curr]!=INT_MAX)  
      return jumps[curr];
       
   if( curr == target)
   {
        return 0;
   }
   if( arr[curr] == 0)
       return INT_MAX;

   jumps[curr] = min( minJumps(  curr+arr[curr], target )+1, minJumps( curr++, target )+1  ); 


   return jumps[curr];
	
	
	

	//return jumps[n - 1]; 
} 




// Driver code 
int main() 
{ 
  
	int arr1[] = {  2,3,1,1,4}; 
    arr=arr1;
	int size = sizeof(arr) / sizeof(int); 
     jumps = new int[size+1]; 
     for (int i = 0; i < size; i++)
          jumps[i] = INT_MAX;
          minJumps( 0,4);
	cout << "Minimum number of jumps to reach end is " << jumps[size-1]; 
	return 0; 
} 
