#include <iostream>
#include <string>
using namespace std;

struct Node {
    string keyword, meaning;
    Node *left, *right;
    Node(string k, string m) : keyword(k), meaning(m), left(NULL), right(NULL) {}
};

class Dictionary {
    Node* root;
    
    Node* insert(Node* root, string key, string meaning) {
        if (!root) return new Node(key, meaning);
        if (key < root->keyword) root->left = insert(root->left, key, meaning);
        else if (key > root->keyword) root->right = insert(root->right, key, meaning);
        return root;
    }
    
    Node* findMin(Node* root) {
        while (root->left) root = root->left;
        return root;
    }
    
    Node* deleteNode(Node* root, string key) {
        if (!root) return root;
        if (key < root->keyword) root->left = deleteNode(root->left, key);
        else if (key > root->keyword) root->right = deleteNode(root->right, key);
        else {
            if (!root->left) return root->right;
            else if (!root->right) return root->left;
            Node* temp = findMin(root->right);
            root->keyword = temp->keyword;
            root->meaning = temp->meaning;
            root->right = deleteNode(root->right, temp->keyword);
        }
        return root;
    }
    
    Node* update(Node* root, string key, string newMeaning) {
        if (!root) return NULL;
        if (key < root->keyword) return update(root->left, key, newMeaning);
        else if (key > root->keyword) return update(root->right, key, newMeaning);
        else root->meaning = newMeaning;
        return root;
    }
    
    void inorder(Node* root) {
        if (root) {
            inorder(root->left);
            cout << root->keyword << " : " << root->meaning << endl;
            inorder(root->right);
        }
    }
    
    void reverseInorder(Node* root) {
        if (root) {
            reverseInorder(root->right);
            cout << root->keyword << " : " << root->meaning << endl;
            reverseInorder(root->left);
        }
    }
    
    int search(Node* root, string key, int& comparisons) {
        if (!root) return -1;
        comparisons++;
        if (key < root->keyword) return search(root->left, key, comparisons);
        else if (key > root->keyword) return search(root->right, key, comparisons);
        return comparisons;
    }
    
public:
    Dictionary() : root(NULL) {}
    
    void insert(string key, string meaning) {
        root = insert(root, key, meaning);
    }
    
    void deleteKeyword(string key) {
        root = deleteNode(root, key);
    }
    
    void updateMeaning(string key, string newMeaning) {
        root = update(root, key, newMeaning);
    }
    
    void displayAscending() {
        inorder(root);
    }
    
    void displayDescending() {
        reverseInorder(root);
    }
    
    void searchKeyword(string key) {
        int comparisons = 0;
        int result = search(root, key, comparisons);
        if (result == -1) cout << "Keyword not found" << endl;
        else cout << "Keyword found with " << comparisons << " comparisons" << endl;
    }
};

int main() {
    Dictionary dict;
    int choice;
    string key, meaning;
    
    do {
        cout << "\nDictionary Operations:\n";
        cout << "1. Insert\n2. Delete\n3. Update\n4. Display Ascending\n5. Display Descending\n6. Search\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                cout << "Enter keyword: ";
                getline(cin, key);
                cout << "Enter meaning: ";
                getline(cin, meaning);
                dict.insert(key, meaning);
                break;
            case 2:
                cout << "Enter keyword to delete: ";
                getline(cin, key);
                dict.deleteKeyword(key);
                break;
            case 3:
                cout << "Enter keyword to update: ";
                getline(cin, key);
                cout << "Enter new meaning: ";
                getline(cin, meaning);
                dict.updateMeaning(key, meaning);
                break;
            case 4:
                dict.displayAscending();
                break;
            case 5:
                dict.displayDescending();
                break;
            case 6:
                cout << "Enter keyword to search: ";
                getline(cin, key);
                dict.searchKeyword(key);
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);
    
    return 0;
}
