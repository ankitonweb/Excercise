#include <string>
#include <vector>
#include <iostream>
using namespace std;

enum class Color { red, green,blue};
enum class Size {small,medium,large};

class Product
{
    public:
    string name;
    Color color;
    Size size; 
};

template <typename T> class Specification
{
    public:
   virtual ~Specification() = default;
   virtual bool is_satisfied(T* item) const = 0;
};

template <typename T> struct AndSpecification : public  Specification<T>
{
    public:
     const Specification<T> &first;
     const Specification<T> &second;

     AndSpecification( const Specification<T>& first, const Specification<T>& second) : first(first), second(second)
     {
         
     }

    bool is_satisfied(T* item) const {
        return first.is_satisfied(item) && second.is_satisfied(item);     
    }   
      


};

template <typename T> class Filter
{
    public:
    virtual vector<T*> filter( vector<T*> items, Specification<T> &spec) = 0;
};

class ColorSpecification: public Specification<Product>
{   public:
    Color color;
    ColorSpecification(Color color ):color(color){

    }
    bool is_satisfied(Product* item) const {
          return item->color == color;
    }
};
class SizeSpecification: public Specification<Product>
{   
    public:
    Size size;
    SizeSpecification(Size size):size(size){

    }
    bool is_satisfied(Product* item) const {
          return item->size == size;
    }
};


class BetterFilter: public Filter<Product>
{
    public:
    vector<Product*> filter( vector<Product*> items, Specification<Product> &spec){
            vector<Product*> result;
            for (auto& p : items)
                if (spec.is_satisfied(p))
                      result.push_back(p);
    return result;
    }

};

int main()
{
  Product apple{"Apple", Color::green, Size::small};
  Product tree{"Tree", Color::green, Size::large};
  Product house{"House", Color::blue, Size::large};
  const vector<Product *> all = { &apple, &tree,&house};
  
  BetterFilter bf;
  ColorSpecification cp(Color::green);
  auto green_things = bf.filter(all, cp);
  cout << green_things.size() << endl;
  for (auto& x : green_things)
    cout << x->name << " is green\n";

    SizeSpecification large(Size::large);
    AndSpecification<Product> green_and_large(cp, large);
    auto big_green_things = bf.filter(all, green_and_large);
    for (auto& x : big_green_things)
    cout << x->name << " is green and large\n";
}