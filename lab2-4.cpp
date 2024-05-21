#include <iostream>
#include <cmath>
using namespace std;
int gys(int a,int b) {
    if (b==0)
        return a;
    return gys(b,a%b);
}

int gbs(int a,int b) {
    return (a*b)/gys(a,b);
}

void hj(int& f1,int& f2) {
    int GYS=gys(abs(f1),abs(f2));
    f1/=GYS;
    f2/=GYS;
}

void mixedToImproper(int& whole,int& f1,int& f2) {
    f1 = whole*abs(f2) + f1;
    whole = 0;
}

void addFractions(int& f11,int& f21,int f12,int f22) {
    int t=gbs(f21,f22);
    f11=f11*(t/f21)+f12*(t/f22);
    f21=t;
}

int main() {
    int N;
    cin>>N;

    int sumf1=0;
    int sumf2=1;
    int sumWhole=0;

    for (int i=0; i<N;++i) {
        int f1,f2;
        char slash;
        cin>>f1>>slash>>f2;
        if (f2<0) {
            f1*=-1;
            f2*=-1;
        }

        hj(f1,f2);

        mixedToImproper(sumWhole,f1,f2);

        addFractions(sumf1,sumf2,f1,f2);

        hj(sumf1,sumf2);
    }

if (sumf1>=sumf2) 
    {
        int whole=sumf1/sumf2;
        sumf1%=sumf2;
        if(sumf1==0)
        {
            cout<<whole<<endl;
        }

        else
        {

            cout<<whole<<" "<<sumf1<<"/"<<sumf2<<endl;
        }

    } else if (sumWhole==0) {
        if (sumf1==0) {
            cout<<"0"<<endl;
        } else {
            cout<<sumf1<<"/"<<sumf2<<endl;
        }
    } else {
        cout<<sumWhole;
        if (sumf1!=0) {
            cout<<" "<<sumf1<<"/"<<sumf2<<endl;
        } else {
            cout<<endl;
        }
    }

    return 0;
}