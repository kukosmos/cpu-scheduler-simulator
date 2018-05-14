#ifndef __SJF_H
#define __SJF_H

#include "../process.h"

struct __sjf_tree_node {
    Process * p;

    struct __sjf_tree_node * parent;
    struct __sjf_tree_node * left;
    struct __sjf_tree_node * right;
};

typedef struct __sjf_tree_node sjf_node_t;

#endif
