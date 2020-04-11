#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
void  display(string str,int depth){

    for( int i=0; i<=depth; i++)
         cout << " " ;
     cout << str << endl;    
}


void PrintBracedText(vector<string> input, int index, int depth ){
    if( index >= input.size() || index < 0)
        return;
     string str=input[index];
     if( str == "(")
     {
         display(str,depth); 
         PrintBracedText(input,index+1, depth+1);
         display(")",depth); 
     } else if( str == ")") 
     {
         //display(str,depth); 
         //PrintBracedText(input,index+1, depth-1);
         return;
     }else 
     {
          display(str,depth);  
          PrintBracedText(input,index+1, depth);
     }
    

}



int main()
{
    string input="( OM ( ShriGanesh ( Namaha ) ) )";
    vector<string> parsedInput;
    stringstream ss(input);
    string token;
    while( ss>>token){
        parsedInput.push_back(token);
    }
    PrintBracedText(parsedInput,0,0);

}

