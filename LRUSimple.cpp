#include<iostream>

#include <string>
#include <list>
#include <set>


using namespace std;
class LRUCache
{
    public:
        LRUCache(int insize):size(insize){

        }
    void refer(int elem);
    void display(){

        auto it = dq.begin();
        while( it != dq.end()){
            cout << *it << endl;
            it++;
        }
    }    
    private:
    int size;
    list<int> dq; 
    set<int> mset;

};


void LRUCache::refer(int elem)
{
    auto it=mset.find(elem);
    if( it == mset.end()){
        if( dq.size() == size){
            int last = dq.back();
            dq.pop_back();
            mset.erase(last);
        }

    }else
    {
        mset.insert(elem); 
    }
        
    dq.remove(elem);
    dq.push_front(elem);

}


int main()
{
    LRUCache l(4);
    l.refer(1);
    l.refer(2);
    l.refer(3);
    l.refer(1);
    l.refer(4);
    l.refer(5);
    l.refer(2);
    l.display();
}