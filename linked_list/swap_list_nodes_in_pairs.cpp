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



    ListNode* swapPairs(ListNode* A)
    {
        if(A==NULL || A->next==NULL)
            return A;

        //A-->B-->C-->D

        ListNode *dummy=new ListNode(0);
        dummy->next=A;
        ListNode *first;
        ListNode *second;
        ListNode *curr;

        curr=dummy;
        while(curr->next!=NULL && curr->next->next!=NULL)
        {
            first=curr->next;
            second=curr->next->next;
            first->next=second->next;
            second->next=first;
            curr->next=second;
            curr=curr->next->next;
            
        }
       
        return dummy->next;

    }





  

  int main()
  {
      struct ListNode* head = NULL;
    //   head->next=NULL;
      vector<int> A={1,2,3,4,5,6};

          push_to_list(A,&head);
      
      printList(head);

      int B=7;

       ListNode *newHead=swapPairs(head);

       printList(newHead);
  }