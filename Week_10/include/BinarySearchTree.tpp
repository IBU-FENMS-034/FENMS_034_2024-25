//
// Created by aldin on 12/02/2025.
//

#pragma once

template<typename Key, typename Value>
BinarySearchTree<Key, Value>::~BinarySearchTree() {
    delete_tree(root);
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::delete_tree(Node<Key, Value> *x) {
    if (x != nullptr) {
        delete_tree(x->left);
        delete_tree(x->right);
        delete x;
    }
}

template<typename Key, typename Value>
BinarySearchTree<Key, Value>::BinarySearchTree(const BinarySearchTree<Key, Value> &src) {
    root = copy_tree(src.root);
}

template<typename Key, typename Value>
BinarySearchTree<Key, Value> &BinarySearchTree<Key, Value>::operator=(const BinarySearchTree<Key, Value> &src) {
    if (this != &src) {
        delete_tree(root);
        root = copy_tree(src.root);
    }
    return *this;
}

template<typename Key, typename Value>
Node<Key, Value>* BinarySearchTree<Key, Value>::copy_tree(Node<Key, Value> *x) {
    if (x == nullptr) {
        return nullptr;
    }

    Node<Key, Value> *t = new Node<Key, Value>(x->key, x->value);
    t->left = copy_tree(x->left);
    t->right = copy_tree(x->right);
    t->size = x->size;

    return t;
}

template<typename Key, typename Value>
BinarySearchTree<Key, Value>::BinarySearchTree(BinarySearchTree<Key, Value> &&src) noexcept {
    root = src.root;
    src.root = nullptr;
}

template<typename Key, typename Value>
BinarySearchTree<Key, Value> &BinarySearchTree<Key, Value>::operator=(BinarySearchTree<Key, Value> &&src) noexcept {
    if (this != &src) {
        delete_tree(root);
        root = src.root;
        src.root = nullptr;
    }
    return *this;
}

template<typename Key, typename Value>
BinarySearchTree<Key, Value>::BinarySearchTree(std::initializer_list<std::pair<Key, Value> > list) {
    for (auto it = list.begin(); it != list.end(); it++) {
        put(it->first, it->second);
    }
}

template<typename Key, typename Value>
Value BinarySearchTree<Key, Value>::get(Key key) {
    Node<Key, Value>* x = root;

    while (x != nullptr) {
        if (key < x->key) {
            x = x->left;
        } else if (key > x->key) {
            x = x->right;
        } else {
            return x->value;
        }
    }
    return Value{};
}

template<typename Key, typename Value>
int BinarySearchTree<Key, Value>::size() const {
    return size(root);
}

template<typename Key, typename Value>
int BinarySearchTree<Key, Value>::size(Node<Key, Value> *x) const {
    if (x == nullptr) {
        return 0;
    }
    return x->size;
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::put(Key key, Value value) {
    root = put(root, key, value);
}

template<typename Key, typename Value>
Node<Key, Value> *BinarySearchTree<Key, Value>::put(Node<Key, Value> *x, Key key, Value value) {
    if (x == nullptr) {
        return new Node<Key, Value>(key, value);
    }

    if (key < x->key) {
        x->left = put(x->left, key, value);
    } else if (key > x->key) {
        x->right = put(x->right, key, value);
    } else {
        x->value = value;
    }

    x->size = 1 + size(x->left) + size(x->right);
    return x;
}

template<typename Key, typename Value>
Key BinarySearchTree<Key, Value>::find_min() {
    return find_min(root)->key;
}

template<typename Key, typename Value>
Node<Key, Value> *BinarySearchTree<Key, Value>::find_min(Node<Key, Value> *x) {
    if (x->left == nullptr) {
        return x;
    }
    return find_min(x->left);
}

template<typename Key, typename Value>
Key BinarySearchTree<Key, Value>::find_max() {
    return find_max(root)->key;
}

template<typename Key, typename Value>
Node<Key, Value> *BinarySearchTree<Key, Value>::find_max(Node<Key, Value> *x) {
    if (x->right == nullptr) {
        return x;
    }
    return find_max(x->right);
}

template<typename Key, typename Value>
int BinarySearchTree<Key, Value>::rank(Key key) {
    return rank(root, key);
}

template<typename Key, typename Value>
int BinarySearchTree<Key, Value>::rank(Node<Key, Value> *x, Key key) {
    if (x == nullptr) {
        return 0;
    }
    if (key < x->key) {
        return rank(x->left, key);
    } else if (key > x->key) {
        return 1 + size(x->left) + rank(x->right, key);
    } else {
        return size(x->left);
    }
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::delete_min() {
    root = delete_min(root);
}

template<typename Key, typename Value>
Node<Key, Value> *BinarySearchTree<Key, Value>::delete_min(Node<Key, Value> *x) {
    if (x->left == nullptr) {
        Node<Key, Value>* t = x->right;
        delete x;
        return t;
    }

    x->left = delete_min(x->left);
    x->size = 1 + size(x->left) + size(x->right);

    return x;
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::delete_any(Key key) {
    root = delete_any(root, key);
}

template<typename Key, typename Value>
Node<Key, Value> *BinarySearchTree<Key, Value>::delete_any(Node<Key, Value> *x, Key key) {
    if (x == nullptr) {
        return nullptr;
    }

    if (key < x->key) {
        x->left = delete_any(x->left, key);
    } else if (key > x->key) {
        x->right = delete_any(x->right, key);
    } else {
        if (x->left == nullptr) {
            Node<Key, Value>* t = x->right;
            delete x;
            return t;
        }
        if (x->right == nullptr) {
            Node<Key, Value>* t = x->left;
            delete x;
            return t;
        }

        Node<Key, Value>* t = find_min(x->right);
        x->key = t->key;
        x->value = t->value;
        x->right = delete_min(x->right);
    }
    x->size = 1 + size(x->left) + size(x->right);
    return x;
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::inorder() {
    inorder(root);
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::inorder(Node<Key, Value> *x) {
    if (x != nullptr) {
        inorder(x->left);
        std::cout << x->key << " ";
        inorder(x->right);
    }
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::preorder() {
    preorder(root);
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::preorder(Node<Key, Value> *x) {
    if (x != nullptr) {
        std::cout << x->key << " ";
        preorder(x->left);
        preorder(x->right);
    }
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::postorder() {
    postorder(root);
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::postorder(Node<Key, Value> *x) {
    if (x != nullptr) {
        postorder(x->left);
        postorder(x->right);
        std::cout << x->key << " ";
    }
}









