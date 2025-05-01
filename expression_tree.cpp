#include<string>
#include<cctype>
#include<stack>
#include<iostream>
using namespace std;
struct Node{
    char data;
    Node *left;
    Node *right;
    Node(char value){
        data = value;
        left = nullptr;
        right = nullptr;
        
    }
};

bool isoperator(char c){
    return(c=='+'|| c=='-'|| c=='*'|| c=='/');
}
Node *exp_tree(const std:: string& prefix)
{
    stack<Node*> s;
    for(int i=prefix.length()-1;i>=0;i--){
        char ch = prefix[i];
        if(isalpha(ch)){
            s.push(new Node(ch));

        }
        else if(isoperator(ch)){
            Node *opNode = new Node(ch);
            opNode-> left = s.top();
            s.pop();
            opNode->right = s.top();
            s.pop();
            s.push(opNode);

        }
    }
    return s.top();
}

void postorder(Node* root){
if (root == nullptr) {
return;
}
stack<Node*>s1;
stack<char>rs;
s1.push(root);
while(!s1.empty()){
    Node *t = s1.top();
    s1.pop();

rs.push(t->data);

if(t->left){
    s1.push(t->left);
}
if(t->right){
    s1.push(t->right);

}
}
while(!rs.empty()){
    cout<<rs.top();
    rs.pop();
}
}

void deletetree(Node* root){
    if(root ==nullptr){
        return;
    }
    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        Node* t = s.top();
        s.top();
        if(t->left){
            s.push(t->left);
        }
        if(t->right){
            s.push(t->right);
        }
        delete t;
    }
}

int main() {
    string exp;
    
    cout << "Enter the prefix expression: ";
    cin >> exp;
    
    Node* root = exp_tree(exp);
    
    cout << "Post-order traversal of the expression tree: ";
    postorder(root);
    cout << endl;

    cout<<"deletig all the nodes......"<<endl;
    deletetree(root);

    return 0;
}
