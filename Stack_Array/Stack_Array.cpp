#include <iostream>
#include <cstdlib>
using namespace std;

#define Max  100
class StackArray
{

public:
     int top;
     int Arr[Max];
    // int pop();
  


    StackArray(){
        top = -1;
    }
 
    int push(int x){
        if (top >= Max-1)

        {
           return 0;
        }

        Arr[++top] = x;
        return 1;
    }

    int pop(){
        if ( top < 0)
        {
            return -1;
        }
       int x =  Arr[top--];
       return x;
        
    }
    int length() const {
        return top + 1;
    }

};


int main() {
    class StackArray s;
   int x1 = s.length();
    s.push(1);
     s.push(2);
      s.push(3);
     int x2 = s.length();
      s.pop();
 int x3 = s.length();

 cout<<x1<<" ,"<<x2<<" ,"<<x3;
}