#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{

    std::vector<int> vec={2,8,6,5,7,10,11,1,3};
    int left = 0;
    int right = 0;
    int sum =0;
    int target = 22;
    sum=vec[left];

    while(left <=right)
    {
        if( sum  < target)
        {

            right++;
             cout << "sum < target left=" << left << ".right=" << right <<  ", Sum=" << sum << endl;
            if( right < vec.size())
                sum+=vec[right];
            else
            {
                break;
            }
        }
        else if ( sum > target )
        {
            cout << "sum > target left=" << left << ".right=" << right <<  ", Sum=" << sum <<  endl;
            sum-=vec[left];
            left++;
             if( sum == target)
             {    
                cout << "Got it left=" << left << ".right=" << right << ", sum=" << sum << endl;
                break;
            }
            
            
            if( left >=  vec.size()){
                 break;
            }
            

        }

        if( sum == target)
        {    
                cout << "Got it left=" << left << ",right=" << right << ", sum=" << sum << endl;
                break;
        }
        

        
    }

}