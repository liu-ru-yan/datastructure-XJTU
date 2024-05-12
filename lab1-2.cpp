#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int time_calcu(int prev,int temp){
    int ce=temp-prev;
    int t;
    if(ce>0){
        t=ce*6+5;
    }
    else{
        t=(-ce)*4+5;
    }
    return t;
}
int main(){
    int temp;
    queue<int> q;
    while(1){
        cin>>temp;
        
        if(temp==0){
            break;
        }
        else{
            q.push(temp);
            //cout<<temp;
        }
    }
    int flag_frist=1;
    int prev;
    int ans=0;
    while(q.empty()!=1){
        if(flag_frist==1){
            temp=q.front();
            //cout<<temp;
            q.pop();
            flag_frist=0;
            ans=ans+time_calcu(0,temp);
            //cout<<ans;
        }
        else{
            prev=temp;
            //cout<<temp;
            temp=q.front();
            //cout<<temp;

            q.pop();
            //cout<<prev<<endl;
            //cout<<temp<<endl;
            //cout<<time_calcu(prev,temp);
            ans=ans+time_calcu(prev,temp);
            //cout<<ans;
        }
    }
    cout<<ans;
    return 0;
}