//
// Created by feng on 2020/12/17.
//

#ifndef ALGORITHM___BINARYTREE_H
#define ALGORITHM___BINARYTREE_H

#include <string>
#include <vector>
#include <ostream>
#include <deque>

template<class K, class V>
class BinaryTree {
    struct Node {
        K key;
        V value;
        Node *left;
        Node *right;

        Node(const K &k, const V &v, Node *left = nullptr, Node *right = nullptr) :
                key(k), value(v), left(left), right(right) {}
    };

    using v_ptr = Node *;
public:
    BinaryTree() : _root(nullptr), N(0) {}

    void insert(const K &key, const V &value) {
        _root = insert(_root, key, value);
    }

    v_ptr get(const K &key) const {
        return get(_root, key);
    }

    void remove(const K &key) {
        _root = remove(_root, key);
    }

    void preOrder(std::vector<K> &vec) const {
        preOrder(_root, vec);
    }

    void midOrder(std::vector<K> &vec) const {
        midOrder(_root, vec);
    }

    void backOrder(std::vector<K> &vec) const {
        backOrder(_root, vec);
    }

    void layerOrder(std::vector<K> &vec) const {
        std::deque<v_ptr> que;
        que.push_front(_root);
        layerOrder(que, vec);
    }

    friend std::ostream &operator<<(std::ostream &os, const BinaryTree &tree) {
        std::vector<K> vec;
        tree.midOrder(vec);
        for (size_t i = 0; i < vec.size(); ++i) {
            if (i == 0 && i == vec.size() - 1) {
                os << "[" << vec[i] << "]";
            }
            else if (i == 0 && i != vec.size() - 1) {
                os << "[" << vec[i] << ",";
            }
            else if (i > 0 && i < vec.size() - 1) {
                os << vec[i] << ",";
            }
            else {
                os << vec[i] << "]";
            }

        }
        return os;
    }

    v_ptr parent(const K &key) const {
        return parent(_root, key);
    }

    v_ptr min() {
        if (_root) {
            return min(_root);
        }
        return nullptr;
    }

    v_ptr max() {
        if (_root) {
            return max(_root);
        }
        return nullptr;
    }

    int maxDepth(){
        return maxDepth(_root);
    }
    v_ptr root() const { return _root; }

    size_t size() const { return N; }

private:
    /*
     插入节点:查找到根节点,增加新节点
     */
    v_ptr insert(v_ptr node, const K &key, const V &value) {
        if (node == nullptr)//只有node == null会改变node值
        {
            node = new Node(key, value);
            ++N;
            return node;
        }
        if (key < node->key) {
            node->left = insert(node->left, key, value);
        }
        else if (key > node->key) {
            node->right = insert(node->right, key, value);
        }
        else {
            node->value = value;
        }
        return node;
    }

    /*
     *获取节点:查找键对应的值
     */
    v_ptr get(v_ptr node, const K &key) const {
        if (nullptr == node) {
            return nullptr;
        }
        if (key < node->key) {
            node = get(node->left, key);
        }
        else if (key > node->key) {
            node = get(node->right, key);
        }
        return node;
    }

    /*
     * 删除节点:查找键对应的节点
     */

    v_ptr remove(v_ptr node, const K &key) {
        if (node == nullptr) return nullptr;
        //查找要删除的节点
        if (key < node->key) {
            node->left = remove(node->left, key);
        }
        else if (key > node->key) {
            node->right = remove(node->right, key);
        }
        else {

            v_ptr rp_node = nullptr;//替换的节点
            v_ptr lp_node = nullptr;//替换节点的父节点
            if (node->left == nullptr)//左侧节点为空
            {
                rp_node = node->right;
                delete node;
                node = rp_node;
            }
            else if (node->right == nullptr)//右侧节点为空
            {
                rp_node = node->left;
                delete node;
                node = rp_node;
            }
            else {
                --N;
                rp_node = node->right;
                //查找最左侧的节点
                while (rp_node->left != nullptr) {
                    if (rp_node->left->left == nullptr) {
                        lp_node = rp_node;
                    }
                    rp_node = rp_node->left;
                }
                //断开最左侧节点与父节点的连接
                if (lp_node) {
                    lp_node->left = rp_node->right;
                }
                //替换删除节点的左右连接
                rp_node->left = node->left;
                rp_node->right = node->right;
                delete node;
                node = rp_node;
            }
        }
        return node;
    }

    /*
     * 前序遍历:节点->左子节点->右子节点
     */
    void preOrder(v_ptr node, std::vector<K> &vec) const {
        if (nullptr == node) return;
        //放入节点的键
        vec.push_back(node->key);
        //递归左侧节点
        if (node->left != nullptr) {
            preOrder(node->left, vec);
        }

        if (node->right != nullptr) {
            preOrder(node->right, vec);
        }
    }

    /*
    * 中序遍历:左子节点->节点->右子节点
    */
    void midOrder(v_ptr node, std::vector<K> &vec) const {
        if (nullptr == node) return;
        //递归左侧节点
        if (node->left != nullptr) {
            midOrder(node->left, vec);
        }
        //放入节点的键
        vec.push_back(node->key);

        if (node->right != nullptr) {
            midOrder(node->right, vec);
        }
    }

    //后序遍历
    void backOrder(v_ptr node, std::vector<K> &vec) const {
        if (nullptr == node) return;
        //递归左侧节点
        if (node->left != nullptr) {
            backOrder(node->left, vec);
        }

        if (node->right != nullptr) {
            backOrder(node->right, vec);
        }
        //放入节点的键
        vec.push_back(node->key);
    }

    //层序遍历
    void layerOrder(std::deque<v_ptr> &que, std::vector<K> &vec) const {
        while (!que.empty()) {
            v_ptr node = que.back();
            que.pop_back();
            vec.push_back(node->key);
            if (node->left) {
                que.push_front(node->left);
            }
            if (node->right) {
                que.push_front(node->right);
            }
        }
    }

    v_ptr parent(v_ptr node, const K &key) const {
        if (nullptr == node || node->key == key) {
            return nullptr;
        }

        if (node->right && node->key < key)//子节点在当前节点的右侧
        {
            if (node->right->key == key) {
                return node;
            }
            else {
                node = parent(node->right, key);
            }
        }
        else if (node->left && node->key > key)//子节点在当前节点的左侧
        {
            if (node->left->key == key) {
                return node;
            }
            else {
                node = parent(node->left, key);
            }

        }
        else //子节点不存在
        {
            return nullptr;
        }
        return node;
    }

    v_ptr min(v_ptr node) {
        if (node->left) {
            node = min(node->left);
        }
        return node;
    }

    v_ptr max(v_ptr node) {
        if (node->right) {
            node = max(node->right);
        }
        return node;
    }
    int maxDepth(v_ptr node){
        if(!node){
            return 0;
        }
        int MaxL = maxDepth(node->left);
        int MaxR = maxDepth(node->right);
        return MaxL > MaxR ? MaxL + 1 : MaxR + 1;
    }
private:
    v_ptr _root;
    size_t N;
};

void testBinaryTree();

#endif //ALGORITHM___BINARYTREE_H
