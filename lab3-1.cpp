#include<iostream>
#include<cstring>
#include <sstream>

using namespace std;
class node{
public:
    char c;
    node* next;
};
void show(node* head){
    node* temp=head->next;
    int cnt=0;
    while(temp!=NULL){
        cout<<temp->c;
        temp=temp->next;
        cnt++;
    }
    cout<<endl;
    cout<<cnt;
    cout<<endl;
}
void ed(node* head,char p){
    node* temp=head->next;
    node* t=head;
    while(temp!=NULL){
        if(temp->c==p){
            t->next=temp->next;
            temp=temp->next;
            continue;
        }
        temp=temp->next;
        t=t->next;
    }
}
int main(){
    string s;
    getline(cin,s);
    node* head;
    head=new node();
    head->next=NULL;
    node* temp=head;
    //cout<<s.length();
    for(int i=0;i<int(s.length());i++){
        node* a=new node();
        a->c=s[i];
        a->next=NULL;
        temp->next=a;
        temp=temp->next;
    }
    show(head);
    char d;cin>>d;
    ed(head,d);
    show(head);
    return 0;
}