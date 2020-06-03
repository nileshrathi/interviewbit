#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;



//  Definition for singly-linked list.
  struct ListNode {
      char val;
      ListNode *next;
      ListNode(char x) : val(x), next(NULL) {}
  };

  void reverse(struct ListNode **head)
  {
      struct ListNode *prev=NULL;
      struct ListNode *curr=*head;
      struct ListNode *next;
      while(curr!=NULL)
      {
          next=curr->next;
          curr->next=prev;
          prev=curr;
          curr=next;
      }
      *head=prev;
      
  }

  int comparelist(struct ListNode *head1, struct ListNode *head2)
  {
      while(head1!=NULL && head2!=NULL)
      {
          if(head1->val!=head2->val)
          {
              return 0;
          }
          head1=head1->next;
          head2=head2->next;
      }

      return 1;
  } 
 
int lPalin(ListNode* A) {

    struct ListNode *slowptr=A;
    struct ListNode *fastptr=A;
    struct ListNode *prevslowptr=A;
    struct ListNode *middleptr=NULL;

    if(A==NULL)
    {
        return 0;
    }
    
    while(fastptr!=NULL && fastptr->next!=NULL)
    {
        fastptr=fastptr->next->next;
        prevslowptr=slowptr;
        slowptr=slowptr->next;
    }

    if(fastptr!=NULL)
    {
        middleptr=slowptr;
        slowptr=slowptr->next;
    }

    struct ListNode *secondhalf=slowptr;

    prevslowptr->next=NULL;
    reverse(&secondhalf);

    int res=comparelist(A,secondhalf);

    return res;
    
}

void push(struct ListNode** head_ref, char new_data) 
{ 
    /* allocate node */
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode)); 
  
    /* put in the data  */
    new_node->val = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to pochar to the new node */
    (*head_ref) = new_node; 
} 

int main()
{
    /* Start with the empty list */
    struct ListNode* head = NULL; 
    char str[] = "abacaba"; 
    int i; 
  
    for (i = 0; str[i] != '\0'; i++) { 
        push(&head, str[i]); 
        // printList(head); 
        // isPalindrome(head) ? printf("Is Palindrome\n\n") : printf("Not Palindrome\n\n"); 
        
    } 
    cout<<lPalin(head);
  
    return 0; 
}