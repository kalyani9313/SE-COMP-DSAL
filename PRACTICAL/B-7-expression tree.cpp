#include <iostream>
#include <stack>
#include <cctype>
using namespace std;
struct Node
{
char data;
Node* left;
Node* right;
Node(char value)
{
data = value;
left = NULL;
right = NULL;
}
};
class ExpressionTree
{
private:
Node* root;
public:
ExpressionTree()
{
root = NULL;
}
void constructTree(const string& expression)
{
stack<Node*> nodeStack;
for (int i = expression.length() - 1; i >= 0; i--)
{
char c = expression[i];
if (isOperand(c))
{
Node* newNode = new Node(c);
nodeStack.push(newNode);
}
else if (isOperator(c))
{
Node* newNode = new Node(c);
newNode->left = nodeStack.top();
nodeStack.pop();
newNode->right = nodeStack.top();
nodeStack.pop();
nodeStack.push(newNode);
}
}
root = nodeStack.top();
}
void postorderTraversal() const
{
if (root == NULL)
{
cout << "\n\tTree is empty." << endl;
return;
}
stack<Node*> nodeStack;
Node* current = root;
Node* lastVisited = NULL;
while (!nodeStack.empty() || current != NULL)
{
if (current != NULL)
{
nodeStack.push(current);
current = current->left;
}
else
{
Node* topNode = nodeStack.top();
if (topNode->right != NULL && topNode->right != lastVisited)
{
current = topNode->right;
}
else
{
cout << topNode->data << " ";
lastVisited = topNode;
nodeStack.pop();
}
}
}
cout << endl;
}
void deleteTree(Node* node)
{
if (node == NULL)
{
return;
}
deleteTree(node->left);
deleteTree(node->right);
delete node;
}
void deleteTree()
{
deleteTree(root);
root = NULL;
cout << "\n\tTree deleted." << endl;
}
bool isOperand(char c) const
{
return isalpha(c);
}
bool isOperator(char c) const
{
return (c == '+' || c == '-' || c == '*' || c == '/');
}
};
int main()
{
ExpressionTree expressionTree;
cout<<"\n\t ________DSAL PRACTICAL-5(B-07)";
cout<<"\n\t _________PREPARED BY:-Siddhesh Pendharkar";
int choice;
while (true)
{
cout<< "\n\t_"<<endl;
cout << "\n\tMenu:" << endl;
cout << "\n\t1. Enter prefix expression and construct the tree" << endl;
cout << "\n\t2. Perform Postorder Traversal" << endl;
cout << "\n\t3. Delete Tree" << endl;
cout << "\n\t4. Exit" << endl;
cout<< "\n\t_"<<endl;
cout << "\n\tEnter your choice: ";
cin >> choice;
cin.ignore();
switch (choice)
{
case 1:
{
string prefixExpression;
cout << "\n\tEnter the prefix expression: ";
getline(cin, prefixExpression);
expressionTree.constructTree(prefixExpression);
cout << "\n\tExpression tree constructed." << endl;
break;
}
case 2:
cout << "\n\tPostorder Traversal: ";
expressionTree.postorderTraversal();
break;
case 3:
expressionTree.deleteTree();
break;
case 4:
cout << "\n\tTHANK UHH!!!" << endl;
return 0;
default:
cout << "\n\tInvalid choice. Please try again." << endl;
}
cout << endl;
}
}
