#include<iostream>
using namespace std;

class Queue{
public:
    int a[10000];
    int front=0;
    int rear=0;
    void push(int c){
        a[front++]=c;
    }
    int first(){
        return a[rear];
    }
    void pop(){
        rear++;
    }
    void show(){
        int flag=0;
        for(int i=rear;i<front;i++){
            if(flag==0){
                cout<<a[i];
                flag++;
            }
            else{
                cout<<' '<<a[i];
            }

        }
    }
};
int main(){
    int n;cin>>n;
    Queue queue;
    for(int i=0;i<n;i++){
        int t;cin>>t;
        queue.push(t);
    }
    //queue.show();
    //cout<<endl;
    queue.pop();
    queue.pop();
    queue.push(11);
    queue.push(12);
    queue.show();
    cout<<endl;
    return 0;
}