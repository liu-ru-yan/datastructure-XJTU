#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

struct nums{
    int f1,f2;
};
struct numss{
    int f1,f2,z;
};

int ch(string s,int index){
    int ans=0,p=0;
    //cout<<ans;
    if(index==1){
        //cout<<s[0]-48<<"?";
        return s[0]-48;
    }
    for(int i=index-1;i>=1;i--){
        //cout<<i;
        ans=ans+int(pow(10,p++))*int(s[i]-48);
        //cout<<ans;
    }
    if(s[0]=='-'){
        ans=-ans;
    }
    else{
        ans=ans+int(pow(10,p++))*int(s[0]-48);
    }
    //cout<<ans<<'!';
    return ans;
}
int ch2(string s,int index){
    int ans,p=0;
    for(int i=s.length()-1;i>index;i--){
        ans=ans+int(pow(10,p++))*int(s[i]-48);
    }
    //cout<<ans;
    return ans;
}
int gys(int a,int b){
    if(b>a){
        int ans=1;
        for(int i=1;i<=a;i++){
            if(a%i==0&&b%i==0){
                ans=i;
            }
        }
        return ans;
    }
    if(a>b){
        int ans=1;
        for(int i=1;i<=b;i++){
            if(a%i==0&&b%i==0){
                ans=i;
            }
        }
        return ans;
    }
    if(a==b){
        return a;
    }
}
int main(){
    int n;cin>>n;
    string s[10000];
    nums ss[10000];
    for(int i=0;i<n;i++){
        cin>>s[i];
        //cout<<s[i];
    }
    for(int i=0;i<n;i++){
        int index;
        for(int j=0;j<int(s[i].length());j++){
            if(s[i][j]=='/'){
                index=j;
                //cout<<j;
            }
        }
        ss[i].f1=ch(s[i],index);
        ss[i].f2=ch2(s[i],index);
    }
    numss ans;
    ans.f1=0;
    ans.f2=0;
    ans.z=0;
    for(int i=0;i<n;i++){
        //cout<<i;
        if(i==0){
            ans.f1=ss[i].f1;
            ans.f2=ss[i].f2;
            continue;
        }
        //cout<<"????";
        int GYS=gys(ans.f2,ss[i].f2);
        //cout<<GYS<<"!";
        int gg=ans.f2*ss[i].f2/GYS;
        int c1=gg/ans.f2,c2=gg/ss[i].f2;
        ans.f2=gg;
        ss[i].f1=c2*ss[i].f1;
        ss[i].f2=gg;
        ans.f1=c1*ans.f1;
        ans.f1=ans.f1+ss[i].f1;
        GYS=gys(ans.f1,ans.f2);
        ans.f1=ans.f1/GYS;
        ans.f2=ans.f2/GYS;
        //cout<<ans.f1<<' '<<ans.f2<<endl;
    }
    while(1){
        if(ans.f1>=ans.f2){
            ans.f1=ans.f1-ans.f2;
            ans.z++;
        }
        else{
            break;
        }
    }
    while(1){
        int temp=ans.f1;
        int flag=0;
        if(ans.f1<0){
            ans.f1=-ans.f1;
            flag=1;
        }
        if(ans.f1>=ans.f2){
            ans.f1=ans.f1-ans.f2;
            if(flag==0)
            ans.z++;
            if(flag==1)
            ans.z--;
        }
        else{
            break;
        }
        ans.f1=-ans.f1;

    }
    //cout<<ans.z<<" "<<ans.f1<<" "<<ans.f2;
    int flag_1=0;
    if(ans.z>0){
        cout<<ans.z<<" ";
        flag_1=1;
    }
    if(ans.z<0){
        cout<<ans.z<<" ";
        flag_1=1;
    }

    if(ans.f1!=0&&flag_1==1){
        cout<<ans.f1<<"/";
        cout<<ans.f2;
    }
    if(ans.f1!=0&&flag_1==0){
        cout<<ans.f1<<"/";
        cout<<ans.f2;
    }
    if(ans.f1==0&&flag_1==0){
        cout<<'0';
    }
    return 0;
}