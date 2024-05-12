#include<iostream>
using namespace std;

int main(){
    int k;cin>>k;
    int a[10000];
    if(k==0){
        int x=0;
        cout<<x<<" "<<x<<" "<<0;
        return 1;
    }
    int flag=1;
    for(int i=0;i<k;i++){
        cin>>a[i];
        if(a[i]>=0){
            flag=0;
        }
    }
    if(flag==1){
        int x=0;
        if(k==0){
            k=1;
        }
        //cout<<x<<" "<<x<<" "<<k-1;
        cout<<x<<" "<<a[0]<<" "<<a[k-1];
        return 1;
    }
    int rmax=-1,rp1=0,rp2=0;
    int max=-1,p1=0,p2=0;
    max=0;
    for(int i=0;i<k;i++){
        max=max+a[i];
        p2=i;
        if(rmax<max){
            rmax=max;
            rp1=p1;
            rp2=p2;
        }
        if(max<0){
            p1=i+1;
            p2=i+1;
            max=0;
        }
    }
    cout<<rmax<<" "<<rp1<<" "<<rp2;

}