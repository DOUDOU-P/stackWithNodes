#ifndef PILE_H_INCLUDED
    #define PILE_H_INCLUDED
    
    typedef struct node node;
    struct node
    {
        int val;
        node* next;
    };

    typedef struct stack stack;
    struct stack
    {
       node* first;
       size_t size;
    };
    void initialize(stack** myStack);
    void push(stack*, const int);
    void displayStack(stack*);
    int pop(stack*);
    size_t getSize(stack*);
    void clear(stack*);

#endif
