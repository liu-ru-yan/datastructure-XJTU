#include<iostream>
#include<math.h>
#include<tuple>
using namespace std;


int temp[10000];
int invert(int x){
    int flag=0;
    if(x<0){
        x=-x;
        flag=1;
    }
    int i=0;
	while(1){
		if(int(pow(10,i))<=x){
			i++;
		}
		else{
			break;
		}
	}
	i--;
    int point=0;
	for(int j=i;j>=0;j--){
		//cout<<x/int(pow(10,j))<<endl;
        temp[point++]=x/int(pow(10,j));
		x=x-x/int(pow(10,j))*int(pow(10,j));
	}
    int flagf=1;
    int index=-1;
    for(int j=point-1;j>=0;j--){
        if(flagf==1&&temp[j]==0){
            continue;
        }
        if(flagf==1&&temp[j]!=0){
            flagf=0;
            index=j;
        }
    }
    int ans=0;
    while(1){
        if(index!=-1){
        ans=ans+int(pow(10,index))*temp[index--];
        }
        else{
            break;
        }
    }
    
    //cout<<ans;
    if(flag==1){
        ans=-ans;
    }
    return ans;

}
int main(){

    int x,y;
    cin>>x>>y;
    int a,b;
    a=(x+y)/2;
    b=(x-y)/2;
    a=invert(a);
    b=invert(b);
    cout<<a+b<<' '<<a-b;
    return 0;
}