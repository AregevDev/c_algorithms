//
// Created by AregevDev on 11/18/2020.
//

#ifndef C_ALGORITHMS_STACK_H
#define C_ALGORITHMS_STACK_H

#include <stdlib.h>

/// Holds the Stack's data, change depending on the exercise.
typedef struct StackItem
{
    int x;
} StackItem;

/// Stack implementation using a dynamic array.
typedef struct Stack
{
    int top;
    int size;
    StackItem* array;
} Stack;

/// Creates an empty stack with a given size.
/// @param size the size of the stack.
/// @return pointer to the created stack.
Stack* stack_create(int size)
{
    Stack* s = malloc(sizeof(Stack));
    s->top = -1;
    s->size = size;
    s->array = (StackItem*) calloc(size, sizeof(StackItem));

    return s;
}

/// Frees the stacks' storage
void stack_destroy(Stack* stack)
{
    free(stack->array);
    free(stack);
}

/// Checks if the stack is empty.
/// @param stack
int stack_is_empty(Stack* stack)
{
    return stack->top == -1;
}

/// Pushes a new element to the stack.
/// @param stack
void stack_push(Stack* stack, StackItem item)
{
    if (stack->top != stack->size - 1)
    {
        *(stack->array + ++stack->top) = item;
    }
}

/// Removes (Pops) an element from the stack.
/// @param stack
/// @return the removed element from the stack.
StackItem* stack_pop(Stack* stack)
{
    if (!stack_is_empty(stack))
        return stack->array + stack->top--;

    return NULL;
}

/// Peeks the stack.
/// @param stack
/// @return the element in the head of the stack.
StackItem* stack_peek(Stack* stack)
{
    if (!stack_is_empty(stack))
        return stack->array + stack->top;

    return NULL;
}

/// Prints the stack's contents
void stack_print(Stack* stack)
{
    printf("[");
    for (int i = 0; i < stack->size; i++)
    {
        if (i == stack->size - 1)
            printf("%d", stack->array[i].x);
        else
            printf("%d, ", stack->array[i].x);
    }

    printf("]\n");
}

#endif //C_ALGORITHMS_STACK_H
