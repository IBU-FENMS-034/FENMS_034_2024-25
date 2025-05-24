//
// Created by aldin on 13/02/2025.
//

#pragma once

template<typename Key, typename Value>
RedBlackTree<Key, Value>::~RedBlackTree() {
    delete_tree(root);
}

template<typename Key, typename Value>
void RedBlackTree<Key, Value>::delete_tree(Node<Key, Value> *x) {
    if (x != nullptr) {
        delete_tree(x->left);
        delete_tree(x->right);
        delete x;
    }
}

template<typename Key, typename Value>
RedBlackTree<Key, Value>::RedBlackTree(std::initializer_list<std::pair<Key, Value> > list) {
    for (auto it = list.begin(); it != list.end(); it++) {
        put(it->first, it->second);
    }
}

template<typename Key, typename Value>
RedBlackTree<Key, Value>::RedBlackTree(const RedBlackTree<Key, Value> &src) {
    root = copy_tree(src.root);
}

template<typename Key, typename Value>
RedBlackTree<Key, Value> &RedBlackTree<Key, Value>::operator=(const RedBlackTree<Key, Value> &src) {
    if (this != &src) {
        delete_tree(root);
        root = copy_tree(src.root);
    }
    return *this;
}

template<typename Key, typename Value>
Node<Key, Value>* RedBlackTree<Key, Value>::copy_tree(Node<Key, Value> *x) {
    if (x == nullptr) {
        return nullptr;
    }

    Node<Key, Value> *t = new Node<Key, Value>(x->key, x->value, x->color);
    t->left = copy_tree(x->left);
    t->right = copy_tree(x->right);
    t->size = x->size;

    return t;
}

template<typename Key, typename Value>
RedBlackTree<Key, Value>::RedBlackTree(RedBlackTree<Key, Value> &&src) noexcept {
    root = src.root;
    src.root = nullptr;
}

template<typename Key, typename Value>
RedBlackTree<Key, Value> &RedBlackTree<Key, Value>::operator=(RedBlackTree<Key, Value> &&src) noexcept {
    if (this != &src) {
        delete_tree(root);
        root = src.root;
        src.root = nullptr;
    }
    return *this;
}

template<typename Key, typename Value>
Value RedBlackTree<Key, Value>::get(Key key) {
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
int RedBlackTree<Key, Value>::size() const {
    return size(root);
}

template<typename Key, typename Value>
int RedBlackTree<Key, Value>::size(Node<Key, Value> *x) const {
    if (x == nullptr) {
        return 0;
    }
    return x->size;
}

template<typename Key, typename Value>
Node<Key, Value> *RedBlackTree<Key, Value>::rotate_left(Node<Key, Value> *h) {
    Node<Key, Value>* x = h->right;
    h->right = x->left;
    x->left = h;
    x->color = h->color;
    h->color = RED;
    h->size = 1 + size(h->left) + size(h->right);
    return x;
}

template<typename Key, typename Value>
Node<Key, Value> *RedBlackTree<Key, Value>::rotate_right(Node<Key, Value> *h) {
    Node<Key, Value>* x = h->left;
    h->left = x->right;
    x->right = h;
    x->color = h->color;
    h->color = RED;
    h->size = 1 + size(h->left) + size(h->right);
    return x;
}

template<typename Key, typename Value>
void RedBlackTree<Key, Value>::flip_colors(Node<Key, Value> *h) {
    h->color = !h->color;
    h->right->color = !h->right->color;
    h->left->color = !h->left->color;
}


template<typename Key, typename Value>
bool RedBlackTree<Key, Value>::is_red(Node<Key, Value> *x) const {
    if (x == nullptr) {
        return false;
    }
    return x->color == RED;
}

template<typename Key, typename Value>
void RedBlackTree<Key, Value>::put(Key key, Value value) {
    root = put(root, key, value);
    root->color = BLACK;
}

template<typename Key, typename Value>
Node<Key, Value> *RedBlackTree<Key, Value>::put(Node<Key, Value> *x, Key key, Value value) {
    if (x == nullptr) {
        return new Node<Key, Value>(key, value, RED);
    }

    if (key < x->key) {
        x->left = put(x->left, key, value);
    } else if (key > x->key) {
        x->right = put(x->right, key, value);
    } else {
        x->value = value;
    }

    // Color balancing
    if (is_red(x->right) && !is_red(x->left)) {
        x = rotate_left(x);
    }
    if (is_red(x->left) && is_red(x->left->left)) {
        x = rotate_right(x);
    }
    if (is_red(x->right) && is_red(x->left)) {
        flip_colors(x);
    }

    x->size = 1 + size(x->left) + size(x->right);
    return x;
}

template<typename Key, typename Value>
Node<Key, Value> *RedBlackTree<Key, Value>::fix_up(Node<Key, Value>* h) {
    if (is_red(h->right) && !is_red(h->left)) {
        h = rotate_left(h);
    }
    if (is_red(h->left) && is_red(h->left->left)) {
        h = rotate_right(h);
    }
    if (is_red(h->right) && is_red(h->left)) {
        flip_colors(h);
    }

    h->size = 1 + size(h->left) + size(h->right);
    return h;
}

template<typename Key, typename Value>
Key RedBlackTree<Key, Value>::find_min() {
    return find_min(root)->key;
}

template<typename Key, typename Value>
Node<Key, Value> *RedBlackTree<Key, Value>::find_min(Node<Key, Value> *x) {
    if (x->left == nullptr) {
        return x;
    }
    return find_min(x->left);
}

template<typename Key, typename Value>
Node<Key, Value> *RedBlackTree<Key, Value>::move_red_left(Node<Key, Value> *h) {
    flip_colors(h);
    if (is_red(h->right->left)) {
        h->right = rotate_right(h->right);
        h = rotate_left(h);
        flip_colors(h);
    }
    return h;
}

template<typename Key, typename Value>
Node<Key, Value> *RedBlackTree<Key, Value>::move_red_right(Node<Key, Value> *h) {
    flip_colors(h);
    if (is_red(h->left->left)) {
        h = rotate_right(h);
        flip_colors(h);
    }
    return h;
}

template<typename Key, typename Value>
void RedBlackTree<Key, Value>::delete_min() {
    root = delete_min(root);
    root->color = BLACK;
}

template<typename Key, typename Value>
Node<Key, Value> *RedBlackTree<Key, Value>::delete_min(Node<Key, Value> *h) {
    if (h->left == nullptr) {
        delete h;
        return nullptr;
    }

    if (!is_red(h->left) && !is_red(h->left->left)) {
        h = move_red_left(h);
    }

    h->left = delete_min(h->left);

    return fix_up(h);
}

template<typename Key, typename Value>
void RedBlackTree<Key, Value>::delete_any(Key key) {
    root = delete_any(root, key);
    root->color = BLACK;
}

template<typename Key, typename Value>
Node<Key, Value> *RedBlackTree<Key, Value>::delete_any(Node<Key, Value> *h, Key key) {
    if (h == nullptr) {
        return nullptr;
    }

    if (key < h->key) {
        if (!is_red(h->left) && !is_red(h->left->left)) {
            h = move_red_left(h);
        }
        h->left = delete_any(h->left, key);
    } else {
        if (is_red(h->left)) {
            h = rotate_right(h);
        }
        if (key == h->key && h->right == nullptr) {
            delete h;
            return nullptr;
        }
        if (!is_red(h->right) && !is_red(h->right->left)) {
            h = move_red_right(h);
        }
        if (key == h->key) {
            Node<Key, Value>* min = find_min(h->right);
            h->key = min->key;
            h->value = min->value;
            h->right = delete_min(h->right);
        } else {
            h->right = delete_any(h->right, key);
        }
    }
    return fix_up(h);
}



