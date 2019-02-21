/*
 * ******************************************************************
 *                                                                  *
 *     There is a template class which called Stack in this head    *
 * file. Because it's a template I make class define (only include  *
 * class members' declaration) and members' definition together in  *
 * only one file.                                                   *
 *                                                                  *
 *     All of the template class are contained in namespace cyc.    *
 * Declaration is the first and followed are definition.            *
 *                                                                  *
 *     The template class Stack is like a hole which obey LIFO      *
 * (last in, first out) rule. It means that which is top in hole    *
 * (last in) will go out by first.                                  *
 *                                                                  *
 *     The template class Stack have basic functions which are      *
 * constructor, destructor and assignment operator. They also have  *
 * special functions which are:                                     *
 *                                                                  *
 *     empty(): return a bool explain whether the Stack is empty.   *
 *     get_size(): return an int explain the Stack size.            *
 *     top(): return the top element of Stack.                      *
 *     push(T): add an object at the top of Stack, no return.       *
 *     pop(): make the top element of Stack delete, no return.      *
 *     clear(): delete all elements, no return.                     *
 *                                                                  *
 * ******************************************************************
 */

#ifndef SUMMERPROJECT_STACK_H
#define SUMMERPROJECT_STACK_H

#include "Vector.h"

namespace cyc
{
    template<typename T>
    class Stack
    {
    private:
        Vector <T> v;

    public:
        Stack();
        ~Stack();
        Stack(const Stack &rhs);
        Stack &operator=(const Stack &rhs);

        bool empty() const;
        int get_size() const;
        const T &top() const;

        void push(const T &rhs);
        void pop();
        void clear();
    };

    /*
     * ******************************************************************
     *                                                                  *
     *     All after here are definitions of functions of class Stack.  *
     *                                                                  *
     * ******************************************************************
     */

    template<typename T>
    Stack<T>::Stack()
    {
        ;
    }

    template<typename T>
    Stack<T>::~Stack()
    {
        ;
    }

    template<typename T>
    Stack<T>::Stack(const Stack &rhs)
            : Stack()
    {
        *this = rhs;
    }

    template<typename T>
    Stack<T> &Stack<T>::operator=(const Stack &rhs)
    {
        if (&rhs == this)
        {
            return *this;
        }
        v = rhs.v;
        return *this;
    }

    template<typename T>
    bool Stack<T>::empty() const
    {
        return get_size() == 0;
    }

    template<typename T>
    int Stack<T>::get_size() const
    {
        return v.get_size();
    }

    template<typename T>
    const T &Stack<T>::top() const
    {
        return v[v.get_size() - 1];
    }

    template<typename T>
    void Stack<T>::push(const T &rhs)
    {
        v.push_back(rhs);
    }

    template<typename T>
    void Stack<T>::pop()
    {
        v.pop_back();
    }

    template<typename T>
    void Stack<T>::clear()
    {
        v.clear();
    }
}

#endif //SUMMERPROJECT_STACK_H
