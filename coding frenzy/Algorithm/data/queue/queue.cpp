#include<iostream>
using namespace std;
class Queue{
    private:
        int max_size;
        int *p;
        int front =0;
        int end=0;
    public:
        Queue(int size){
            this->max_size=size;
            p= new int [max_size];
        }
        int size(){
            return end-front;
        }
        bool empty(){
            return this->size()==0? 1:0;
        }
        bool full(){
            return !(end-front==max_size-1);
        }
        bool push(int i){
            if(full()){
                
            }
        }

};
int main(){
    Queue q(10);
    for(int i=0;i<5;i++)
        q.push(i);
    cout<<q.size();
    cout<<q.empty();
    for(int i=0;i<5;i++){
        cout<<q.front();
        q.pop();
    } 
    cout<<q.size();
    cout<<q.empty();
}