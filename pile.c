#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "pile.h"

void initialize(stack** myStack)
{
    *myStack = malloc(sizeof(*myStack));
    (*myStack)->first = NULL;
    (*myStack)->size = 0;
}
void push(stack* myStack, const int data)
{
    node* new = malloc(sizeof(*new));

    assert(myStack != NULL && new != NULL);

    new->val = data;
    new->next = myStack->first;
    myStack->first = new;
    (myStack->size)++;
}

int pop(stack* myStack)
{
    int pValue = EOF;
    if(myStack != NULL && myStack->first != NULL)
    {
        node* temp = myStack->first;
        pValue = temp->val;
        myStack->first = temp->next;
        (myStack->size)--;
        free(temp);
    }

    return pValue;
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

    if(myStack->first != NULL)
    {
        pop(myStack);
        clear(myStack);
    }
}