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

  void printList(struct ListNode *head)
  {
      while(head!=NULL)
      {
          cout<<head->val<<" ";
          head=head->next;
      }
      cout<<"\n";
  }


  void reversetill(ListNode **head, ListNode *tail)
  {
      ListNode *curr=*head;
      ListNode *prev=tail;
      ListNode *next;
      while(curr!=tail)
      {
          next=curr->next;
          curr->next=prev;
          prev=curr;
          curr=next;
      }
      *head=prev;

  }

  ListNode* reverseList(ListNode* A, int B) {

    ListNode *curr=A;
    ListNode *prev=NULL;
    ListNode *next;
    int count=0;
    while(curr!=NULL && count<B)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }

    if(next!=NULL)
    {   
        A->next=reverseList(next,B);
    }

    A=prev;
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

  

  int main()
  {
      struct ListNode* head = NULL;
    //   head->next=NULL;
      vector<int> A={1,2,3,4,5,6};

          push_to_list(A,&head);
      
      printList(head);

      int B=7;

       ListNode *newHead=reverseList(head,2);

       printList(newHead);
  }