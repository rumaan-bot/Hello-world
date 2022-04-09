#include<stdio.h>
#include<string.h>
#define MAX_SIZE 6
void push(int[],int*,int);
int Pop(int[],int*);
void display(int[],int);
int palindrome(int[],int*,char[]);
int main()
{   int stack[MAX_SIZE],ele,top=-1,flag=-1,done=0,choice,deleted_item;
	char palstr[MAX_SIZE+1];
	while(!done)
	{
	   printf("\n1.push\n2.pop\n3.palindrome\n4.exit\n");
	   printf("enter the choice\n");
	   scanf("%d",&choice);
	   switch(choice)
	   {
		case 1:printf("enter the element to be pushed\n");
			scanf("%d",&ele);
			push(stack,&top,ele);
			display(stack,top);
			break;
		case 2:deleted_item=Pop(stack,&top);
			display(stack,top);
			break;
		case 3:printf("enter the string\n");
			scanf("%s",palstr);
			top=-1;
			flag=palindrome(stack,&top,palstr);
			if(flag==1)
				printf("%s is a palindrome\n",palstr);
			else
				printf("%s is not a palindrome\n",palstr);
			top=-1;
			break;
		case 4:done=1;
			break;
		default:printf("invalid choice\n");
	   }
	  }
       return 0;
}
void push(int stack[],int *top,int ele)
{
	if(*top==MAX_SIZE-1)
		{  printf("stack overflow\n");
		}
	else
		{
		    ++(*top);
		    stack[*top]=ele;
		 }
	return;
}
int Pop(int stack[],int*top)
{
	int temp;
	if(*top==-1)
	      {	printf("stack underflow\n");
	      }
	else
	{
		temp=stack[*top];
		(*top)--;
		printf("The poped element is %d\n",temp);
		return temp;
	}

}
void display(int stack[],int top)
{
	int i;
	if(top==-1)
		printf("stack is empty\n");
	else
	{
		printf("stack elements are\n");
		for(i=top;i>=0;i--)
		printf("%d\t",stack[i]);
	}
	return;
}
int palindrome(int stack[],int*top,char pal[])
{
	int i;
	for(i=0;i<strlen(pal);i++)
		push(stack,top,pal[i]);
	for(i=0;i<strlen(pal);i++)
	{
		if(pal[i]!=Pop(stack,top))
			return -1;
	}
	return 1;
}

