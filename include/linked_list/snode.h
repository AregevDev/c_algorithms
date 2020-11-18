//
// Created by AregevDev on 11/18/2020.
//

#ifndef C_ALGORITHMS_SNODE_H
#define C_ALGORITHMS_SNODE_H

#include <stdlib.h>

/// Holds the Node's data, change depending on the exercise.
typedef struct SNodeItem
{
    int x;
} SNodeItem;

/// Node of a Singly Linked List.
typedef struct SNode
{
    SNodeItem data;
    struct SNode* next;
} SNode;

/// Creates a new node.
/// @param data the node's data.
/// @return the newly created node.
SNode* snode_create(SNodeItem data)
{
    SNode* n = (SNode*) malloc(sizeof(SNode));
    n->data = data;
    n->next = NULL;

    return n;
}

/// Frees the entire list.
/// @param node the head of the list.
void snode_destroy(SNode* node)
{
    SNode* temp;

    while (node != NULL)
    {
        temp = node;
        node = node->next;
        free(temp);
    }
}

/// Pushes a new node at the end of the list.
/// @param node pointer to the head of the list.
/// @param data the item to push.
void snode_push_back(SNode** node, SNodeItem data)
{
    SNode* n = snode_create(data);
    SNode* last = *node;

    if (*node == NULL)
    {
        *node = n;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = n;
}

/// Pushes a new node at the beginning of the list, replacing the head.
/// @param node pointer to the head of the list.
/// @param data the item to push.
void snode_push_front(SNode** node, SNodeItem data)
{
    SNode* n = snode_create(data);
    n->next = *node;
    *node = n;
}

/// Appends a new node after a specific node in the list.
/// @param node the previous node.
/// @param data the item to append.
void snode_append_after(SNode* node, SNodeItem data)
{
    if (node == NULL)
        return;

    SNode* n = snode_create(data);
    node->next = n;
}

/// Prints the entire list to stdout.
/// This function should change depending on the NodeItem.
/// @param node the head of the list.
void snode_print(SNode* node)
{
    printf("[");
    while (node != NULL)
    {
        if (node->next == NULL)
            printf("%d", node->data.x);
        else
            printf("%d, ", node->data.x);

        node = node->next;
    }

    printf("]\n");
}

#endif //C_ALGORITHMS_SNODE_H
