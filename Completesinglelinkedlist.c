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

/*** Add a node after a given node ***/



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


/***Iterative method ***/
length_list()
{
	
	struct node *tmp;
	int count=0;
	tmp=head;
	while(tmp)
	{
		count++;
		tmp=tmp->pnxt;
	}
	
	printf("Length of Linked list(Iterative method) =%d\n",count);
	
}

int length_list_recursive(struct node *head)
{
	if(head == NULL)
	return 0;
	return 1 + length_list_recursive(head->pnxt);
}


/* Function to swap nodes x and y in linked list by
   changing links */
void swapNodes(struct node *head_ref, int x, int y)
{
	if(x==y)
	return 0;
	
	struct node *curx=head_ref,*cury,*prex=NULL,*prey,*tmp;
	
	while(curx->member != x)
	{
		prex=curx;
		curx=curx->pnxt;
	}
	
	while(cury->member != y)
	{
		prey=cury;
		cury=cury->pnxt;
	}
	
	tmp=cury->pnxt;
	cury->pnxt = curx->pnxt;
	curx->pnxt= tmp;
	 
}

/***Get nth element from start ***/
int GetNth(struct node* head, int index)
{
	struct node *tmp;
	tmp = head;
	int count=0;
	
	while(tmp != NULL)
	{
		if(count == index)
		return (tmp->member);
		count++;
		tmp=tmp->pnxt;
	}
	
}

/***Get nth element from end ***/
/*Need to implement

void printNthFromLast(struct node *head, int n)
{
  struct node *main_ptr = head;
  struct node *ref_ptr = head;
 
  int count = 0;
  if(head != NULL)
  {
     while( count < n )
     {
        if(ref_ptr == NULL)
        {
           printf("%d is greater than the no. of "
                    "nodes in list", n);
           return;
        }
        ref_ptr = ref_ptr->next;
        count++;
     } // End of while
 
     while(ref_ptr != NULL)
     {
        main_ptr = main_ptr->next;
        ref_ptr  = ref_ptr->next;
     }
     printf("Node no. %d from last is %d ", 
              n, main_ptr->data);
  }
}
*/

/*** Find the middle node of a linked list & print memeber ****/
void midnode(struct node* head)
{
	struct node* slow_ptr = head;
	struct node* fast_ptr = head;
	
	
	if(head != NULL)
	{
		while(fast_ptr != NULL && fast_ptr->pnxt !=NULL)
		{
			slow_ptr = slow_ptr->pnxt;
			fast_ptr = fast_ptr->pnxt->pnxt;
		}
		printf("Middle Node =%d\n",slow_ptr->member);
	}

	
}

/*** Function to reverse the linked list ***/
static void reverse(struct node** head_ref)  //Need to take double pointer then only head only change else only head_ref local to this function
{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->pnxt;  
        current->pnxt = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}


/* Detect loop 
1.use Hashing
2.Mark visited flags
3.Floyd’s Cycle-Finding Algorithm:
*/

int detectloop(struct node *list)
{
    struct node  *slow_p = list, *fast_p = list;
  
    while (slow_p && fast_p && fast_p->pnxt )
    {
        slow_p = slow_p->pnxt;
        fast_p  = fast_p->pnxt->pnxt;
        if (slow_p == fast_p)
        {
           printf("Found Loop");
           return 1;
        }
    }
    return 0;
}

/**akes two lists sorted in increasing order, and splices
   their nodes together to make one big sorted list which
   is returned. **/
struct node* SortedMerge(struct node* a, struct node* b) 
{
  struct node* result = NULL;
 
  /* Base cases */
  if (a == NULL) 
     return(b);
  else if (b==NULL) 
     return(a);
 
  /* Pick either a or b, and recur */
  if (a->member <= b->member) 
  {
     result = a;
     result->pnxt = SortedMerge(a->pnxt, b);
  }
  else
  {
     result = b;
     result->pnxt = SortedMerge(a, b->pnxt);
  }
  return(result);
}
/**Main start ***/

int main()
{
	int input;
	int value;
	int list_length =0;
	int nth_element;
	printf("Welcome to linked list program:\n");
	while(1)
	{
		printf("1.addnodefront        2.addnodeback                3.deletenode      \n ");
		printf("6.Lengthof(iter)      7.Lengthoflist(recursive)    4. DisplayNodes   \n");
		printf("8.swap nodes          9.GetNthElement              10.Midnode  \n");
		printf("11.Reverselist        5.Exit\n");		
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
		case 6:
			length_list();
			break;
		case 7:
			list_length = length_list_recursive(head);
			printf("List Length(Recursive) =%d\n",list_length);
			break;
		case 8:
			swapNodes(head,22,44); //if you wanna change  11,33 take new input values from scanf
			break;
		case 9:
			printf("Get Nth element & select N:");
			scanf("%d",&nth_element);
			nth_element=GetNth(head,nth_element);
			printf("Get N th element is =%d\n",nth_element);
			break;
		case 10:
			 midnode(head);
			 break;
		case 11:
			reverse(&head);
			break;
			
	
	 } //switch end

} //While end
	
} /***Main End ***/
