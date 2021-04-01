#include <stdio.h>
002	#include <stdlib.h>
003	#include <ctype.h>
004	 
005	#define MAX 10
006	#define EMPTY -1
007	 
008	 
009	struct node
010	{
011	    char element;
012	    struct node *left,*right;
013	};
014	 
015	struct stack
016	{
017	    struct node *data[MAX];
018	    int top;
019	};
020	 
021	int isempty(struct stack *s)
022	{
023	    return (s->top == EMPTY) ? 1 : 0;
024	}
025	 
026	void emptystack(struct stack* s)
027	{
028	    s->top=EMPTY;
029	}
030	 
031	void push(struct stack* s, struct node *item)
032	{
033	    if(s->top == (MAX-1))
034	    {
035	        printf("\nSTACK FULL");
036	    }
037	    else
038	    {
039	        ++s->top;
040	        s->data[s->top]=item;
041	 
042	    }
043	}
044	 
045	struct node* pop(struct stack* s)
046	{
047	    struct node *ret=NULL;
048	    if(!isempty(s))
049	    {
050	        ret= s->data[s->top];
051	        --s->top;
052	    }
053	    return ret;
054	}
055	 
056	void postfix2exptree(char* postfix, struct node **root)
057	{
058	    struct stack X;
059	    struct node *newnode,*op1,*op2;
060	    char *p;
061	    p = &postfix[0];
062	    emptystack(&X);
063	    while(*p)
064	    {
065	 
066	        while(*p == ' ' || *p == '\t')
067	        {
068	            p++;
069	        }
070	 
071	        if(isalpha(*p) || isdigit(*p))
072	        {
073	            newnode = malloc(sizeof(struct node));
074	            newnode->element = *p;
075	            newnode->left = NULL;
076	            newnode->right = NULL;
077	            push(&X,newnode);
078	        }
079	        else
080	        {
081	            op1 = pop(&X);
082	            op2 = pop(&X);
083	            newnode = malloc(sizeof(struct node));
084	            newnode->element = *p;
085	            newnode->left = op2;
086	            newnode->right = op1;
087	            push(&X,newnode);
088	        }
089	        p++;
090	    }
091	    *root = pop(&X);
092	}
093	 
094	void inorder(struct node *x)
095	{
096	    if(x != NULL)
097	    {
098	        inorder(x->left);
099	        printf("%c ",x->element);
100	        inorder(x->right);
101	    }
102	}
103	 
104	void preorder(struct node *x)
105	{
106	    if(x != NULL)
107	    {
108	        printf("%c ",x->element);
109	        preorder(x->left);
110	        preorder(x->right);
111	    }
112	}
113	 
114	void postorder(struct node *x)
115	{
116	    if(x != NULL)
117	    {
118	        postorder(x->left);
119	        postorder(x->right);
120	        printf("%c ",x->element);
121	    }
122	}
123	 
124	int main()
125	{
126	    struct node *r;
127	    postfix2exptree("A B C * +",&r);
128	    printf("Inorder = ");
129	    inorder®;
130	    printf("\nPreorder = ");
131	    preorder®;
132	    printf("\nPostorder = ");
133	    postorder®;
134	    return 0;
135	}