#include<iostream>
#include<cstring>
#include<string>
using namespace std;


int main(){
    string s;
    getline(cin, s);
    int max=0,index=0,rmax=0;
    for(int i=0;i<s.length();i++){
        if(s[i]!=' '){
            max++;
        }
        else{
            if(max>rmax){
                index=i-max;
                rmax=max;
                max=0;
            }
            else{
                max=0;
            }
        }
    }
    if(max>rmax){
        index=s.length()-max;
        rmax=max;
        max=0;
    }
    for(int i=0;i<rmax;i++){
        cout<<s[index+i];
    }
    return 0;
}