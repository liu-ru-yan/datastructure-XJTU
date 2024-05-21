#include<iostream>
#include<cstring>
using namespace std;

struct node{
    int value;
    int valid;
    int left;
    int right;
    int father;
    int deep;
};
node f[10000];
int find_min(node f[],int n){
    int min,index=-1,flag=0;
    for(int i=0;i<n;i++){
        if(f[i].valid==0){
            continue;
        }
        else{
            if(flag==0){
                min=f[i].value;
                index=i;
                flag=1;
                continue;
            }
            if(min>f[i].value){
                min=f[i].value;
                index=i;
                continue;
            }
        }
    }
    return index;
}
void postv(node& root,int deep){
    if(deep==-1){
        return;
    }
    root.deep=deep;

    //cout<<root.value<<' '<<root.deep<<endl;
    if(root.left!=-1){
        postv(f[root.left],deep+1);
    }
    if(root.right!=-1){
        postv(f[root.right],deep+1);
    }

}
void wpl(node& root,int& w){
    if(root.left!=-1){
        wpl(f[root.left],w);
    }
    if(root.right!=-1){
        wpl(f[root.right],w);
    }
    if(root.left==-1){
        w=w+root.value*root.deep;
        return;
    }
    if(root.right==-1){
        w=w+root.value*root.deep;
        return;
    }
}
void show(node& root){
    cout<<root.value;
    if(root.left!=-1){
        cout<<"(";
        show(f[root.left]);
        cout<<",";
    }
    //cout<<",";
    if(root.right!=-1){
        show(f[root.right]);
        cout<<")";
    }

}
void last(node& root,string s){
    if(root.left!=-1){
        string sl=s+"0";
        last(f[root.left],sl);
    }
    if(root.right!=-1){
        string sr=s+"1";
        last(f[root.right],sr);
    }
    /*
    if(root.left==-1){
        cout<<s<<" ";
    }
    */
    if(root.right==-1){
        cout<<s<<" ";
    }
}
int main(){
    int root;
    int n;cin>>n;
    //node f[2*n];
    int point=n;
    for(int i=0;i<n;i++){
        cin>>f[i].value;
        f[i].valid=1;
        f[i].left=-1;
        f[i].right=-1;
        f[i].father=-1;
    }
    for(int i=0;i<n-1;i++){
        int index1=find_min(f,point);
        if(index1==-1){
            break;
        }
        f[index1].valid=0;
        int index2=find_min(f,point);
        if(index2==-1){
            break;
        }
        f[index2].valid=0;
        f[point].value=f[index1].value+f[index2].value;
        f[point].valid=1;
        if(f[index1].value<f[index2].value){
            f[point].left=index1;
            f[point].right=index2;
        }
        else{
            f[point].left=index2;
            f[point].right=index1;
        }
        f[index1].father=point;
        f[index2].father=point;
        root=point++;

    }
    postv(f[root],0);
    int w=0;
    wpl(f[root],w);
    cout<<w;
    cout<<endl;
    show(f[root]);
    cout<<endl;
    last(f[root],"");
    return 0;
}