#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct LINKED_STACK_NODE_s *LINKED_STACK_NODE;
typedef struct LINKED_STACK_NODE_s{
	LINKED_STACK_NODE next;
	void *data;
} LINKED_STACK_NODE_t[1];

typedef struct LINKED_STACK_s{
  	LINKED_STACK_NODE head;
} LINKED_STACK_t[1], *LINKED_STACK;

void *linked_stack_pop(LINKED_STACK stack)
{
	void *res;
	LINKED_STACK_NODE sub;
	if(stack->head!=NULL)
	{
		sub=stack->head;
		res=sub->data;
		stack->head=sub->next;
		free(sub);
	}
	return res;
}

void linked_stack_push(LINKED_STACK stack, void *data)
{
	LINKED_STACK_NODE add_node=(LINKED_STACK_NODE)malloc(sizeof(LINKED_STACK_NODE_t));
	if(add_node==NULL)
	{
		printf("stackoverflow");
	}
	else
	{
		add_node->data=data;
		add_node->next=stack->head;
		stack->head=add_node;
	}
}
int linked_stack_is_emtpy(LINKED_STACK stack)
{
	void *data=linked_stack_pop(stack);
	return data==NULL ? 1 : 0;
	
}

LINKED_STACK linked_stack_init()
{
	LINKED_STACK node;
	node=(LINKED_STACK)malloc(sizeof(LINKED_STACK_t));
	if(node!=NULL)
	{
		node->head=NULL;
	}
	else
	{
		printf("error linked stack init");
	}
	return node;
}

void linked_stack_free(LINKED_STACK stack)
{
	while(stack->head!=NULL)
	{
		linked_stack_pop(stack);
	}
}

void reverse(char *str, char *rev_str)
{

	int a,i,idx;
	char *p;
	LINKED_STACK node;
	node=linked_stack_init();
	a=linked_stack_is_emtpy(node);
	for(i=0;i<strlen(str);i++)
	{
		p=&str[i];
		linked_stack_push(node,p);
	}

	for(i=0;i<strlen(str);i++)
	{
		p=linked_stack_pop(node);
		rev_str[i]=*p;
	}
	free(p);
	linked_stack_free(node);
}

void isPalindrome(char *str,char *rev_str)
{
	int i,size;
	if(strcmp(str,rev_str)==0)
	{
		printf("Reverse of the word is %s and word is Palindrome\n",rev_str);
	}
	else
	{
		printf("Reverse of the word is %s and word is not Palindrome\n",rev_str);
	}
}


int main() 
{
	int a,i,size;
	char *word,*rWord;
	
	word=(char*)malloc(20*sizeof(char));
	rWord=(char *)malloc(20*sizeof(char));
	
	printf("enter word\n");
	scanf("%s",word);
	reverse(word,rWord);
	isPalindrome(word,rWord);
	
	free(word);
	free(rWord);
	
	return 0;
}
