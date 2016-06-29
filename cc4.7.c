/*
cc4.7: Design an algorithm and write code to find the first common ancestor of two nodes in a binary 
       tree. Avoid storing additional nodes in a data structure. NOTE: This is not necessary to be a
       binary search tree.


IDEA: This is what we call LCA(lowest common ancestor). LCA must satisfy that both nodes are sitting
      on the different branch. If root is either equal to p or q, then return root. If we cannot find
      p or q on the root, we go to check the left branch and right branch. If we find that both 
      branches are not equal to NULL, then the root must be the LCA; else go to the non-NULL branch
      and continue the process. (For certain node, if we find p and q on both left and right child,
      then we return the root; if we find either p or q in one child, we return the child!!)


*/





#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;

}TreeNode;

TreeNode *create(int x)
{
	TreeNode *node;
	node=(TreeNode *)malloc(sizeof(TreeNode));
	node->val=x;
	node->left=NULL;
	node->right=NULL;
	return node;
}

/* Time: O(n) */
TreeNode *Ancestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
	if(root==NULL)
		return NULL;
	if(root==p||root==q)
		return root;
	TreeNode *left=Ancestor(root->left, p, q);
	TreeNode *right=Ancestor(root->right, p, q);
    if(left&&right)
    	return root;
    else
    	return left==NULL? right:left;

}

void main()
{
 	TreeNode *n0, *n1, *n2, *n3, *n4, *n5, *n6;
 	TreeNode *n7, *n8, *n9, *n10, *n11, *n12, *n13, *n14;
 	n0=create(0);
	n1=create(1);
	n2=create(2);
	n3=create(3);
	n4=create(4);
	n5=create(5);
	n6=create(6);
	n7=create(7);
	n8=create(8);
	n9=create(9);
	n10=create(10);
	n11=create(11);
	n12=create(12);
	n13=create(13);
	n14=create(14);

	n0->left=n1;
	n0->right=n2;

	n1->left=n3;
	n1->right=n4;

	//n2->left=n5;
	//n2->right=n6;

	n3->left=n7;
	n3->right=n8;

	n4->left=n9;
	n4->right=n10;

	//n5->left=n11;
	//n5->right=n12;

	//n6->left=n13;
	//n6->right=n14;

	printf("Ancestor is: %d\n", Ancestor(n0, n3, n2)->val);
   
    free(n0);
    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    free(n6);
    free(n7);
    free(n8);
    free(n9);
    free(n10);
    free(n11);
    free(n12);
    free(n13);
    free(n14);

}