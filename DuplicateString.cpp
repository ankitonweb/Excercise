#include <string>
#include <set>
#include <locale>  
#include <ctype.h>
#include <iostream>
using namespace std;
std::string duplicate_encoder(const std::string& word){
  std::string result;
  int  alpha[256]={};
  for( int i=0; i < 256 ; i++){
       alpha[i] = -1;
  }
 
  for(    int loopi=0 ; loopi< word.length(); loopi++ )
  {
     int index = word[loopi];
     std::cout << index << endl;;
     if(std::isalpha(word[loopi]))
     {
         index = std::tolower( word[loopi])-  'a';
     }
      std::cout << index << endl;;
     if( alpha[index]==-255 )
         
         result+=')';
     else
     {
         if( alpha[index] == -1)
         {  
             result+='(';
            alpha[index] = loopi;
         }else
         {
             /* code */
             int clear_index =  alpha[index] ;
             result[clear_index] = ')';
             alpha[index] = -255;
               result+=')';
         }
         
     }
     
  }
  

  cout << result << endl;
  return result;
}

int main(){

    std::string str="recede";
    cout << duplicate_encoder(str);

}