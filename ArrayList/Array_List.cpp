#include <iostream>
#include <cstdlib>
using namespace std;

template <typename E>
class ALIST{
    int listSize;
    int maxSize;
    int curr;
    E* ArrayList;

    public: 
    ALIST(int size = 100){
        maxSize = size;
        listSize =0;
        curr = 0;
        ArrayList = new E[maxSize];

    }
    ~ALIST(){
        delete[] ArrayList;
    }

    void insert(const E& it){

        if (listSize >= maxSize)
        {
            return;
        }

        for (int i = listSize; i >curr; i--)
        {
            ArrayList[i] = ArrayList[i-1];
        }

        ArrayList[curr]=it;
        listSize++;
        
    }

    void append(const E& it){
        if (listSize>= maxSize)
        {
        return;
        }
        ArrayList[listSize]= it;
        listSize++;
        
    }

    E remove(){
        if (listSize<0||listSize<curr)
        {
            return -1;
        }
     int it = ArrayList[curr];
     for (int i = curr ; i < listSize; i++)
     {
        ArrayList[i] = ArrayList[i+1];
     }
     listSize++;
     return it;
    }

    void movetostart(){
        curr=0;
    }
    void movetoEnd(){
        curr = listSize;
    }
    void prev(){
        if (curr > 0 ){
        curr--;}
    }
    void next(){
        if (curr < listSize){
        curr++;}
    }
     int length() const { return listSize; }
    int currPos() const { return curr; }
   void moveToPos(int pos){
        if (pos >=0 && curr < listSize)
        {
            curr = pos;
        }
        
    }

    const E& getValue() const{
        if (curr >= 0 && curr < listSize){
            return ArrayList[curr];
        }
    }
};

int main (){
   ALIST<int> arr(10);
   
   int len = arr.length();
   cout<<"length before add:"<<len;
   arr.append(10);
   arr.append(20);
   arr.append(30);
   int len1 = arr.length();
   cout<<"length after add:"<<len1<<endl;

   arr.movetostart();
   arr.insert(5);
    for (arr.movetostart(); arr.currPos() < arr.length(); arr.next()) {
        cout << arr.getValue() << " "<<endl;
    }
   arr.movetoEnd();
   arr.insert(8);
 for (arr.movetostart(); arr.currPos() < arr.length(); arr.next()) {
        cout << arr.getValue() << " "<<endl;
    }
   //remove
   arr.movetostart();
   arr.remove();
 for (arr.movetostart(); arr.currPos() < arr.length(); arr.next()) {
        cout << arr.getValue() << " "<<endl;
    }

}