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


ListNode* addTwoNumbers(ListNode* A, ListNode* B) {

    ListNode *aptr=A;
    ListNode *bptr=B;
    ListNode *aprev=A;
    ListNode *bprev=B;
    int carry=0;

    while(aptr!=NULL && bptr!=NULL)
    {
        int sum=(aptr->val)+(bptr->val)+carry;
        if(sum>=10)
        {
            carry=sum/10;
            sum=sum%10;
        }
        else
        {
            carry=0;
        }
        
        aptr->val=sum;
        aprev=aptr;
        bprev=bptr;
        aptr=aptr->next;
        bptr=bptr->next;
        //printList(aptr);
    }

    if(aptr==NULL && bptr==NULL)
    {
        if(carry)
        {
            ListNode *newnode=new ListNode(carry);
            aprev->next=newnode;
            newnode->next=NULL;
        }
        return A;
    }

    ListNode *longer_list=NULL;
    ListNode *longer_list_last_node=NULL;
    if(aptr!=NULL)
    {
        longer_list=aptr;
    }
    else if(bptr!=NULL)
    {
        longer_list=bptr;
        aprev->next=bptr;
    }

    while(longer_list!=NULL)
    {
        int sum=(longer_list->val)+carry;
        if(sum>=10)
        {
            carry=sum/10;
            sum=sum%10;
        }
        else
        {
            carry=0;
        }
        
        longer_list->val=sum;
        longer_list_last_node=longer_list;
        longer_list=longer_list->next;
    }

    if(carry)
        {
            ListNode *newnode=new ListNode(carry);
            longer_list_last_node->next=newnode;
            newnode->next=NULL;
        }

    
return A;


}







    int main()
  {
      struct ListNode* head = NULL;
      struct ListNode* head2=NULL;
    //   head->next=NULL;
      vector<int> A={2,4};
      vector<int> B={5,6,7};
          push_to_list(A,&head);
          push_to_list(B,&head2);
//      printList(head);


       ListNode *newHead=addTwoNumbers(head,head2);

       printList(newHead);
  }