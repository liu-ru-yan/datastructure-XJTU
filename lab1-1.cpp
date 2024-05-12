#include<iostream>
#include<cstring>
using namespace std;


int main(){
    string s;cin>>s;
    int r=s.size()%3;
    int point=0;
    int flag_3=1;
    if(r==1){
        cout<<s[point++];
        flag_3=0;
    }
    if(r==2){
        cout<<s[point++];
        cout<<s[point++];

        flag_3=0;
    }
    int flag=0;
    for(int i=point;i<s.size();i=i+3){
        if(flag_3==0||flag==1){
            cout<<",";
        }
        if(flag_3==1&&flag==0){
            flag=1;
        }
        cout<<s[i]<<s[i+1]<<s[i+2];
    }
    return 0;
}