#include <iostream>

using namespace std;


class MyStack{

        int N = 100000;
        int* arr;
        int sz = 0;
        int tos = -1;

    public:
        MyStack()
        {
            this->arr = new int[N];
        }
        
        MyStack(int size_)
        {
            this->arr = new int[size_];
            this->N = size_;
        }

        int size(){
            return this->sz;
        }

        bool empty(){
            return this->sz == 0;
        }

        void push(int val){
            if(this->tos == N){
                return;
            }
            this->tos++;
            this->arr[tos] = val;
            this->sz++;
        }

        void pop(){
            if(this->tos == -1){
                return;
            }
            this->arr[tos] = 0;
            tos--;
            this->sz--;
        } 

        int top(){
            if(this->tos == -1){
                return -1;
            }
            return this->arr[tos];
        }
};


void solve(){

    MyStack* st = new MyStack();

    for(int i=1;i<=10;i++){
        st->push(i);
    }

    while(st->size() != 0){
        cout<<st->top()<<",";
        st->pop();
    }

}
int main(){

    solve();
    return 0;

}