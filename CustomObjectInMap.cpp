#include <iostream>
#include <map>

using namespace std;
class Data
{
    
    public:
        Data( int v){
            val = v;
        }
        ~Data(){     
        }
    int val;
    bool operator < ( const  Data &r) const{
         return r.val < val;

    }

};


int main()
{
    map<Data,int> mymap;

    for ( int i=0; i< 10; i++){
        Data d(i);
        mymap[d]=i;
    }
    string s;

    s.compare
    auto it=mymap.begin();
    while( it !=mymap.end()){
        auto &data=it->first;
        std::cout<<  data.val << endl;
        it++;
    }
}

