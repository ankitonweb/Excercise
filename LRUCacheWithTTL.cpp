#include <iostream>
#include <string>
#include <unordered_map>
#include <list>

#include <queue> 

using namespace std;
class Data
{
    public:
    int value;
    int expires;
    bool operator < ( const Data& p1) const
   { 
  
    // this will return true when second Data  
    // has greater height. Suppose we have p1.height=5  
    // and p2.height=5.5 then the object which 
    // have max height will be at the top(or  
    // max priority) 

    if(p1.expires  ==  this->expires )
        return p1.value > this->value;     
    else 
    return p1.expires < this->expires; 
    
    }

    bool operator > ( const Data& p1) const
   { 
  
    // this will return true when second Data  
    // has greater height. Suppose we have p1.height=5  
    // and p2.height=5.5 then the object which 
    // have max height will be at the top(or  
    // max priority) 

    if(p1.expires  ==  this->expires )
        return p1.value > this->value;     
    else 
    return p1.expires > this->expires; 
    
    }

};

 
class LRUCacheTTL
{

    public:
        LRUCacheTTL(int size){
            this->size = size;
        }
    int get(int key, int ts){
       
         while( !pq.empty()){
             Data d=pq.top();
             cout << d.expires  <<"," << d.value << endl;
             pq.pop();
         }

        return -1;

    }
    void put( int value,int expireTime){

        
        Data data{value,expireTime};
        pq.push(data);
        
    }
    private:
    int size;
    
    priority_queue<Data > pq; 
    unordered_map<int, Data> mymap;


}; 


int main()
{
    LRUCacheTTL lrucache(2);
    lrucache.put(3,10);
    lrucache.put(4,5);
    lrucache.put(6, 10);
    cout << lrucache.get(2, 1)<< endl;

}