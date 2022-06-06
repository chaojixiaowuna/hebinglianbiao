//#include<stdio.h>
//#include<stdlib.h>
// struct ListNode 
// {
//      int val;
//     struct ListNode *next;
// };
// 
//void ListPrint(struct ListNode* head)
//{
//	struct ListNode* cur=head;
//	while(cur)
//	{
//		printf("%d",cur->val);
//		cur=cur->next;
//	}
//}
//
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//	struct ListNode* head1=list1,*head2=list2;
//	struct ListNode* tail=NULL;
//	struct ListNode* head=NULL;
//	 if(list1==NULL)
//    return list2;
//    if(list2==NULL)
//    return list1;
//	while(head1&&head2)
//	{
//		if(head1->val<head2->val)
//		{
//			if(head==NULL)
//			{
//			tail=head=head1;
//			}
//			else
//			{
//				tail->next=head1;
//				tail=head1;
//			}
//			head1=head1->next;
//		}
//
//		else
//		{
//			if(head==NULL)
//			{
//				tail=head=head2;
//			}
//			else
//			{
//				tail->next=head2;
//				tail=head2;
//			}
//			head2=head2->next;
//		}
//	}
//		if(head1==NULL)
//		{
//		tail->next=head2;
//		}
//		else 
//			{
//				tail->next=head1;
//		}
//		return head;
//	
//}
//int main()
//{
//	struct ListNode* n1=(struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n2=(struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n3=(struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n4=(struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n5=(struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n6=(struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* tmp;
//	n1->val=1;
//	n2->val=2;
//	n3->val=3;
//	n4->val=4;
//	n5->val=5;
//	n6->val=6;
//	n1->next=n2;
//	n2->next=n3;
//	n3->next=NULL;
//	n4->next=n5;
//	n5->next=n6;
//	n6->next=NULL;
//	tmp=mergeTwoLists(n1,n4);
//	ListPrint(tmp);
//	return 0;
//}


//先在头部位置放一个节点 再循环
//#include<stdio.h>
//#include<stdlib.h>
// struct ListNode 
// {
//      int val;
//     struct ListNode *next;
// };
// 
//void ListPrint(struct ListNode* head)
//{
//	struct ListNode* cur=head;
//	while(cur)
//	{
//		printf("%d",cur->val);
//		cur=cur->next;
//	}
//}
//
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//	struct ListNode* head1=list1,*head2=list2;
//	struct ListNode* tail=NULL;
//	struct ListNode* head=NULL;
//	 if(list1==NULL)
//    return list2;
//    if(list2==NULL)
//    return list1;
//	if(head1->val<head2->val)
//	{
//		head=tail=head1;
//		head1=head1->next;
//	}
//	else
//	{
//		head=tail=head2;
//		head2=head2->next;
//		}
//	while(head1&&head2)
//	{
//		if(head1->val<head2->val)
//		{
//			tail->next=head1;
//			tail=head1;
//			head1=head1->next;
//		}
//
//		else
//		{
//			tail->next=head2;
//			tail=head2;
//			head2=head2->next;
//		}
//	}
//		if(head1==NULL)
//		{
//		tail->next=head2;
//		}
//		else 
//		{
//		tail->next=head1;
//		}
//		return head;
//	
//}
//int main()
//{
//	struct ListNode* n1=(struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n2=(struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n3=(struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n4=(struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n5=(struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n6=(struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* tmp;
//	n1->val=1;
//	n2->val=2;
//	n3->val=3;
//	n4->val=4;
//	n5->val=5;
//	n6->val=6;
//	n1->next=n2;
//	n2->next=n3;
//	n3->next=NULL;
//	n4->next=n5;
//	n5->next=n6;
//	n6->next=NULL;
//	tmp=mergeTwoLists(n1,n4);
//	ListPrint(tmp);
//	return 0;
//}



//设置一个哨兵位 作为头
#include<stdio.h>
#include<stdlib.h>
 struct ListNode 
 {
      int val;
     struct ListNode *next;
 };
 
void ListPrint(struct ListNode* head)
{
	struct ListNode* cur=head;
	while(cur)
	{
		printf("%d",cur->val);
		cur=cur->next;
	}
}
void ListDestroy(struct ListNode** tmp)
{
	struct ListNode* cur=*tmp;
	while(cur)
	{
		*tmp=(*tmp)->next;
		free(cur);
		cur=(*tmp);
	}
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
	struct ListNode* head1=list1,*head2=list2;
	struct ListNode* tail=NULL;
	struct ListNode* head=NULL;
	struct ListNode* list;
	 if(list1==NULL)
    return list2;
    if(list2==NULL)
    return list1;
	head=tail=(struct ListNode*)malloc(sizeof(struct ListNode));
	while(head1&&head2)
	{
		if(head1->val<head2->val)
		{
			tail->next=head1;
			tail=head1;
			head1=head1->next;
		}

		else
		{
			tail->next=head2;
			tail=head2;
			head2=head2->next;
		}
	}
		if(head1==NULL)
		{
		tail->next=head2;
		}
		else 
		{
		tail->next=head1;
		}
		list=head->next;
		free(head);
		return list;
	
}
int main()
{
	struct ListNode* n1=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n3=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n4=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n5=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n6=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* tmp;
	n1->val=1;
	n2->val=2;
	n3->val=3;
	n4->val=4;
	n5->val=5;
	n6->val=6;
	n1->next=n2;
	n2->next=n3;
	n3->next=NULL;
	n4->next=n5;
	n5->next=n6;
	n6->next=NULL;
	tmp=mergeTwoLists(n1,n4);
	ListPrint(tmp);
	ListDestroy(&tmp);
	return 0;
}