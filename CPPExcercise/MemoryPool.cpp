#include<iostream>

using namespace std;

enum  MemPoolSize {
    MAX_MEMPOOL_SIZE = 32
};
template <class T>
class MemoryPool
{

    size_t size;
    
    MemoryPool<T> *available;

    public:
    int availCount = 0;
    int usedCount = 0;
         MemoryPool(size_t size = MAX_MEMPOOL_SIZE )
         {
             available=nullptr;
            // expandFreeList(size);
         }
         ~MemoryPool(){
             MemoryPool<T> *NextPtr = available;
             for(NextPtr = available; NextPtr !=nullptr ;  ){
                 available = available->available;
                 if(NextPtr!=nullptr &&  NextPtr !=this)
                   delete  NextPtr;
                  NextPtr = available;
             }
             

         }
         virtual void* allocate(size_t insize);
         virtual void  free(void *release);
         
         void expandFreeList(int additional);


    
};
template <class T>
void * MemoryPool<T> ::allocate(size_t required)
{
    if(available == nullptr){
        expandFreeList(MAX_MEMPOOL_SIZE);
    }
     MemoryPool<T> *head = available;
    available = available->available;
    usedCount++;
    availCount--;
    return head;
}

template <class T>
void MemoryPool<T>::free(void * release)
{
    MemoryPool<T> *head =  (MemoryPool<T> *) (release);
    head->available = available;
    available = head;
     availCount++;
     usedCount--;
}
template <class T>
void MemoryPool<T>::expandFreeList(int additional){

    size_t sz = ( sizeof(T) > sizeof(MemoryPool<T> *)) ? sizeof(T):sizeof(MemoryPool<T> *);
    char *temp = new char[sz];
    MemoryPool<T> *holder =  (MemoryPool<T> * ) (temp);

    available = holder;
    for( int i=0; i< additional ; i++ ){
        temp = new char[sz];
        holder->available =   (MemoryPool<T> *) (temp);
        holder = holder->available;
    }
    holder->available = nullptr;
    availCount+=additional;
    
}


class Rational
{

    static MemoryPool<Rational> *mempool;
    int a;
    int b;
    public:
     Rational(int a, int b):a(a),b(b){

     }
     void display(){
         cout << " a =" << a <<  ", available=" << mempool->availCount << " used=" << mempool->usedCount << endl;
     }
     void* operator new(size_t size)
     {
        return mempool->allocate(size);
    }
     void operator delete(void *release)
     {
         
        return mempool->free( release);
    }

    static void initMemPool(){
        mempool = new MemoryPool<Rational>(32);
        mempool->expandFreeList(32);

    }
     static void deleteMemPool(){
       cout <<   mempool->availCount << " used=" << mempool->usedCount << endl;  
       delete mempool;  
    }

};
 MemoryPool<Rational> *Rational::mempool = nullptr;
int main()
{
   
    Rational *array[1000];

    Rational::initMemPool();
    
    for( int i=0; i< 10 ; i++){
        array[i] = new Rational(i,i+1);
        array[i]->display() ;

    }
    /* for( int i=0; i< 10 ; i++)
      { 
             array[i]->display() ;
      }
    */
    for( int i=0; i< 10 ; i++)
      { 
           delete  array[i] ;
      }
   Rational::deleteMemPool();
    
}