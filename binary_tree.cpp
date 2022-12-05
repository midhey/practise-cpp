#include <iostream>
using namespace std;

class TreeItem {
public:
    int data;
    TreeItem* left, * right;

    TreeItem(int data, TreeItem* left, TreeItem* right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class Tree {
public:

    Tree() {
        this->root = nullptr;
        this->level = 0;
    }

    TreeItem* addItem(Tree* tree, int data, TreeItem* item);
    int findLevel(Tree* tree, TreeItem* item);
    void printTree(TreeItem* item, int level) {
        if (item) {
            printTree(item->right, level + 1);
            for (int i = 0; i < level; i++) cout << "\t";
            cout << item->data << endl;
            printTree(item->left, level + 1); 
        }
    }
    int setLevel(Tree* tree) {
       return this->level = findLevel(tree, this->root);
    }
    void checkBinary(Tree* tree, TreeItem* item, int findItem, int data);
    TreeItem* getRoot() {
        return this->root;
    }

private: 
    TreeItem* root;

    void setRoot(int data) {
        this->root = new TreeItem(data, nullptr, nullptr);
    }
    TreeItem* findItems(Tree* tree, TreeItem* item, int findItem);
 
    int level;

};

TreeItem* Tree::addItem(Tree* tree, int data, TreeItem* item) {
    if (!tree->getRoot()) tree->setRoot(data);
    else {
        if (data > item->data) {
            if (item->right) item->right = addItem(tree, data, item->right);
            else item->right = new TreeItem(data, nullptr, nullptr);
        }
        else if (data < item->data) {
            if (item->left) item->left = addItem(tree, data, item->left);
            else item->left = new TreeItem(data, nullptr, nullptr);
        }
    }
    return item;
}
int Tree::findLevel(Tree* tree, TreeItem* item) {
    if (!item) return 0;
    else return max(findLevel(tree, item->left), findLevel(tree, item->right)) + 1;
}
void fillTree(Tree* tree, int count) {    
    for (int i = 0; i < count; i++) {
        int num;
        cin >> num;
        tree->addItem(tree, num, tree->getRoot());
    }
}
TreeItem* Tree::findItems(Tree* tree, TreeItem* item, int findItem) {
    if (!tree->root) throw "Tree is empty";
    else {
        if (item) {
            while (item->data != findItem) {
                if (findItem < item->data) return findItems(tree, item->left, findItem);
                else return findItems(tree, item->right, findItem);
            }
        }
        else throw "Item not found";
    }
}
void Tree::checkBinary(Tree* tree, TreeItem* item,int findItem, int data) {
    TreeItem* tempItem = tree->findItems(tree, item, findItem);
    if (tempItem->data > data) {
        if (tempItem->left == nullptr) tempItem->left = new TreeItem(data, nullptr, nullptr);
        else throw "This place is taken";
    }
    else if (tempItem->data < data) {
        if (tempItem->right == nullptr) tempItem->right = new TreeItem(data, nullptr, nullptr);
        else throw "This place is taken";
    }
}


int main()
{
    int size;
    cout << "Enter size of Tree: ";
    cin >> size;

    Tree BT;
    fillTree(&BT, size);
    system("cls");
    BT.printTree(BT.getRoot(), BT.setLevel(&BT));
    BT.checkBinary(&BT, BT.getRoot(), 2, 5);
    cout << "\n\n\n\n\n";
    BT.printTree(BT.getRoot(), BT.setLevel(&BT));
    return 0;
}


