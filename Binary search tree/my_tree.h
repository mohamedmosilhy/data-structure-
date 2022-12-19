#ifndef MY_TREE_H
#define MY_TREE_H

#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

template <class T>
struct Node {
    T data;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(T data) : data(data) {}
    // Add the constructors you want
};

template <class T>
class MyTree{

    private:
    Node<T>* root = nullptr;

    Node<T>* sortedVectorToBST(std::vector<T> elements, int start, int end)
        {   
            if (start > end)
                return NULL;

            float mid = ceil((start + end)/2.0);
            Node<T>* temp = new Node<T>(elements[mid]);
            temp->left = sortedVectorToBST(elements, start, mid - 1);
            temp->right = sortedVectorToBST(elements, mid + 1, end);

            root  = temp;
            return root;
        }

        Node<T>* magic_insert_key(Node<T>* root,T key){

            if (!root)
            {   
                return new Node<T>(key);
            }
            if (key > root->data)
            { 
                root->right = magic_insert_key(root->right,key); 
            }
            else if (key < root->data)
            {
                root->left = magic_insert_key(root->left,key);
            }
            return root;

            // int n = vec.size();
            // return sortedVectorToBST(vec,0,n-1);

        }

        Node<T>* magic_insert_node(Node<T>* root,Node<T> node){
            if (!root)
            {   
                return new Node<T>(node.data);
            }
            if (node.data > root->data)
            { 
                root->right = magic_insert_node(root->right,node); 
            }
            else if (node.data < root->data)
            {
                root->left = magic_insert_node(root->left,node);
            }
            return root;
        }

        Node<T>* magic_search(Node<T>* root,T key){
            if (root == nullptr || root->data == key)
            {
                return root;
            }
            if (key > root->data)
            {
                return magic_search(root->right,key);
            }
            return magic_search(root->left,key);
        }
        
        Node<T>* magic_delete_key(Node<T>* root,T key){
            if (root == nullptr)
            {
                return root;
            }
            if (root->data > key)
            {
                root->left = magic_delete_key(root->left,key);
                return root;
            }
            else if(root->data < key)
            {
               root->right = magic_delete_key(root->right,key);
                return root;
            }

            if (root->left == nullptr)
            {
                Node<T>* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == nullptr)
            {
                Node<T>* temp = root->left;
                delete root;
                return temp;
            }
            else
            {
               Node<T>* succparent = root;
               Node<T>* succ = root->right;
                while (succ->left != nullptr)
                {
                    succparent = succ;
                    succ = succ->left;
                }
                if (succparent != root)
                    succparent->left = succ->right;
                else
                    succparent->right = succ->right;

                delete succ;
                return root;
            }
        }

        Node<T>* magic_delete_node(Node<T>* root,Node<T> node){
            if (root == nullptr)
            {
                return root;
            }
            if (root->data > node.data)
            {
                root->left = magic_delete_node(root->left,node.data);
                return root;
            }
            else if(root->data < node.data)
            {
                root->right = magic_delete_node(root->right,node.data);
                return root;
            }

            if (root->left == nullptr)
            {
                Node<T>* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == nullptr)
            {
                Node<T>* temp = root->left;
                delete root;
                return temp;
            }
            else
            {
               Node<T>* succparent = root;
               Node<T>* succ = root->right;
                while (succ->left != nullptr)
                {
                    succparent = succ;
                    succ = succ->left;
                }
                if (succparent != root)
                    succparent->left = succ->right;
                else
                    succparent->right = succ->right;

                delete succ;
                return root;
            }
        }

        void magic_inorder_rec(Node<T>* root,std::vector<T>& vec){
            if (root != NULL) {
            magic_inorder_rec(root->left,vec);
            vec.push_back(root->data);
            magic_inorder_rec(root->right,vec);
            }
        }
        void magic_preorder_rec(Node<T>* root,std::vector<T>& vec){
            if (root != NULL) {
            vec.push_back(root->data);
            magic_preorder_rec(root->left,vec);
            magic_preorder_rec(root->right,vec);
            }
        }
        void magic_postorder_rec(Node<T>* root,std::vector<T>& vec){
            if (root != NULL) {
            magic_postorder_rec(root->left,vec);
            magic_postorder_rec(root->right,vec);
            vec.push_back(root->data);
            }
        }

        int magic_get_height(Node<T>* root){
            std::queue<Node<T>*> q;
            q.push(root);
            int height = 0;
            while (!q.empty()) {
                int size = q.size();
                for (int i = 0; i < size; i++) {
                Node<T>* temp = q.front();
                q.pop();
                if (temp->left != NULL) {
                    q.push(temp->left);
                }
                if (temp->right != NULL) {
                    q.push(temp->right);
                }
                }
                height++;
            }
            return height - 1;
        }

        void magic_clear(Node<T>* root){
            if (root == NULL) return;
 
            /* first delete both subtrees */
            magic_clear(root->left);
            magic_clear(root->right);
            delete root;
        }

        void magic_breadth_traversal(Node<T>* root,std::vector<T>& vec){
            std::queue<Node<T>*> q;
            q.push(root);
            while (!q.empty()) {
                int size = q.size();
                for (int i = 0; i < size; i++) {
                Node<T>* temp = q.front();
                q.pop();
                if (temp->left != NULL) {
                    q.push(temp->left);
                }
                if (temp->right != NULL) {
                    q.push(temp->right);
                }
                    vec.push_back(temp->data);
                }
            }
        }

       void magic_inorder_it(Node<T>* root,std::vector<T>& vec){
            std::stack<Node<T>*> st;
            while (root != nullptr || !st.empty())
            {
                if (root != nullptr)
                {
                    st.push(root);
                    root = root->left;
                }
                else
                {
                    root = st.top();
                    st.pop();
                    vec.push_back(root->data);
                    root = root->right;
                }
            }
       }

       void magic_preorder_it(Node<T>* root,std::vector<T>& vec){
            std::stack<Node<T>*> st;
            while (root != nullptr || !st.empty())
            {
                if (root != nullptr)
                {
                    st.push(root);
                    vec.push_back(root->data);
                    root = root->left;
                }
                else
                {
                    root = st.top();
                    st.pop();
                    root = root->right;
                }
            }
       }

       void magic_postorder_it(Node<T>* root,std::vector<T>& vec){
            std::stack<Node<T>*> st;
            Node<T>* curr = root;
            while (true)
            {
                if (curr != nullptr)
                {
                    st.push(curr);
                    curr = curr->left;
                }
                else
                {
                    if (st.empty())
                    {
                        break;
                    }
                    curr = st.top()->right;
                    if (curr == nullptr)
                    {
                        Node<T>* last = nullptr;
                        while (!st.empty() && st.top()->right == last)
                        {
                            last = st.top();
                            st.pop();
                            vec.push_back(last->data);
                        }  
                    }
                } 
            }  
       }

    public:
        MyTree(){}
        
        MyTree(std::vector<T> elements){
            int n = elements.size();
            std::sort(elements.begin(), elements.end());
            root = sortedVectorToBST(elements, 0, n-1);
        }
   
        void insert(T key){
            // std::vector<T> vec = inorder_rec();
            // vec.push_back(key);
            // std::sort(vec.begin(), vec.end());
            root = magic_insert_key(root,key);
        }

        void insert(const Node<T> node){
            root = magic_insert_node(root,node);
        }

        const Node<T>* search(T key){
            return magic_search(root,key);
        }
        
        const Node<T>* delete_node(T key){
            return magic_delete_key(root,key);
        }

        const Node<T>* delete_node(const Node<T> node){
            return magic_delete_node(root,node);
        }

        bool isBST(){
            std::vector<T> vec;
            vec = inorder_rec();
            return std::is_sorted(vec.begin(),vec.end());
        }
        
        std::vector<T> inorder_rec(){
            std::vector<T> vec;
            magic_inorder_rec(root,vec);
            return vec;
        }
        
        std::vector<T> preorder_rec(){
            std::vector<T> vec;
            magic_preorder_rec(root,vec);
            return vec;
        }
        
        std::vector<T> postorder_rec(){
            std::vector<T> vec;
            magic_postorder_rec(root,vec);
            return vec;
        }
        
        std::vector<T> inorder_it(){
            std::vector<T> vec;
            magic_inorder_it(root,vec);
            return vec;
        }
        
        std::vector<T> preorder_it(){
            std::vector<T> vec;
            magic_preorder_it(root,vec);
            return vec;
        }
        
        std::vector<T> postorder_it(){
            std::vector<T> vec;
            magic_postorder_it(root,vec);
            return vec;
        }

        std::vector<T> breadth_traversal(){
            std::vector<T> vec;
            magic_breadth_traversal(root,vec);
            return vec;
        }

        int get_size(){
            std::vector<T> vec = inorder_rec();
            return vec.size();
        }

        int get_height(){
            return magic_get_height(root);
        }

        void clear(){
            magic_clear(root);
            root = nullptr;
        }

        ~MyTree(){
            clear();
        }
};

#endif