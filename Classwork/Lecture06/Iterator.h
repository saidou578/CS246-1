#ifndef ITERATOR_H
#define ITERATOR_H

#include "Node.h"

namespace ds
{
    template <class T>
    class IteratorInterface
    {
    public:
        virtual bool HasNext() const = 0;
        virtual T& Next() = 0;
    };

    namespace sn
    {
        template<class T>
        class Iterator : public IteratorInterface<T> 
        {
        private:
            Node<T>* data;
        public:
            Iterator() : Iterator(NULL) {}

            Iterator(Node<T>* data) : data(data) {}

            bool HasNext() const 
            {
                return (data == NULL);
            }

            T& Next() 
            {
                Node<T>* tmp = data;
                data = data->GetLink();
                return tmp->GetData();
            }
        };
    }
}

#endif