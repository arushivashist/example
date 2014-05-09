#include<stdio.h>
#include<stdlib.h>
typedef struct tree node;
struct tree{
	int d;
	node *r;
	node *l;
	node * parent;
};


node * insert(node *tree,int data)
{
        if(tree)
        {
                if(tree->d < data)
                {
                        if(tree->r==NULL)
                        {

                                tree->r=(node*)malloc(sizeof(node));
                                tree->r->d=data;
                                tree->r->r=NULL;
                                tree->r->l=NULL;
                                tree->r->parent=tree;
                        }
                        else
                        insert(tree->r,data);
                }
                if(tree->d>data)
                {
                        if(tree->l==NULL)
                        {
                                tree->l=(node*)malloc(sizeof(node));
                                tree->l->d=data;
                                tree->l->r=NULL;
                                tree->l->l=NULL;
                                        tree->l->parent=tree;                }
                        else
                        insert(tree->l,data);
                }
        }
	return tree;

}


/*	if(root==NULL)
	{
		root=malloc(sizeof(node));
		root->r=NULL;
		root->l=NULL;
		root->parent=NULL;
		//return root;
	}

	else if(root->d > x)
	{
		root->l=insert(root->l,x);
                //return root;		
	}

	else
	{
		root->r=insert(root->r,x);
		//return root;
	}
	return root;*/

void find(node * root,int x)
{
	if(root==NULL)
	   printf("n\n");

	else if(root->d==x)
           printf("y\n");

	else  if(x < root->d)
	     find(root->l,x);
	else
	    find(root->r,x);
	
}
//int ld=0,rd=0;
int depth(node * root)
{
	if(root==NULL)
		return 0;
	else
	{
		int ld=depth(root->l);
		int rd=depth(root->r);
		if(ld>rd)
		   return ld+1;
		else
		   return rd+1;
	}
}
int minval(node * root)
{
	node * cur=root;
	while(cur->l!=NULL)
		cur=cur->l;
	return cur->d;
}
int size(node *root)//find no of nodes
{
	if(root==NULL)
	    return 0;
	else
		return (size(root->l)+1+size(root->r));
}

		
int haspathsum(node * root,int sum)//sub sum downwards, if 0 in end, true
{
	if(root==NULL)
		return 0;
	else{
		int subsum=sum- root->d;
		return(haspathsum(root->l,subsum)||haspathsum(root->r,subsum));
	}
}

void printArray(int ints[], int len) {
  int i;
  for (i=0; i<len; i++) {
    printf("%d ", ints[i]);
  }
  printf("\n");
}
void printPathsRecur(node *,int a[],int);
/*
 Given a binary tree, print out all of its root-to-leaf
 paths, one per line. Uses a recursive helper to do the work.
*/
void printPaths(node* node) {
  int path[1000];

  printPathsRecur(node, path, 0);
}

/*
 Recursive helper function -- given a node, and an array containing
 the path from the root node up to but not including this node,
 print out all the root-leaf paths.
*/
void printPathsRecur(node* node, int path[], int pathLen) {
  if (node==NULL) return;

  // append this node to the path array
  path[pathLen] = node->d;
  pathLen++;

  // it's a leaf, so print the path that led to here
  if (node->l==NULL && node->r==NULL) {
    printArray(path, pathLen);
  }
  else {
  // otherwise try both subtrees
    printPathsRecur(node->l, path, pathLen);
    printPathsRecur(node->r, path, pathLen);
  }
} 
node* findmin(node *root);



/* Print nodes at a given level */
void printGivenLevel(node* root, int level)
{
  if(root == NULL)
    return;
  if(level == 1)
    printf("%d ", root->d);
  else if (level > 1)
  {
    printGivenLevel(root->l, level-1);
    printGivenLevel(root->r, level-1);
  }

}

/* Function to print level order traversal a tree*/

void printLevelOrder(node* root)
{
  int h =depth(root);
  int i;
  for(i=1; i<=h; i++)
    printGivenLevel(root, i);
}    




node * del(node * root,int x)
{
	if(root==NULL){
	     printf("empty\n");
	   }

	else if(root->d < x)
		root->r=del(root->r,x);
	else if(root->d > x)
		root->l=del(root->l,x);
	else{
		if(root->r && root->l)
		{
			node * temp=findmin(root->r);
			root->d=temp->d;
			root->r=del(root->r,temp->d);
		}

		else{
			node *t =root;
			if(root->l==NULL)
				root=root->r;
                        else if(root->r ==NULL)
				root=root->l;
			free(t);
		}
	}
	return root;
}
void mirror(node* ROOT) {
  if (ROOT==NULL) {
    return;
  }
  else {
	  node* temp=NULL;

    // do the subtrees
    mirror(ROOT->l);
    mirror(ROOT->r);
   
    // swap the pointers in this node
    temp = ROOT->l;
    ROOT->l =ROOT->r;
    ROOT->r = temp;
  }
} 
void preorder(node * root)
{
	if(root!=NULL)
	{

		printf("%d",root->d);
		preorder(root->l);
		preorder(root->r);
	}
}
void postorder(node *root)
{
	if(root!=NULL){
		postorder(root->l);
		postorder(root->r);
		printf("%d ",root->d);
	}
}
void inorder(node*root)//incresing order
{
	if(root!=NULL){

		inorder(root->l);

		printf("%d",root->d);
		inorder(root->r);
	}

}
node * findmax(node * root)
{
	while(root->r!=NULL)
	{	

		root=root->r;
	}
	return root;
}
node *findmin(node * root)
{
	while(root->l!=NULL)
		root=root->r;
	return root;
}

int  main()
{
	int i,n,data;
	scanf("%d",&n);
	scanf("%d",&data);
        node* root=(node*)malloc(sizeof(node));
        root->d=data;
        root->l=NULL;
        root->r=NULL;
        root->parent=NULL;
	while(--n)
	{
		scanf("%d",&data);
		root=insert(root,data);
	}
	printLevelOrder(root);
	printf("\n");
	
	/*
	i=depth(root);
        printLevelOrder(root);
	printf("%d\n",i);
	printf("inorder\n          ");

	inorder(root);

	printf("\npre\n        ");
	preorder(root);

	printf("\npost\n          ");
	postorder(root);



	printf("\nfind : ");
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&i);
		find(root,i);
	}
	printf("\ndel : ");
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&i);
		del(root,i);
	}

	preorder(root);*/
	return 0;
}




