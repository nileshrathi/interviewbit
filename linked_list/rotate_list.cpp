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


ListNode* rotateRight(ListNode* A, int B) {


    if(B==0 || A==NULL)
    {
        return A;
    }
    ListNode *st=A;
    ListNode *en=A;
    int count=0;
    while(en!=NULL && B--)
    {
        en=en->next;
    }

    if(en==NULL || B>0)
    {
        return rotateRight(A,B);
    }


    while(en->next!=NULL)
    {
        st=st->next;
        en=en->next;
    }

    en->next=A;
    A=st->next;
    st->next=NULL;
    
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
      vector<int> A={1,2,3,4,5,6};

          push_to_list(A,&head);
      
      printList(head);

      int B=7;

      ListNode *newHead=rotateRight(head,B);
      printList(newHead);
  }


  