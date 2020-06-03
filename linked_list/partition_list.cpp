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


  ListNode* partition(ListNode* A, int B) {

      ListNode *fix=new ListNode(0);
      ListNode *st=fix;
      ListNode *en=fix;

      ListNode *curr=A;
      bool first1=true;
      bool first2=true;
      ListNode *fhead=NULL;
      while(curr!=NULL)
      {

          if(curr->val<B)
          {
              ListNode *newNode= new ListNode(curr->val);
              newNode->next=fix;
              if(st!=fix)
              {
                  st->next=newNode;
                  
              }
              st=newNode; 
              if(first1)
              {
                  fhead=newNode;
                  first1=false;
              }
          }
          else
          {
              ListNode *newNode= new ListNode(curr->val);
              en->next=newNode;
              en=newNode;
              if(first2)
              {
                  fix->next=newNode;
                  first2=false;
              }
          }

          curr=curr->next;
         // printList(fix);
          //break;
          
      }
      if(fhead==NULL)
      {
          fhead=fix->next;
          return fhead;
      }
      if(en==fix)
      {
          st->next=NULL;
          return fhead;
      }

      st->next=st->next->next;




      return fhead;

}



  int main()
  {
      struct ListNode* head = NULL;
    //   head->next=NULL;
     vector<int> A={486 ,239 ,75 , 441 , 622 , 652 , 923 , 252 , 837 , 711 , 278 , 644 , 680 , 394 , 772 , 507 , 369 , 127 , 995 , 388 , 641 , 514 , 920 , 569 , 552 , 258 , 902 , 191 , 667 , 12 , 60 , 650 , 672 , 340 , 38 , 545 , 547 , 702 , 959 , 500 , 327 , 921 , 748 , 214 , 752 , 589 , 164 , 126 , 226 , 691 , 51 , 975 , 512 , 146 , 109 , 101 , 836 , 418 , 141 , 949 , 687 , 938 , 773 , 867 , 717 , 882 , 30 , 413 , 4 , 218 , 87 , 77 , 657 , 575 , 63 , 27 , 355};
       // vector<int> A={486,12};
          push_to_list(A,&head);
      
      printList(head);

      int B=7;

       ListNode *newHead=partition(head,27);

       printList(newHead);
  }
