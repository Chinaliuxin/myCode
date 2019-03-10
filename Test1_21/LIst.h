#pragma once
#include <iostream>
#include<assert.h>
#include<string>

typedef  int DataType;
struct Node
{
	struct Node* next;
	DataType  data;
};
typedef struct Node Node;
typedef struct Node*  PNode;


#if 1
void ListInit(PNode * phead)
{
	assert(phead);
	*phead = nullptr;

}
PNode CreateNewNode(DataType x)
{
	PNode newnode=(PNode)malloc(sizeof(Node));
	newnode->data = x;
	newnode->next = nullptr;
	return newnode;

}
void push_back(PNode* phead,DataType data)
{
	assert(phead);
	PNode newnode = CreateNewNode(data);
	PNode pcur = *phead;
	if (pcur == nullptr)
	{
		*phead = newnode;
		return;
	}

	while (pcur->next!=nullptr)
	{
		pcur = pcur->next;
	}
	pcur->next = newnode;
}
void pop_back(PNode* phead)
{
	assert(phead);
	if ((*phead) == nullptr)
	{
		return;
	}
	if ((*phead)->next == nullptr)
	{
		free(*phead);
		*phead = nullptr;
		return;
	}
	else
	{
		PNode pcur = *phead;
		while (pcur->next->next)
		{
			pcur = pcur->next;
		}
		free(pcur->next);
		pcur->next = nullptr;

	}
}
void push_front(PNode* phead, DataType data)
{
	assert(phead);
	PNode newnode = CreateNewNode(data);
	newnode->next = *phead;
	*phead = newnode;

}

void pop_front(PNode* phead)
{
	if (*phead == nullptr)
		return;
	else
	{
		PNode pcur = *phead;
		*phead = pcur->next;
		free(pcur);
		pcur = nullptr;
	}
}
void print(PNode phead)
{
	PNode pcur = phead;
	while (pcur)
	{
		std::cout << pcur->data << std::endl;
		pcur = pcur->next;
	}
}


PNode find(PNode phead,DataType x)
{
	if (phead == nullptr)
		return nullptr;

	else
	{
		while (phead != nullptr)
		{
			if (x == phead->data)
			{
				return phead;
			}
			phead = phead->next;
		}
	}
}

void Insert(PNode* phead, PNode position, DataType num)
{
	assert(phead && position && *phead);

		PNode newnode = CreateNewNode(num);
		newnode->next = position->next;
		position->next = newnode;
}

void erase(PNode* phead,PNode position )
{
	if (*phead == nullptr)
		return;
	if (position == *phead)
	{
		pop_front(phead);
	}
	else
	{
		PNode pcur = *phead;
		while (pcur->next!=position &&pcur)
		{
			pcur = pcur->next;
		}

		pcur->next = position->next;
		free(position);
	}
}
void destroy(PNode *phead)
{
	if (*phead = nullptr)
		return;
	PNode pcur=nullptr;
	while ((*phead)->next != nullptr)
	{
		pcur = *phead;
		*phead = pcur->next;
		free(pcur);
	}
}
//从小到大 快速排序
int quick_sort_part(int *a, int first, int last)
{
	int temp = a[last];
	while (first<last)
	{
		while (a[first] >= temp && first < last)
		{
			first++;
		}
		a[last] = a[first];
		while (a[last] <= temp && first < last)
		{
			last--;
		}
		a[first] = a[last];


	}

	a[last] = temp;
	return first;
}
void quick_sort(int *a,int first,int last)
{
	if (last>first)
	{
		int mid = quick_sort_part(a,first,last);
		quick_sort(a, first, mid-1);
		quick_sort(a , mid + 1, last);//尾递归，还是普通递归
	}

}

PNode ysf_creat(int n)
{
	PNode head = CreateNewNode(1);
	auto pcur = head;
	for (int i = 2; i <= n; i++)
	{
		PNode newnode = CreateNewNode(i);
		pcur->next = newnode;
		newnode->next = head;
		pcur = newnode;
	}
	return head;
}
void ysf_fun(PNode L, int m)
{

#if 0
		int i;
	Node *p=nullptr, *s=nullptr, *q=nullptr;
	p = L;
	printf("出列顺序为:");
	while (p->next != p)
	{
		for (i = 1; i < m; i++) /*从1开始*/
		{
			q = p;
			p = p->next;
		}
		printf("%5d", p->data);
		s = p;
		q->next = p->next;
		p = p->next; /*使p指向新的起点*/
		free(s);/*free()与malloc()函数配对使用，释放malloc函数申请的动态内存*/
	}
	printf("%5d\n", p->data);
#endif
#if 1
	PNode del = L;
	PNode delPre = nullptr;
	int outman;
	while (del->next != del)
	{

		for (int i = 1; i < m; ++i)
		{
		    delPre = del;
			del = del->next;
		}
		 outman = del->data;

		auto it_del = del;
		delPre->next = del->next;
		del = del->next;
		free(it_del);
	}
	std::cout << "胜者" << outman << std::endl;

#endif
}
void ysf_test()
{
	ysf_fun(ysf_creat(6),3);
}

#endif
int quicksortpart(int* a, int left, int right)
{
	int temp = a[right];
	while (right > left)
	{
		while (left < right && a[left] <temp)
		{
			left++;
		}
		a[right] = a[left];
		while (left<right && a[right]>=temp)
		{
			right--;
		}
		a[left] = a[right];
	}
	a[right] = temp;

	return right;
 }
void quick_sort2(int* a,int left,int right)
{
	if (right - left > 0)
	{
		int mid = quicksortpart(a, left, right);
		quick_sort2(a, left, mid - 1);
		quick_sort2(a, mid + 1, right);
	}
}


PNode ReverseList(PNode phead)
{
	assert(phead);
	PNode pPre = phead,pCur=pPre->next,pNext=pCur->next;
	while (pNext != nullptr)
	{
		pCur->next = pPre;
		pPre = pCur;
		pCur = pNext;
		pNext = pCur->next;
	}
	phead->next = nullptr;
	pCur->next = pPre;
	return pCur;
}
