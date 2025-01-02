#include <iostream>
using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value)
    {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Tree
{
private:
    TreeNode *head;

    void inorder(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        cout << node->value << " ";
        inorder(node->left);
        inorder(node->right);
    }

    void preorder(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        preorder(node->left);
        cout << node->value << " ";
        preorder(node->right);
    }

    void postorder(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        postorder(node->left);
        postorder(node->right);
        cout << node->value << " ";
    }

    TreeNode *find(int target)
    {
        return _find(target, head);
    }

    TreeNode *_find(int target, TreeNode *node)
    {
        if (!node)
            return node;
        if (node->value == target)
            return node;
        TreeNode *left = _find(target, node->left);
        if (left)
            return left;
        return _find(target, node->right);
    }

    void insert(int value, int target, string lorR)
    {
        if (head->value == target)
        {
            TreeNode *node = new TreeNode(value);
            head->left = node;
            return;
        }
        TreeNode *tNode = find(target);
        if (!tNode)
            throw std::runtime_error("Node not found");
        TreeNode *node = new TreeNode(value);
        lorR == "left" ? tNode->left = node : tNode->right = node;
    }

public:
    Tree(int value)
    {
        TreeNode *newNode = new TreeNode(value);
        this->head = newNode;
    }

    TreeNode *getHead()
    {
        return head;
    }

    void insertLeftOf(int target, int value)
    {
        insert(value, target, "left");
    }

    void insertRightOf(int target, int value)
    {
        insert(value, target, "right");
    }

    void printInorder()
    {
        inorder(this->head);
        cout<<endl;
    }

    void printPreorder()
    {
        preorder(this->head);
        cout<<endl;
    }

    void printPostorder()
    {
        postorder(this->head);
        cout << endl;
    }

    TreeNode *insertLeft(int value, TreeNode *node)
    {
        TreeNode *newNode = new TreeNode(value);
        node->left = newNode;
        return newNode;
    }

    TreeNode *insertRigth(int value, TreeNode *node)
    {
        TreeNode *newNode = new TreeNode(value);
        node->right = newNode;
        return newNode;
    }
};

int main()
{
    Tree *tree = new Tree(45);

    tree->insertLeftOf(45, 32);
    tree->insertRightOf(32,65);
    tree->insertLeftOf(65,12);

    tree->printPostorder();
}