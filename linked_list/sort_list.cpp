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

 ListNode* merge(ListNode *A, ListNode *B)
 {
     ListNode *res=NULL;
    if(A==NULL)
        return B;
    if(B==NULL)
        return A;
    
    if(A->val<=B->val)
    {
        res=A;
        res->next=merge(A->next,B);
    }
    else
    {
        res=B;
        res->next=merge(A,B->next);
    }
    return res;
    

 }
  ListNode* sortList(ListNode* A) {

      //printList(A);
      if(A==NULL || A->next==NULL)
        return A;
    
     ListNode *first_half=NULL;
     ListNode *second_half=NULL;

     ListNode *slow=A;
     ListNode *fast=A;
     ListNode *prev_slow=NULL;
     while(fast!=NULL && fast->next!=NULL)
     {
        prev_slow=slow;
        fast=fast->next->next;
        slow=slow->next;
     }
     
     if(prev_slow)
        prev_slow->next=NULL;
    


     first_half=A;
     second_half=slow;

     first_half=sortList(first_half);
     second_half=sortList(second_half);

     ListNode *mergeList=merge(first_half,second_half);


      return mergeList;
    return NULL;
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

       ListNode *newHead=sortList(head);

       printList(newHead);
  }