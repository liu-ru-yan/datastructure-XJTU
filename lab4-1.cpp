#include<iostream>
using namespace std;

void BubbleSort(int a[],int n){
    for(int i=0;i<9;i++){
        for(int j=i+1;j<10;j++){
            if(a[j]<a[i]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    for(int i=0;i<10;i++){
        if(i==0){
            cout<<a[i];
        }
        else{
            cout<<' '<<a[i];
        }
    }
}
void SelectionSort(int a[],int n){
    for(int i=0;i<10;i++){
        int max;
        int index;
        for(int j=i;j<10;j++){
            if(j==i){
                max=a[i];
                index=j;
            }
            else{
                if(a[j]>max){
                    max=a[j];
                    index=j;
                }
            }
        }
        a[index]=a[i];
        a[i]=max;
    }
    for(int i=0;i<10;i++){
        if(i==0){
            cout<<a[i];
        }
        else{
            cout<<' '<<a[i];
        }
    }
}

int main(){
    int a[10];
    for(int i=0;i<10;i++){
        cin>>a[i];
    }
    //cout<<"!";
    BubbleSort(a,10);
    cout<<endl;
    SelectionSort(a,10);


    return 0;
}