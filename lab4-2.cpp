#include<iostream>
#include<cstring>
using namespace std;

struct Student{
    string id;
    string name;
    double grade;

};
int main(){
    int n;cin>>n;
    Student s[1000];
    for(int i=0;i<n;i++){
        cin>>s[i].id>>s[i].name>>s[i].grade;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(s[i].grade<=s[j].grade){
                continue;
            }
            else{
                Student temp=s[i];
                for(int k=i;k>j;k--){
                    s[k]=s[k-1];
                }
                s[j]=temp;

            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<s[i].id<<' '<<s[i].name<<' '<<s[i].grade<<endl;
    }



    return 0;
}