#include <iostream>
#include <vector>
//https://www.geeksforgeeks.org/find-the-maximum-repeating-number-in-ok-time/
using namespace std;

int main()
{
     int arr[] = {2, 3, 3, 5, 3, 2, 4, 7}; 
     int N=8;
     int max=0;
     int index = -1;

     for( int i = 0 ; i < N; i++){
          cout << "i=" << i << ", arr[i]= "<< arr[i] <<  " arr[i] %N="<<  arr[i] %N << endl; 
          arr[  arr[i] %N ] +=N;
          cout << "Now " <<  " arr[arr[i] %N]="<<  arr[arr[i] %N] << endl; 
          if( max < arr[arr[i] %N ]/N){
              max = arr[arr[i] %N ]/N;
              index = arr[i] %N;
          }
     }
     vector<pair<int,int> > vect;

    for( int i = 0 ; i< N; i++){
         if( arr[i]/N == max )
             {
                cout << "max=" << max << ", index=" << i << endl;
                break;
             } 
        
    }

    

}