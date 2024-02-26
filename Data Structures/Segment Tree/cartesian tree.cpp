// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

#define maxLen 30 

// Node of the BST 
struct node { 
	int data; 
	node* left; 
	node* right; 
	node(int data) 
	{ 
		left = NULL; 
		right = NULL; 
		this->data = data; 
	} 
}; 

// Array to store segment tree 
int segtree[maxLen * 3]; 

// Function to create segment-tree to answer 
// range-max query 
int buildTree(int l, int r, int i, int* arr) 
{ 
	// Base case 
	if (l == r) { 
		segtree[i] = l; 
		return l; 
	} 

	// Maximum index in left range 
	int l1 = buildTree(l, (l + r) / 2, 
					2 * i + 1, arr); 

	// Maximum index in right range 
	int r1 = buildTree((l + r) / 2 + 1, 
					r, 2 * i + 2, arr); 

	// If value at l1 > r1 
	if (arr[l1] > arr[r1]) 
		segtree[i] = l1; 

	// Else 
	else
		segtree[i] = r1; 

	// Returning the maximum in range 
	return segtree[i]; 
} 

// Function to answer range max query 
int rangeMax(int l, int r, int rl, 
			int rr, int i, int* arr) 
{ 

	// Base cases 
	if (r < rl || l > rr) 
		return -1; 
	if (l >= rl and r <= rr) 
		return segtree[i]; 

	// Maximum in left range 
	int l1 = rangeMax(l, (l + r) / 2, rl, 
					rr, 2 * i + 1, arr); 

	// Maximum in right range 
	int r1 = rangeMax((l + r) / 2 + 1, r, 
					rl, rr, 2 * i + 2, arr); 

	// l1 = -1 means left range 
	// was out-side required range 
	if (l1 == -1) 
		return r1; 
	if (r1 == -1) 
		return l1; 

	// Returning the maximum 
	// among two ranges 
	if (arr[l1] > arr[r1]) 
		return l1; 
	else
		return r1; 
} 

// Function to print the inorder 
// traversal of the binary tree 
void inorder(node* curr) 
{ 

	// Base case 
	if (curr == NULL) 
		return; 

	// Traversing the left sub-tree 
	inorder(curr->left); 

	// Printing current node 
	cout << curr->data << " "; 

	// Traversing the right sub-tree 
	inorder(curr->right); 
} 

// Function to build cartesian tree 
node* createCartesianTree(int l, int r, int* arr, int n) 
{ 
	// Base case 
	if (r < l) 
		return NULL; 

	// Maximum in the range 
	int m = rangeMax(0, n - 1, l, r, 0, arr); 

	// Creating current node 
	node* curr = new node(arr[m]); 

	// Creating left sub-tree 
	curr->left = createCartesianTree(l, m - 1, arr, n); 

	// Creating right sub-tree 
	curr->right = createCartesianTree(m + 1, r, arr, n); 

	// Returning current node 
	return curr; 
} 

// Driver code 
int main() 
{ 
	// In-order traversal of cartesian tree 
	int arr[] = { 8, 11, 21, 100, 5, 70, 55 }; 

	// Size of the array 
	int n = sizeof(arr) / sizeof(int); 

	// Building the segment tree 
	buildTree(0, n - 1, 0, arr); 

	// Building and printing cartesian tree 
	inorder(createCartesianTree(0, n - 1, arr, n)); 
} 
