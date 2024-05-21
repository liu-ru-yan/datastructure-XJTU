#include<iostream>
#include<string>
using namespace std;

class Stack{
public:
    char a[10000];
    int point=0;
    void push(char c){
        a[point++]=c;
    }
    void pop(){
        point--;
    }
    char top(){
        return a[point-1];
    }
    int isempty(){
        if(point==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    void show(){
        cout<<"*****";
        for(int i=point-1;i>=0;i--){
            cout<<a[i];
        }
        cout<<endl;
    }
};

int main(){
    int f=0;
    string s;
    cin>>s;
    Stack stack;
    for(int i=0;i<int(s.length());i++){
        if(i==0){
            stack.push(s[i]);
            //stack.show();
            continue;
        }
        else{
            if(s[i]!=')'){
                stack.push(s[i]);
                //stack.show();
                continue;
            }
            else{
                int flag=0;

                while(1){
                    if(flag==1){
                        break;
                    }
                    if(stack.isempty()==1){
                        f=1;
                        break;
                    }
                    char top=stack.top();
                    if(top=='('){
                        if(stack.isempty()==0){
                            stack.pop();
                            //stack.show();
                            flag=1;
                            break;
                        }
                        else{
                            f=1;
                            break;
                        }
                    }
                    else{
                        if(stack.isempty()==0){
                            stack.pop();
                           // stack.show();
                            continue;
                        }
                        else{
                            f=1;
                            break;
                        }
                    }
                }
                //cout<<"sds";
                //cout<<f;
                if(f==1){
                    break;
                }
                continue;
                

            }
        }
    }
    //cout<<stack.top();
    while(1){
        if(stack.top()!='('&&stack.top()!=')'&&stack.isempty()==0){
            stack.pop();
        }
        else{
            break;
        }
    }
    //stack.show();
    if(stack.isempty()==0){
        f=1;
    }
    if(f==1){
        cout<<"括号不匹配！";
        //cout<<"!";
    }
    else{
        cout<<"括号匹配！";
        //cout<<"?";
    }


    return 0;
}