#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
#include <sstream>
#include <algorithm>
using namespace std;

class binaryTreeNode {
public:

    binaryTreeNode* left, * right;
    int data;

    binaryTreeNode(int data=NULL, binaryTreeNode *left=nullptr, binaryTreeNode *right=nullptr) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class binaryTree {
public:
    
    binaryTree() {
        this->treeRoot = nullptr;
    }

    binaryTreeNode* getRoot() {
        return this->treeRoot;
    }

    binaryTreeNode* addNode(binaryTree* tree, binaryTreeNode* node, int data) {
        if (!tree->treeRoot) tree->setRoot(data);
        else {
            if (data > node->data) {
                if (node->right) node->right = addNode(tree, node->right, data);
                else node->right = new binaryTreeNode(data, nullptr, nullptr);
            }
            else if (data < node->data) {
                if (node->left) node->left = addNode(tree, node->left, data);
                else node->left = new binaryTreeNode(data, nullptr, nullptr);
            }
        }
        return node;
    }
    void fillTree(binaryTree* tree, int count) {
        for (int i = 0; i < count; i++) {
            int num;
            cin >> num;
            tree->addNode(tree, tree->treeRoot, num);
        }
    }
    void printTree(binaryTreeNode* node, int indent) {
        if (treeRoot == nullptr) throw "Root is empty";
        if (node->right) printTree(node->right, indent + 4);
        if (indent) cout << setw(indent) << ' ';
        if (node->right) cout<< "  /\n" << setw(indent) << ' ';
        cout << node->data << " \n";
        if (node->left) {
            cout << setw(indent) << " " << " \\\n";
            printTree(node->left, indent + 4);
        }
    }
    bool checkBinaryTree(binaryTree* tree, queue<binaryTreeNode*> queue, int level) {


        if (!checkLeft(tree, queue.front())) return false;
        if (!checkRight(tree, queue.front())) return false;

        int temp_level = 0;

        for (int i = 0; i < level; i++)
        {
            if (queue.front()->left) {
                queue.push(queue.front()->left);
                temp_level++;
            }
            if (queue.front()->right) {
                queue.push(queue.front()->right);
                temp_level++;
            }
            queue.pop();
            if (queue.size()==0) break;
        }

        level = temp_level++;
        if (!queue.empty()) checkBinaryTree(tree, queue, level);
        else return 1;
    }

    void findItemPath(binaryTree* tree, int findItem) {
        queue <int> queue;

        queue = findItems(tree, this->treeRoot, findItem, queue);

        printPathToItem(queue);
    }

private:
    binaryTreeNode* treeRoot;

    void setRoot(int data) {
        this->treeRoot = new binaryTreeNode(data);
    }

    bool checkLeft(binaryTree* tree, binaryTreeNode* node) {
        if (node->left == nullptr) return true;
        else if (node->left->data < node->data) return true;
        else return false;
    }
    bool checkRight(binaryTree* tree, binaryTreeNode* node) {
        if (node->right == nullptr) return true;
        else if (node->right->data > node->data) return true;
        else return false;
    }

    queue<int> findItems(binaryTree* tree, binaryTreeNode* node, int findItem, queue<int> queue) {
        if (!tree->treeRoot) throw "Tree is empty";
        else {
            if (node) {
                while (node->data != findItem) {
                    if (findItem < node->data) {
                        queue.push(node->data);
                        findItems(tree, node->left, findItem, queue);
                    }
                    else {
                        queue.push(node->data);
                        findItems(tree, node->right, findItem, queue);
                    }
                }
            }
            else throw "Item not found";
            return queue;
        }
        
    }

    void printPathToItem(queue<int> queue) {
        for (int i = 0; i < queue.size(); i++)
        {
            cout << i << " = " << queue.front();
            queue.pop();
        }
    }
};

int main()
{
    binaryTree tree;
    int count = 7;
    tree.fillTree(&tree, count);
    tree.printTree(tree.getRoot(), 0);
    queue <binaryTreeNode*> queue;
    queue.push(tree.getRoot());
    if (tree.checkBinaryTree(&tree, queue, 1) > 0) cout << "Tree is right cool tree!";
    else cout << "My tree is shit";
    queue.pop();
    tree.findItemPath(&tree, 4);
    return 0;
}