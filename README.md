# Data Structure Project
 
# Part II research student management system

A. Student management system is a project that have a many function like
• Adding student using linked list
Student linked list items (name , department , number of registered courses , pointer to linked list of students courses , pointer to next students)
• Adding student subject grades as a branched linked list from students which contain (subject name , total ,grade , point )
![alt text](https://i.imgur.com/X2SD15L.png)

print student ,subject ,grades

# B. Solve the following problems
I. In-place merge two sorted arrays
Given two sorted arrays X[] and Y[] of size m and n each, merge elements of X[] with elements of array Y[] by maintaining the sorted order. i.e. fill X[] with first m smallest elements and fill Y[] with remaining elements.
The conversion should be done in-place and without using any other data structure.
For example,
Input:
X[] = { 1, 4, 7, 8, 10 }
Y[] = { 2, 3, 9 }
Output:
X[] = { 1, 2, 3, 4, 7 }
Y[] = { 8, 9, 10}.
II. Assume you have the following Tree Struct
1. Print Tree
Write a print method that takes the node which the mirror image of the tree will start from if no parameter is sent to the function the default value will be the root node.
You must solve this problem by three different algorithms.
(Inorder, Preorder and Postorder)
(a) Inorder (Left, Root, Right) : 4 2 5 1 3
(b) Preorder (Root, Left, Right) : 1 2 4 5 3
(c) Postorder (Left, Right, Root) : 4 5 2 3 1
template<typename T>
struct Tree {
Tree(const T &v) : value(v), left(NULL), right(NULL) {}
T value;
Tree *left;
Tree *right;
};
2. Tree Flipping.
Write a flip method that takes the node which the mirror image of the tree will start from if no parameter is sent to the function the default value will be the root node. Flip the tree then print the flipped tree.
void flip(Tree <int>* t );
Output: print the flipped tree
3. Largest Values
Find the largest value in each row of this tree.
The output should be: [1, 3, 5]
In the first row, there is only one vertex, the root with value 1;
In the second row, there are two vertices with values 2 and 3, so the largest value is 3;
In the third row, there are two vertices with values 4 and 5, so the largest value is 5.
void largestValues(Tree <int>* t);
note : - There is many possible answers
4. Branches Sum
Sum encoded values in each path from root to leaf.
The output should be: 262 (124 + 125 + 13)
Path 1 → 2 → 4 encodes 124
Path 1 → 2 → 5 encodes 125
Path 1 → 3 encodes 13
long branchesSum(Tree<int> * t);
int main(){
Tree<int>* t = new Tree<int>(1);
Tree<int>* _1_left = new Tree<int>(2);
Tree<int>* _1_right = new Tree<int>(3);
t->left = _1_left; t->right = _1_right;
Tree<int>* _2_left = new Tree<int>(4);
Tree<int>* _2_right = new Tree<int>(5);
_1_left->left = _2_left; _1_left->right = _2_right;
largestValues(t);
return 0;
}
III. Balanced String
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input
string is valid.
An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
Input : exp = “{()}[][{()()}()]”
Output : “Balanced”
Input : exp = “{(])”
Output : "Not Balanced"
