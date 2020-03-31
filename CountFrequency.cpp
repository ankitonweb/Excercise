#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int countFrequency(int array[], int number, int array_size ){

    int *low = std::lower_bound(array, array+array_size, number );
    if( low == array+array_size || *low !=number)
         return 0;
    int *high =   std::upper_bound(array, array+array_size, number );

    return high - low;
}




int main(){

    int array[]={1, 2, 2, 3, 3, 3, 3};

    cout << countFrequency(array, 8, 7) << endl;
}