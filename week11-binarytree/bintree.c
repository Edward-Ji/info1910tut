#include "bintree.h"

void bt_node_init(bt_node *node, char elem) {
    node->elem = elem;
    node->left_child = NULL;
    node->right_child = NULL;
}

void bt_node_setl(bt_node *parent, bt_node *child) {
    parent->left_child = child;
}

void bt_node_setr(bt_node *parent, bt_node *child) {
    parent->right_child = child;
}

int bt_size(bt_node *node) {
    if (node == NULL) {
        return 0;
    }
    return bt_size(node->left_child) + bt_size(node->right_child) + 1;
}

int bt_depth(bt_node *node) {
    if (node == NULL) {
        return -1;
    }
    int depthl = bt_depth(node->left_child);
    int depthr = bt_depth(node->right_child);
    return (depthl > depthr? depthl : depthr) + 1;
}

int bt_max_layer_size(int depth) {
    if (depth <= 0) {
        return 1;
    }
    return 2 * bt_max_layer_size(depth - 1);
}
