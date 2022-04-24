#include <iomanip>

enum RBColor { BLACK, RED };

template <class KeyType>
struct RBNode {
  KeyType          key;
  RBColor          color;
  RBNode<KeyType> *left;
  RBNode<KeyType> *right;
  RBNode<KeyType> *parent;

  RBNode(KeyType key, RBColor color, RBNode *p, RBNode *l, RBNode *r)
      : key(key), color(color), parent(p), left(l), right(r) {
  }
};

template <typename T>
class RBTree {
public:
  RBTree();
  ~RBTree();

  void       insert(T key);  // 插入key
  void       remove(T key);  // 删除key
  RBNode<T> *search(T key);  // 查找key
  void       print();

  void preOrder();   // 先序遍历
  void inOrder();    // 中序遍历
  void postOrder();  // 后序遍历

private:
  void leftRotate(RBNode<T> *&root, RBNode<T> *node);   // 左旋
  void rightRotate(RBNode<T> *&root, RBNode<T> *node);  // 右旋

  void insert(RBNode<T> *&root, RBNode<T> *node);  // 插入节点
  void insertFixUp(RBNode<T> *&root, RBNode<T> *node);
  void destory(RBNode<T> *node);

  void remove(RBNode<T> *&root, RBNode<T> *node);
  void removeFixUp(RBNode<T> *&root, RBNode<T> *node, RBNode<T> *parent);

  RBNode<T> *search(RBNode<T> *root, T key) const;

  RBNode<T> *root;
};

template <typename T>
RBTree<T>::RBTree() : root(nullptr) {
}

template <typename T>
RBTree<T>::~RBTree() {
  destory(root);
}

// 左旋
template <typename T>
void RBTree<T>::leftRotate(RBNode<T> *&root, RBNode<T> *node) {
  // 将当前右子树的左子树，改为轴节点的右子树
  RBNode<T> *right = node->right;

  node->right = right->left;

  // 如果左子树不为空，设置其父节点为轴节点
  if (nullptr != right->left) {
    right->left->parent = node;
  }

  // 右子树节点的父节点为轴节点的父节点
  right->parent = node->parent;

  if (nullptr == node->parent) {
    root = right;
  } else {
    // 轴节点为父节点的左节点时，需要将轴节点的父节点的左子树设置为右节点
    if (node == node->parent->left) {
      node->parent->left = right;
    } else {
      // 轴节点为父节点的右子树时，需要将右节点链接到轴的父节点的右子树
      node->parent->right = right;
    }
  }

  // 将轴节点变为到右子树左节点
  right->left  = node;
  node->parent = right;  // 轴节点的父节点改为右子树
}

// 右旋
template <typename T>
void RBTree<T>::rightRotate(RBNode<T> *&root, RBNode<T> *node) {
  // 获取轴节点的左子树根节点，记为左节点
  RBNode<T> *left = node->left;
  // 左节点的右子树链接到轴节点的左侧，成为轴节点的左子树
  node->left = left->right;

  // 如果左节点的左子树不空，设置其父节点为轴节点
  if (nullptr != left->right) {
    left->right->parent = node;
  }

  // 处理轴节点的父节点与父节点的左右子树
  left->parent = node->parent;

  if (nullptr == node->parent) {
    root = left;
  } else {
    // 轴节点为其父节点的左子树时
    if (node == node->parent->left) {
      // 左节点链接到其左子树上
      node->parent->left = left;
    } else {
      node->parent->right = left;
    }
  }

  // 将轴节点的作为左节点的右子树链接
  left->right  = node;
  node->parent = left;
}

// 插入算法
template <typename T>
void RBTree<T>::insert(T key) {
  RBNode<T> *node = new RBNode<T>(key, RED, nullptr, nullptr, nullptr);
  insertFixUp(root, node);
}

template <typename T>
void RBTree<T>::insert(RBNode<T> *&root, RBNode<T> *node) {
  RBNode<T> *cur  = root;
  RBNode<T> *leaf = nullptr;

  // 查找叶子节点
  while (nullptr != cur) {
    leaf = cur;
    // 二叉搜索树的值的性质适用
    if (node->key > cur->key) {
      cur = cur->right;
    } else {
      cur = cur->left;
    }
  }

  node->parent = leaf;

  // 插入节点
  if (nullptr != leaf) {
    if (node->key > leaf->key) {
      leaf->right = node;
    } else {
      leaf->left = node;
    }
  } else {
    root = node;
  }

  node->color = RED;
  insertFixUp(root, node);
}

// 调整RB Tree
template <typename T>
void RBTree<T>::insertFixUp(RBNode<T> *&root, RBNode<T> *node) {
  RBNode<T> *parent = node->parent;

  while (node != RBTree::root && parent->color == RED) {
    RBNode<T> *gparent = parent->parent;

    if (parent == gparent->left) {  // 父节点为祖父节点的左子树
      RBNode<T> *uncle = gparent->right;  // 插入节点的叔父节点

      if (nullptr != uncle && uncle->color == RED) {
        parent->color  = BLACK;  // 父节点和叔父节点设置为黑色
        uncle->color   = BLACK;
        gparent->color = RED;      // 祖父节点设置为红色
        node           = gparent;  // 向上递归
        parent         = node->parent;
      } else {
        // 如果插入节点为右节点
        if (node == parent->right) {
          // 以parent为轴，左旋
          leftRotate(root, parent);
          swap(node, parent);  // 交换当前节点和轴节点
        }

        // 以祖父节点为轴右旋
        rightRotate(root, gparent);
        gparent->color = BLACK;
        parent->color  = RED;
        break;
      }
    } else {
      RBNode<T> *uncle = gparent->left;

      if (nullptr != uncle && RED == uncle->color) {
        gparent->color = RED;
        parent->color  = BLACK;
        uncle->color   = BLACK;

        node    = parent;
        gparent = parent->parent;
      } else {
        if (node == parent->left) {
          rightRotate(root, parent);
          swap(node, parent);
        }

        leftRotate(root, gparent);
        parent->color  = BLACK;
        gparent->color = RED;
        break;
      }
    }
  }

  root->color = BLACK;
}

// 销毁红黑树
template <typename T>
void RBTree<T>::destory(RBNode<T> *root) {
  if (nullptr == root) {
    return;
  }

  destory(root->left);
  destory(root->right);

  delete root;
  root = nullptr;
}

// 红黑树删除
template <typename T>
void RBTree<T>::remove(T key) {
  RBNode<T> *deletenode = search(key);

  if (nullptr != deletenode) {
    remove(root, deletenode);
  }
}

template <typename T>
void RBTree<T>::remove(RBNode<T> *&root, RBNode<T> *node) {
  RBNode<T> *child, *parent;
  RBColor    color;

  // 被删除节点为非叶子结点
  if (nullptr != node->left && nullptr != node->right) {
    RBNode<T> *replace = node;

    // 查找后继节点，右子树的最左节点
    replace = node->right;
    while (replace->left) {
      replace = replace->left;
    }

    // 被删节点不为根节点的情况
    if (nullptr != node->parent) {
      if (node == node->parent->left) {
        node->parent->left = replace;
      } else {
        node->parent->right = replace;
      }
    } else {
      // 根节点的情况
      root = replace;
    }

    // child是后续节点的右节点，是需要调整的节点
    // replace是后继节点，不可能存在左节点
    //同理前驱节点不可能存在右节点
    child  = replace->right;
    parent = replace->parent;
    color  = replace->color;

    // 被删节点时取代节点的父节点的情况
    if (node == parent) {
      parent = replace;
    } else {
      // child节点存在的情况
      if (nullptr != child) {
        child->parent = parent;
      }

      parent->left        = child;
      replace->right      = node->right;
      node->right->parent = replace;
    }

    replace->parent    = node->parent;
    replace->color     = node->color;
    replace->parent    = node->parent;
    node->left->parent = replace;

    if (BLACK == color) {
      removeFixUp(root, replace, parent);
    }

    delete node;
    return;
  }

  // 被删除节点只有左节点的情况，找到被删除节点的子节点
  if (nullptr != node->left) {
    child = node->left;
  } else {
    child = node->right;
  }

  parent = node->parent;
  color  = node->color;

  if (child) {
    child->parent = parent;
  }

  // 被删除节点不为根节点
  if (nullptr != parent) {
    if (parent->left == node) {
      parent->left = child;
    } else {
      parent->right = child;
    }
  } else {
    RBTree::root = child;
  }

  if (BLACK == color) {
    removeFixUp(root, child, parent);
  }

  return;
}

template <typename T>
void RBTree<T>::removeFixUp(RBNode<T> *&root,
                            RBNode<T>  *node,
                            RBNode<T>  *parent) {
  RBNode<T> *othernode;
  while (!node || BLACK == node->color && RBTree::root != node) {
    if (node == parent->left) {
      othernode = parent->right;
      if (RED == othernode->color) {
        othernode->color = BLACK;
        parent->color    = RED;
        leftRotate(root, parent);
        othernode = parent->right;
      } else {
        if (!othernode->right || BLACK == othernode->right->color) {
          othernode->left->color = BLACK;
          othernode->color       = RED;
          rightRotate(root, othernode);
          othernode = parent->right;
        }

        othernode->color        = parent->color;
        parent->color           = BLACK;
        othernode->right->color = BLACK;
        leftRotate(root, parent);
        node = root;
        break;
      }
    } else {
      othernode = parent->left;
      if (RED == othernode->color) {
        othernode->color = BLACK;
        parent->color    = RED;
        rightRotate(root, parent);
        othernode = parent->left;
      }

      if ((!othernode->left || BLACK == othernode->left->color) &&
          (!othernode->right || BLACK == othernode->right->color)) {
        othernode->color = RED;
        node             = parent;
        parent           = node->parent;
      } else {
        if (!othernode->left || othernode->left->color == BLACK) {
          othernode->right->color = BLACK;
          othernode->color        = RED;
          leftRotate(root, othernode);
          othernode = parent->left;
        }

        othernode->color       = parent->color;
        parent->color          = BLACK;
        othernode->left->color = BLACK;
        rightRotate(root, parent);
        node = root;
        break;
      }
    }
  }

  if (node) {
    node->color = BLACK;
  }
}

template <typename T>
RBNode<T> *RBTree<T>::search(T key) {
  return search(root, key);
}

template <typename T>
RBNode<T> *RBTree<T>::search(RBNode<T> *root, T key) const {
  if (nullptr == root || root->key == key) {
    return root;
  }

  if (root->key < key) {
    return search(root->right, key);
  } else {
    return search(root->left, key);
  }
}
