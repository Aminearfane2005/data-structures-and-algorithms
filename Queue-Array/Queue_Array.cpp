#include <iostream>
using namespace std;

#define SIZE 10

class QueueArr
{
private:

    int front;
    int rear;
    int Arr[SIZE];

public:

    QueueArr(){
        front = -1;
        rear = -1;
    }


    bool isFull(){
        return rear == SIZE-1;
    }


    bool isEmpty(){
        return front == -1;
    }


    void enqueue(int elem){

        if(isFull())
        {
            cout<<"Queue is full\n";
            return;
        }

        if(front == -1)
            front = 0;

        Arr[++rear] = elem;
    }


    int dequeue(){

        if(isEmpty())
        {
            cout<<"Queue is empty\n";
            return -1;
        }

        int elem = Arr[front];

        if(front >= rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }

        return elem;
    }


    void display(){

        if(isEmpty())
        {
            cout<<"Queue is empty\n";
            return;
        }

        for(int i=front; i<=rear; i++)
        {
            cout<<Arr[i]<<" ";
        }

        cout<<endl;
    }
};


int main(){

    QueueArr q;

    q.enqueue(7);
    q.enqueue(7);
    q.enqueue(1);

    q.display();

    q.dequeue();

    q.display();

}