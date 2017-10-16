#include<stdio.h>
#include<malloc.h>

struct node
{ int data;
  struct node *lc,*rc;
};

struct node* root=NULL;

void in()
{ struct node* temp,*p=root;
  temp=(struct node*)malloc(sizeof(struct node));
  printf("enter data\n");
  scanf("%d",&temp->data);
  temp->lc=NULL;
  temp->rc=NULL;

  if(root==NULL)
 { root=temp;
 }

  else
 {  struct node* curr=root;
    while(curr)
   {  p=curr;
    if(temp->data > curr->data)
      {
         curr=curr->rc;
      }
    else
        curr=curr->lc;
   }

  if(temp->data > p->data)
  {
    p->rc=temp;
  }

  else
  {
    p->lc=temp;
  }
 }

}

void in_or(struct node* root)
{
  if (root==NULL)
     return;
  else
 { in_or(root->lc);
   printf("%d\t",root->data);
  in_or(root->rc);
 }
}

void pre_or(struct node* root)
{
  if(root==NULL)
  return;
  else
 { printf("%d\t",root->data);
  pre_or(root->lc);
  pre_or(root->rc);
 }
}

void post_or(struct node* root)
{
  if(root==NULL)
    return;
  else
  { post_or(root->lc);
    post_or(root->rc);
    printf("%d\t",root->data);
  }
}


void main()
{ int ch;
  printf("1.insert\n 2.in order\n 3.pre order\n 4.post order \n 5.exit\n");
  do
   { printf("\nenter choice:\n");
     scanf("%d",&ch);
     switch(ch)
     {
       case 1: in();break;
       case 2: in_or(root);break;
       case 3: pre_or(root);break;
       case 4: post_or(root);break;
       case 5: printf("exit\n");
     }
   }
  while(ch!=5);

}
