#include<iostream>
using namespace std;
struct Node{
    int val;
    Node* next;
};
int main()
{
    // Node* head=NULL;
    // Node* tail=NULL;
    // for(int i=1;i<=3;i++)
    // {
    //     Node* node=new Node;
    //     node->val=i;
    //     if(head==NULL)
    //     {
    //         head=node;
    //         node->next=NULL;
    //         tail=node;
    //     }
    //     else{
    //         tail->next=node;
    //         tail=node;
    //         node->next=NULL;
    //     }
    // }
    // for(Node* i=head;i!=NULL;i=i->next)
    // {
    //     cout<<(*i).val<<endl;
    // }
    // Node * temp=head;
    // while(temp!=NULL)
    // {
    //     cout<<temp->val<<" ";
    //     temp=temp->next;
    // }
    // Node* node=new Node;
    // node->val=10;
    // head=node;
    // node->next=NULL;
    // cout<<head->val;
    Node* head=new Node;
    Node* node=new Node;
    node->val=10;
    head->next=node;
    node->next=NULL;
    cout<<head->next->val;
}