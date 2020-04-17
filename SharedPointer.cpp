r#include <iostream>
#include <string>

using namespace std;

class ReferenceCount
{
    int count{0};

    public:
        void increase(){
            count++;
        }

        void decrease(){
            count--;
        }

        int get(){
            return count;
        }

};

template <typename T>
class mshared_ptr 
{
    public:
            mshared_ptr( T *input):object(input),ref(new ReferenceCount()){
                      ref->increase();
                       cout << "createdsmart_ptr! Ref count is "<< ref->get() << endl;
            }
            mshared_ptr( const mshared_ptr<T> &other):object(other.object),ref(other.ref){
                ref->increase();
                cout << "Copied smart_ptr! Ref count is "<< ref->get() << endl;


            }
            mshared_ptr<T>& operator=( const mshared_ptr<T> &other) 
            {

                if( this != &other)
                {
                        if( ref != NULL   )
                        {
                            ref->decrease();
                            if( ref->get() == 0){
                                delete object;
                                delete ref;
                            }
                        }
                    object = other.object;
                    ref    = other.ref;
                    ref->increase();
                    cout << "Assigned smart_ptr! Ref count is " << ref ->get() << endl;
                    
                }
                return *this;
            }
            virtual ~mshared_ptr(){
                 cout << " Inside destroy " << ref->get() << endl;
                    ref->decrease();
                    if( ref->get()<=0)
                        {
                             
                            cout << " destroying ! Ref count is " << ref->get() << endl;
                            delete ref;
                            delete object;

                        }else
                        {
                             cout << " Inside destroy  reduced count ...doing nothig " << ref->get() << endl;
                        }
                        
                 
            }

            T& operator*(){
                return *object;
            }

            T* operator->(){
                 return  object;   
            }
    private :
        T* object;
        ReferenceCount *ref;

};





int main(){

 mshared_ptr<string> mshptr(new string("Jai shri ganesh"));
 cout << *mshptr << endl;
 
mshared_ptr<string>  second = mshptr;
{ 
    mshared_ptr<string>  third(new string("Jai shri Ashapura Maa")) ;
    cout << *third << endl;

      third = second;   
     cout << "After assignment" << *third << endl;

}




}