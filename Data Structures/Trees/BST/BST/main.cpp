/*Program to implement Binary Search Tree*/
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
	
};

class _BST_
{
	struct node *head;
	public:
		_BST_();
		struct node* Insert(int,struct node*);
		void Delete_Ele(int);
		void Inorder(struct node* e);
		void Preorder(struct node* e);
		void Postorder(struct node* e);
		~_BST_();
		int findMax(struct node* e);
		int findMin(struct node* e);
		int height(struct node* e);
		int leafNodeNumber(struct node* e);
		int nonLeafNodeNumber(struct node* e);

};

_BST_::_BST_()
{
	head = NULL;

}

struct node* _BST_::Insert(int e,struct node* curr)
{
	if (curr == NULL) {
		struct node *temp;
		temp = new node;
		temp->data = e;
		temp->left = NULL;
		temp->right = NULL;
		head = temp;
		return temp;
	}
	else {
		if (e < curr->data) {
			curr->left = Insert(e, curr->left);
		}
		else {
			curr->right = Insert(e, curr->right);
		}
		//return curr;
	}
	
}

int _BST_::findMax(struct node* curr)
{
	if (curr != NULL) {
		while (curr->right != NULL) {
			curr = curr->right;
		}
		return curr->data;
	}
	else
		return -1;
}

int _BST_::findMin(struct node* curr)
{
	if (curr != NULL) {
		while (curr->left != NULL) {
			curr = curr->left;
		}
		return curr->data;
	}
	else
		return -1;
}

int _BST_::height(struct node* curr)
{
	if (curr == NULL) {
		return -1;
	}
	else {
		return(max(height(curr->left), height(curr->right))+1);
	}
}

int _BST_::leafNodeNumber(struct node* curr)
{
	if (curr == NULL) {
		return 0;
	}
	if (curr->left == NULL && curr->right == NULL)
		return 1;
	return(leafNodeNumber(curr->left) + leafNodeNumber(curr->right));
}

int _BST_::nonLeafNodeNumber(struct node* curr)
{
	if (curr == NULL) {
		return 0;
	}
	if (curr->left == NULL && curr->right == NULL)
		return 1;
	return(leafNodeNumber(curr->left) + leafNodeNumber(curr->right) + 1);
}

void _BST_::Inorder(struct node *curr)
{
	if (curr == NULL)
		return;
	else {
		Inorder(curr->left);
		cout << curr->data << endl;
		Inorder(curr->right);
	}
}

void _BST_::Preorder(struct node *curr)
{
	if (curr == NULL)
		return;
	else {
		
		cout << curr->data << endl;
		Preorder(curr->left);
		Preorder(curr->right);
	}
}

void _BST_::Postorder(struct node *curr)
{
	if (curr == NULL)
		return;
	else {

		Postorder(curr->left);
		Postorder(curr->right);
		cout << curr->data << endl;
	}
}

