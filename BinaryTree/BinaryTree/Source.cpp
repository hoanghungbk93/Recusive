#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* creatNode(int data)
{
	Node* p = (Node*) malloc(sizeof(Node));
	if(p == NULL)
	{
		return NULL;
	}
	else
	{
		p->data = data;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}

Node* insertNode(Node *node, int key)
{
	if(node == NULL)
	{
		return creatNode(key);
	}
	else
	{
		if(node->data == key)
		{
			return node;
		}
		else
		{
			if(node->data < key)
			{
				node->right = insertNode(node->right, key);
			}
			else
			{
				node->left = insertNode(node->left, key);
			}
		}
	}
	return node;
}

void LNR(Node* node)
{
	if(node != NULL)
	{
		LNR(node->left);
		cout << node->data;
		LNR(node->right);
	}
}
void NLR(Node* node)
{
	if(node != NULL)
	{
		cout<< node->data;
		NLR(node->left);
		NLR(node->right);
	}
}

void LRN(Node* node)
{
	if(node != NULL)
	{
		LRN(node ->left);
		LRN(node->right);
		cout << node->data;
	}
}
void NRL(Node* node)
{
	if(node != NULL)
	{
		cout << node->data;
		NRL(node->right);
		NRL(node->left);
	}
}
void RNL(Node* node)
{
	if(node != NULL)
	{
		RNL(node->right);
		cout << node->data;
		RNL(node->left);
	}
}
void RLN(Node* node)
{
	if(node != NULL)
	{
		RLN(node->right);
		RLN(node->left);
		cout << node->data;
	}
}

Node* findNode(Node* node, int key)
{
	Node* ret = NULL;
	if(node != NULL)
	{
		if(node->data > key)
		{
			ret = findNode(node->left, key);
		}
		else if(node->data < key)
		{
			ret = findNode(node->right, key);
		}
		else
		{
			ret = node;
		}
	}
	return ret;
}
int main()
{
	Node* node = NULL;
	node = insertNode(node,5);
	insertNode(node,3);
	insertNode(node,7);
	insertNode(node,2);
	insertNode(node,4);
	insertNode(node,6);
	insertNode(node,8);
	insertNode(node,9);
	LNR(node);
	cout<<endl;
	RNL(node);
	Node * t = findNode(node, 6);
}