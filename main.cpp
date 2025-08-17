#include<iostream>
#include "pile.hpp"
int main()
{
    stack<long> myStack;
    char c;
    long data;

    while(true)
    {
        std::cout<<"i = inserer donnee"<<"\n";
        std::cout<<"e = enlever donner"<<"\n";
        std::cout<<"a = afficher pile"<<"\n";
        std::cout<<"t = obtenir la taille de la pile"<<"\n";
        std::cout<<"v = vider la pile"<<"\n";
        std::cout<<"f = fin du processus"<<"\n";
        std::cout<<"Quelle operation souhaitez vous effectuer?: ";
        std::cin>>c;

        switch (c)
        {
        case 'i':
        case 'I':
            if(!myStack.isFull())
            {
                std::cout<<"Entrez la donnee a inserer: ";
                std::cin>>data;
                myStack.push(data);
            }
            else
                std::cout<<"La pile est pleine"<<"\n";
            break;
        
        case 'e':
        case 'E':
            if(!myStack.isEmpty())
            {
                myStack.pop(data);
                std::cout<<data<<" a ete enlevee de la pile"<<"\n";
            }
            else
                std::cout<<"La pile est vide"<<"\n";
            break;
        
        case 'a':
        case 'A':
            myStack.display();
            break;
        
        case 't':
        case 'T':
            std::cout<<"Taille actuelle de la pile: "<<myStack.getSize()<<"\n";
            break;
        
        case 'v':
        case 'V':
            myStack.clear();
            break;
        
        case 'f':
        case 'F':
            std::cout<<"Fin du processus"<<"\n";
            return 0;

        default:
            std::cout<<"Commande eronnee"<<"\n";
        }
    }
}