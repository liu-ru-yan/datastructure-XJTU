#include<iostream>
using namespace std;

struct soldier{
    int index;
    int valid;
};

int nums(soldier s[],int n){
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i].valid==1){
            cnt++;
        }
    }
    return cnt;
}

void remove2(soldier s[],int n){
    int in=0;
    for(int i=0;i<n;i++){
        if(s[i].valid==1){
            in++;
        }
        if(in==2){
            in=0;
            s[i].valid=0;
        }
    }
}
void remove3(soldier s[],int n){
    int in=0;
    for(int i=0;i<n;i++){
        if(s[i].valid==1){
            in++;
        }
        if(in==3){
            in=0;
            s[i].valid=0;
        }
    }
}
int main(){
    int n;
    cin>>n;
    soldier s[10000];
    int p=1;
    for(int i=0;i<n;i++){
        s[i].index=p++;
        s[i].valid=1;
    }
    int flag=2;
    while(nums(s,n)>3){
        if(flag==2){
            remove2(s,n);
            flag=3;
        }
        else{

            remove3(s,n);
            flag=2;
        }
    }
    int f=0;
    for(int i=0;i<n;i++){
        if(s[i].valid==1){
            if(f==0){
               cout<<s[i].index;
               f++;
               continue; 
            }
            cout<<' '<<s[i].index;
        }

    }
    return 0;
}