#include<stdio.h>
#include<stdlib.h>
#include "pile.h"

int main(void)
{
   stack* myStack = NULL;
   initialize(&myStack);

   for(int i = 0; i < 5; i++)
   {
        printf("On empile %d\n", i);
        push(myStack, i);
   }

   printf("Affichage de la pile: ");
   displayStack(myStack);

   pop(myStack);
   pop(myStack);

   printf("Affichage de la pile: ");
   displayStack(myStack);

   printf("Taille de la pile: %ld\n", getSize(myStack));

   clear(myStack);

   displayStack(myStack);

   for(int i = 0; i < 5; i++)
   {
      printf("On empile %d\n", i);
      push(myStack, i);
   }

   freeAll(myStack);

   return 0;
}