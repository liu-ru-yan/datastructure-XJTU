#include<iostream>
#include<map>
#include<set>
#include<utility>
#include<algorithm>

using namespace std;




int main(){
    int k;cin>>k;
    set<double> allset;
    map<double,double> inflect;


    for(int i=0;i<k;i++){
        //cout<<i<<endl;
        pair<double,double> p;//first is z
        cin>>p.first>>p.second;
        inflect.insert(p);
        allset.insert(p.first);
    }
    
    //cout<<inflect[1.2]<<inflect[1.3]<<endl;

    cin>>k;
    map<double,double> inflect2;
    for(int i=0;i<k;i++){
        pair<double,double> p;
        cin>>p.first>>p.second;
        inflect2.insert(p);
        auto it=allset.find(p.first);
        if(it==allset.end()){
            allset.insert(p.first);
        }
    }
    int ansk=0;
    map<double,double> result;
    for(auto iterator=allset.begin();iterator!=allset.end();iterator++){
        ansk++;
        pair<double,double> p;
        p.first=*iterator;
        p.second=0.0;
        auto it=inflect.find(*iterator);
        if(it!=inflect.end()){
            p.second+=inflect[*iterator];
        }
        auto ite=inflect2.find(*iterator);
        if(ite!=inflect2.end()){
            p.second+=inflect2[*iterator];
        }
        result.insert(p);

    }
    cout<<ansk;
    for(auto iterator=allset.rbegin();iterator!=allset.rend();iterator++){
        cout<<' '<<*iterator<<' '<<result[*iterator];
    }




    return 0;
}