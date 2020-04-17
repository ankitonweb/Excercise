#include<iostream>
#include <SessionCleanup.h>
#include <vector>

using namespace std;
class SessionCleanup
{
    public:
        static void init( CallBack *m_callback);
        static void clearSession(vector<string> vect);

    private:
        CallBack *m_callback;
        class SessionCleanupImpl;
        SessionCleanupImpl *pimpl;
        SessionCleanup(){

        }

        ~SessionCleanup(){

        }


};

class SessionCleanup::SessionCleanupImpl
{
 public:
   void clearSession(vector<string> sessions)
   {
       Trunk trunks = Trunk::trunkFactory(sessions.size);
       TransportLayer transport =  TransportLayer::init(trunks);
       TransactionLayer  transaction = TransactionLayer::init(transport,callback);
       for( string session: sessions){

           SipRequest req = Parser::createRequest(session);
           transaction.send(req);

       }    

   }

   private:
        CustomSipStack *sipstack;
        {
        Trunk list;
        Parser sipprrser;
        TransportLayer transport;
        TransactionLayer transection
        };
};

class Transaction
{
    void send( SipReques req){
       int index = transport->getLeastLoadedTrunk();
        trunk[i]->dispatch(req);
    }

    void  onNotify( char *message){
        
    }
    private:
        Callback *clb;
        Transport *transport;

};
int main()
{

}