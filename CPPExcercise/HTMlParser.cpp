#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
using namespace std;

enum  {
    INIT = 0, START_TAG, ATRRIBUTE, END_TAG

};

class ParsingError : public exception
{
    string reason;
    
    public: 
    ParsingError(const char *rs){
        reason.append(rs);
    }
    const char* what(){

            return reason.c_str();
    }

};
class HTMLDoc;
class HTMLDoc
{
    vector<HTMLDoc*> child;
    unordered_map<string,string> attribute;
    int state;
    string tagName;
    

    public:
    ~HTMLDoc(){
        while( child.size()>0){
            HTMLDoc* c = child.back();
            delete c;
            child.pop_back();
        }
    }
    HTMLDoc(){
        state = INIT;
    }
    void setTagName(string &str){
        tagName=str.substr( 1,  str.size());
        state = START_TAG;
    }

    void addAttribute(string &key,string &val){
        attribute[key]=val;
        state = ATRRIBUTE;
    }
    void addChild(HTMLDoc *ch){
        child.push_back(ch);
    }
    void gotEndTag(){
        state = END_TAG;
    }

    string& getTagName(){
        return tagName;
    }
};



class HTMLParser
{
    
    
    public:
    HTMLDoc* parse(vector<string> &texts){
        
        HTMLElementTreeBuilderImpl  htmlTreeBuilder;
        HTMLDoc*  root =  htmlTreeBuilder.buildTree(texts);

        return root;
    }

};


class HTMLElementTreeBuilderImpl
{
    private:
    vector<string> tvector;
    int  pIndex;

    public:
       HTMLDoc* buildTree(vector<string> &texts){
           pIndex = 0;
           this->tvector = texts;
            return buildTree();
       }
       HTMLDoc *buildTree(){
           HTMLDoc *currNode = new HTMLDoc();
           if( !isStartTag()){
                throw  ParsingError("No start tag");
           }
           
           currNode->setTagName(tvector[pIndex]);  
           pIndex++;
           while( isAttribute()) {
               addAttriBute(currNode);
               pIndex+=3;
           }
          
           while(!isEndTag(currNode)){
               HTMLDoc *childNode = buildTree();
               currNode->addChild(childNode);
           } 
           currNode->gotEndTag();
           pIndex++;
           return currNode;
       }
        bool isAttribute(){
            if(pIndex < tvector.size() -2 && tvector[pIndex+1] == "="){
                return true;
            }
            return false;
        }
        bool isEndTag(HTMLDoc *currNode)
        {
            if( pIndex >= tvector.size())
                throw ParsingError("No End tag");

             string &str=tvector[pIndex];
             string &tagName = currNode->getTagName();
             for( int i=0, j=2; i< str.length() -1 &&  j < tagName.size(); i++, j++){
                  if(str[i]!=tagName[j])
                    return false;
             }
              return true;

        }
        void addAttriBute(HTMLDoc *currNode){
            string &key=tvector[pIndex];
            string &eq=tvector[pIndex+1];
            string &val=tvector[pIndex+2];
            if(val.back() == '>')
               val.pop_back();
            currNode->addAttribute(key,val);

        }
       bool  isStartTag(){
            string &curr = tvector[pIndex];
            if(curr[0] == '<'  && curr[1] !='/')
                return true;
            return false;
       }

        bool  isEndTag(){
            string &curr = tvector[pIndex];
            if(curr[0] == '<'  && curr[1] =='/' && curr.back() == '>')
                return true;
            return false;
       }

};

class HTMLParserFactory
{
    HTMLParser *html_parser =nullptr;
    public:
        static HTMLParserFactory* newInstance(){
            HTMLParserFactory *factory = new HTMLParserFactory();
            return factory;
        }
        HTMLParser*  newHTMLParser(){
            if( html_parser == nullptr){
                html_parser = new HTMLParser();
            }
            return html_parser;
        }   
};


 void  split( string &instr,vector<string> &tokens )
    {
            stringstream ss(instr);
            string str;
            while( ss >> str){
                tokens.push_back(str);
            }

           
    }

int main()
{
     
    HTMLParserFactory *factory = HTMLParserFactory::newInstance();

    HTMLParser *html_parser = factory->newHTMLParser();

     int N =0, Q =0;
    cin>> N ;
    cin >> Q;
    string line;
    getline(cin, line);
    
    vector<string> htmlstring;
    for( int i = 0; i < N ; i++){
        getline(cin, line);
        vector<string> tokens ;
        split(line,htmlstring);
    }
    HTMLDoc *root_doc = html_parser->parse( htmlstring); 





}       