#include<iostream>
#include<cstring>
using namespace std;

void print_space(int n){
    for(int i=0;i<n;i++){
        cout<<' ';
    }
}


int main(){
    string s;
    cin>>s;
    int t=int(s.length())/3;
    int r=int(s.length())-2*t;
    //cout<<t<<r;
    if(r<=t){
        r=r+2;
        t=t-1;
    }
    //cout<<t;
    int point1=0,point2=int(s.length()-1);
    for(int i=0;i<t;i++){
        cout<<s[point1++];
        print_space(r-2);
        cout<<s[point2--];
        cout<<endl;
    }
    for(int i=point1;i<=point2;i++){
        cout<<s[i];
    }




    return 0;
}