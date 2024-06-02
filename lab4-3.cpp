#include<iostream>
using namespace std;


int a[1000],b[1000],c[1000];

void MergeSort(int a[],int left,int right){
    if(left==right){
        return;
    }
    else{
        int mid=(left+right)/2;
        MergeSort(a,left,mid);
        MergeSort(a,mid+1,right);
        for(int i=left;i<=mid;i++){
            b[i]=a[i];
        }
        for(int i=mid+1;i<=right;i++){
            c[i]=a[i];
        }
        int p1=left,p2=mid+1,p=left;
        while(1){
            if(p1>mid&&p2>right){
                break;
            }
            if(p1>=left&&p1<=mid&&p2>=mid+1&&p2<=right){
                if(b[p1]<c[p2]){
                    a[p++]=b[p1++];
                }
                else{
                    a[p++]=c[p2++];
                }
                continue;
            }
            if(p1>=left&&p1<=mid&&p2>right){
                a[p++]=b[p1++];
                continue;
            }
            if(p1>mid&&p2>=mid+1&&p2<=right){
                a[p++]=c[p2++];
                continue;
            }
            if(p2>right&&p1>mid){
                break;
            }
            
        }
    }
}
void adjustHeap(int a[],int n,int i){
    int parent=i;
    int left=2*i+1;
    int right=2*i+2;


    if(left<n&&a[left]<a[parent]){
        parent=left;
    }
    if(right<n&&a[right]<a[parent]){
        parent=right;
    }

    if(parent!=i){
        int temp=a[i];
        a[i]=a[parent];
        a[parent]=temp;
        adjustHeap(a,n,parent);
    }


}
void HeapSort(int a[],int n){
    for(int i=n/2-1;i>=0;i--){
        adjustHeap(a,n,i);
    }

    for(int i=n-1;i>0;i--){
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        adjustHeap(a,i,0);
    }

}
int main(){
    int n;cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    MergeSort(a,0,n-1);
    for(int i=0;i<n;i++){
        if(i==0){
            cout<<a[i];
        }
        else{
            cout<<' '<<a[i];
        }
    }
    cout<<endl;
    HeapSort(a,n);
    for(int i=0;i<n;i++){
        if(i==0){
            cout<<a[i];
        }
        else{
            cout<<' '<<a[i];
        }
    }
    return 0;
}