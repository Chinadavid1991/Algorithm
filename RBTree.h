//
// Created by feng on 2020/12/21.
//

#ifndef ALGORITHM___RBTREE_H
#define ALGORITHM___RBTREE_H
#include <iostream>
template <typename K,typename V>
class RBTree {
    struct Node{
        K key;
        V value;
        Node* left;
        Node* right;
        bool color;

        Node(K key, V value, Node *left = nullptr, Node *right = nullptr, bool color = _red) :
                        key(key), value(value), left(left), right(right),color(color) {}
    };

public:
    RBTree() : N(0), _root(nullptr) {}

    void insert(const K& key, const V& value){
        _root = insert(_root,key,value);
        _root->color = _black;
    }

    bool isBalance() {
        return isBalance(_root);
    }

private:
    /*
     * 右旋
     */
    Node* rotaRight(Node* h){
        Node* x = h->left;
        h->left = x->right;
        x->right = h;
        x->color = h->color;
        h->color = _red;
        return x;
    }
    /*
     * 左旋
     */
    Node* rotaLeft(Node* h){
        Node* x = h->right;
        h->right = x->left;
        x->left = h;
        x->color = h->color;
        h->color = _red;
        return x;

    }
    /*
     * 颜色反转
     */
    void colorFlip(Node* h){
        h->color = _red;
        h->left->color = _black;
        h->right->color = _black;
    }
    /*
     *插入
     */
    Node* insert(Node* node,const K& key, const V& value){
        if(nullptr == node){
            node = new Node(key,value);
            ++N;
            return node;
        }
        if(key < node->key){
            node->left = insert(node->left,key,value);
        }
        else if (key > node->key){
            node->right = insert(node->right,key,value);
        }
        else{
            node->value = value;
            return node;
        }
        //先左旋
        if(!isRed(node->left) && isRed(node->right)){
            node = rotaLeft(node);
        }

        //再右旋
        if(isRed(node->left) && isRed(node->left->left)){
            node = rotaRight(node);
        }
        //最后颜色翻转
        if(isRed(node->left) && isRed(node->right)){
            colorFlip(node);
        }

        return node;
    }
    bool isRed(Node* h){
        return h && h->color;
    }
    bool isBalance(Node* node){
        if(node == nullptr){
            return true;
        }
        if(isRed(node->right) || (isRed(node) && (isRed(node->left)))){
            return false;
        }

        return isBalance(node->left) && isBalance(node->right);

    }

private:
    static const bool _black = false;
    static const bool _red = true;
    size_t N;
    Node* _root;

};


#endif //ALGORITHM___RBTREE_H
