 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;
 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
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

void insert(ListNode **head,ListNode *target)
{
    if(*head==NULL)
    {
        *head=target;
        target->next=NULL;
        return ;
    }
    else if((*head)->val>=target->val)
    {
        target->next=*head;
        *head=target;
    }
    else
    {
        ListNode *curr=*head;
        ListNode *prev_curr=*head;

        while(curr!=NULL && curr->val<target->val)
        {
            prev_curr=curr;
            curr=curr->next;
        }
        prev_curr->next=target;
        target->next=curr;
    }
    
}



  ListNode* insertionSortList(ListNode* A) {

      ListNode *curr=A;
      ListNode *result=NULL;
      ListNode *next;
      while(curr!=NULL)
      {
          next=curr->next;

          insert(&result,curr);
          curr=next;
      }
      return result;
}



int main()
  {
      struct ListNode* head = NULL;
    //   head->next=NULL;
   //  vector<int> A={486 ,239 ,75 , 441 , 622 , 652 , 923 , 252 , 837 , 711 , 278 , 644 , 680 , 394 , 772 , 507 , 369 , 127 , 995 , 388 , 641 , 514 , 920 , 569 , 552 , 258 , 902 , 191 , 667 , 12 , 60 , 650 , 672 , 340 , 38 , 545 , 547 , 702 , 959 , 500 , 327 , 921 , 748 , 214 , 752 , 589 , 164 , 126 , 226 , 691 , 51 , 975 , 512 , 146 , 109 , 101 , 836 , 418 , 141 , 949 , 687 , 938 , 773 , 867 , 717 , 882 , 30 , 413 , 4 , 218 , 87 , 77 , 657 , 575 , 63 , 27 , 355};
        vector<int> A={5,4,2,1,3};
          push_to_list(A,&head);
      
      printList(head);

      int B=7;

       ListNode *newHead=insertionSortList(head);

       printList(newHead);
  }