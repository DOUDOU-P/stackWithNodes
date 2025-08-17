#ifndef PILE_HPP_INCLUDED
    #define PILE_HPP_INCLUDED

    #include "noeud.hpp"

    template<typename unType>
    class stack
    {
        private:
            node<unType>* first;
            size_t size;
        
        public:
            stack(const stack&) = delete;
            stack& operator=(const stack&) = delete;

            stack()
            {
                first = nullptr;
                size = 0;
            }
            stack(stack&& other)
            {
                this->first = other.first;
                this->size = other.size;
                other.first = nullptr;
                other.size = 0;
            }
            stack& operator=(stack&& other)
            {
                clear(); // Pour éviter les fuites de mémoire
                this->first = other.first;
                this->size = other.size;
                other.first = nullptr;
                other.size = 0;
                return *this;
            }
            ~stack()
            {
                clear();
            }

            bool isEmpty() const
            {
                return first == nullptr;
            }

            bool isFull() const
            {
                return false;
            }

            size_t getSize() const
            {
                return this->size;
            }

            void push(unType data)
            {
                node<unType>* newNode = new node<unType>(data, first);
                first = newNode;
                size++;
            }

            bool pop(unType& data)
            {
                if(!isEmpty())
                {
                    data = first->getValue();
                    node<unType>* element = first;
                    first = first->getNext();
                    size--;
                    delete element;
                    return true;
                }

                return false;
            }

            bool getTop(unType& data) const
            {
                if(!isEmpty())
                {
                    data = first->getValue();
                    return true;
                }
                return false;
            }

            void display() const
            {
                node<unType>* cursor = first;
                while(cursor != nullptr)
                {
                    std::cout<<cursor->getValue()<<" -> ";
                    cursor = cursor->getNext();
                }

                std::cout<<"NULL\n";
            }

            void clear()
            {
                while(!isEmpty())
                {
                    unType data;
                    pop(data);
                }
            }

    };

#endif