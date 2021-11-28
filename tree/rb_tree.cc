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
  void       print(RBNode<T> *root) const;
  void       preOrder(RBNode<T> *root) const;
  void       inOrder(RBNode<T> *root) const;
  void       postOrder(RBNode<T> *root) const;

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
