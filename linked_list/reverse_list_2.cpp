 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;
 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(char x) : val(x), next(NULL) {}
  };


ListNode* reverseBetween(ListNode* A, int B, int C) {


    ListNode *dummy=new ListNode(-1);
    dummy->next=A;
    ListNode *bst=dummy;
    ListNode *st=A;
    ListNode *aen=A;
    ListNode *en=A;


    while(B>1)
    {
        bst=st;
        st=st->next;
        B--;
    }

    while(C>1)
    {
        en=en->next;
        C--;
    }
    aen=en->next;


    ListNode *prev=bst;
    ListNode *curr=st;
    ListNode *nxt;
    while(curr!=en)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
   curr->next=prev;
    bst->next=en;
    st->next=aen;
   // st->next=en->next;

    if(bst==dummy)
        return en;
    
    return A;


}

















  void push_to_list(vector<int> A, struct ListNode **head)
  {

      struct ListNode *curr=*head;
      struct ListNode *prev=*head;

      for(int i=A.size()-1;i>=0;i--)
      {
          struct ListNode *newNode= new ListNode(A[i]);
          newNode->next=(*head);
          (*head)=newNode;
      }
      

  }

  void printList(struct ListNode *head)
  {
      while(head!=NULL)
      {
          cout<<head->val<<" ";
          head=head->next;
      }
      cout<<"\n";
  }

  int main()
  {
      struct ListNode* head = NULL;
    //   head->next=NULL;
      vector<int> A={1,2,3,4};

          push_to_list(A,&head);
      
      printList(head);

      int B=7;

       ListNode *newHead=reverseBetween(head,1,2);

       printList(newHead);
  }