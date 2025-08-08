#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "pile.h"

void initialize(stack** myStack)
{
    *myStack = malloc(sizeof(**myStack));
    assert(*myStack != NULL);
    (*myStack)->first = NULL;
    (*myStack)->size = 0;
}
void push(stack* myStack, const int data)
{
    node* newNode = malloc(sizeof(*newNode));

    assert(myStack != NULL && newNode != NULL);

    newNode->val = data;
    newNode->next = myStack->first;
    myStack->first = newNode;
    (myStack->size)++;
}

int pop(stack* myStack)
{
    if(myStack != NULL && myStack->first != NULL)
    {
        node* temp = myStack->first;
        myStack->first = temp->next;
        (myStack->size)--;
        free(temp);
        return 1;
    }

    return 0;
}

void displayStack(stack* myStack)
{
    assert(myStack != NULL);
    node* actual = myStack->first;

    while(actual != NULL)
    {
       printf("%d -> ", actual->val);
       actual = actual->next;
    }

    printf("NULL\n");
}

size_t getSize(stack* myStack)
{
    assert(myStack != NULL);
    return myStack->size;
}
void clear(stack* myStack)
{
    assert(myStack != NULL);

    while(myStack->first != NULL)
        pop(myStack);
}
void freeAll(stack* myStack)
{
    clear(myStack);
    free(myStack);
}