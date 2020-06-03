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


void reverse(struct ListNode **head)
{
    ListNode *prev=NULL;
    ListNode *curr=*head;
    ListNode *nxt;
    while(curr!=NULL)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    *head=prev;
}

ListNode* reorderList(ListNode* A) {

    if(A==NULL || A->next==NULL)
        return A;

    ListNode *slow=A;
    ListNode *fast=A;
    struct ListNode *middle=NULL;
    ListNode *prev_slow;
    while(fast!=NULL && fast->next!=NULL)
    {
        prev_slow=slow;
        slow=slow->next;
        fast=fast->next->next;
    }

    if(fast!=NULL)
    {
        middle=slow;
        prev_slow=slow;
        slow=slow->next;
    }
    // printList(fast)
   // struct ListNode *secondhalf=slow;
    reverse(&slow);
    prev_slow->next=slow;

    //return A;
    ListNode *c1=A;
    ListNode *c2=slow;

    ListNode *n1;
    ListNode *n2;

    bool first=true;
    
    while(c2->next!=NULL)
    {
        if(first)
        {
            n1=c1->next;
            c1->next=c2;
            c1=n1;
            first=false;
        }
        else
        {
            n2=c2->next;
            c2->next=c1;
            c2=n2;
            first=true;
        }
        
    }

    n1=c1->next;
    c1->next=c2;
    c1=n1;
    first=false;


    if(middle)
    {
        c2->next=middle;
        middle->next=NULL;
    }
    
    
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
      vector<int> A={1};

          push_to_list(A,&head);
      
      printList(head);

      int B=7;

       ListNode *newHead=reorderList(head);

       printList(newHead);
  }