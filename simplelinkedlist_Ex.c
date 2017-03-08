/**Single linked list Using C **/

#include<stdio.h>
struct node
{
	int member;
	struct  node *pnxt;
};

static struct node *head;
static struct node *tail;

int addnodefront(int element)
{
	
	printf("Inside addnodefront function\n");
	struct node *pn;
	pn = malloc(sizeof(*pn));
	pn->member=element;
	if(head==NULL)
	{
	    head=pn;
	    tail=pn;
	    pn->pnxt=NULL;
	    
	}
	else
	{
	pn->pnxt=head;
	head=pn;
	
	}
		
	
}

int addnodeback(int element)
{
	printf("Inside addnodefront function\n");
	struct node *pn;
	pn = malloc(sizeof(*pn));
	pn->member=element;
	if(head==NULL)
	{
	    head=pn;
	    tail=pn;
	    pn->pnxt=NULL;
	    
	}
	
	else
	{
		tail->pnxt=pn;
		pn->pnxt=NULL;
		tail=pn;
	}
}

int deletenode(int value)
{
	printf("delete node containing value=%d\n",value);
	struct node *ptmp, *pdel;
	
	if (head==NULL)
	return;
	if(head->member == value)
	{
		pdel=head;
		head=head->pnxt;
		free(pdel);
		return 0;
	}
	
	ptmp=head;
	while(ptmp->pnxt)
	{
		if(ptmp->pnxt->member == value)
		{
			pdel=ptmp->pnxt;
			ptmp->pnxt= ptmp->pnxt->pnxt;
			free(pdel);
			return 0;
		}
		ptmp=ptmp->pnxt;
	}
	
	
	
	
}

int displaynodes()
{
	printf("display nodes function\n");
	struct node *tmp;
	tmp=head;
	while(tmp)
	{
		printf("Display Nodes =%d\n",tmp->member);
		tmp=tmp->pnxt;
	}
}

int main()
{
	int input;
	int value;
	printf("Welcome to linked list program:\n");
	while(1)
	{
		printf("1.addnodefront 2.addnodeback  3.deletenode 4.displaynodes 5.exit \n");
	scanf("%d",&input);
	
	switch(input)
	{
		case 1:
			printf("add nodefrnont: enter element:\n");
			scanf("%d",&value);
			addnodefront(value);
			
			break;
		case 2:
			printf("add node back,Enter Element:\n");
			printf("add nodefrnont: enter element:\n");
			scanf("%d",&value);
			addnodeback(value);
			break;
		case 3:
			printf("delete node\n");
			/*We can write multiple deletenode funcction based on argument like member match,which node you can delete */
			deletenode(44);
			break;
		case 4:
			printf("displaynodes\n");
			displaynodes();
			
			break;
		case 5:
			printf("exit");
			return 0;
	
	
	}

}
	
}
