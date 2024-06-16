#include<iostream>
using namespace std;

int main(){
    int n;cin>>n;
    int a[10000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;cin>>x;
    int index=-1;
    int left=0,right=n-1;
    int mid;
    while(1){
        mid=left+right;
        mid=mid/2;
        if(mid==left){
            break;
        }
        else{
            if(a[mid]==x){
                index=mid;
                break;
            }
            else{
                if(a[mid]>x){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
        }
    }
    cout<<index;



    return 0;
}