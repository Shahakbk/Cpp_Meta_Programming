//
// Created by Abir on 16/01/2020.
//

#ifndef OOP_HW5_LIST_H
#define OOP_HW5_LIST_H

/// declaring List
template<typename ...TT>
struct List {};

/// empty List should contain only size 0.
template<>
struct List<> {
    constexpr static int size = 0;
};

/// List of 1 element, contains the element, next is empty List, and size is 1.
template<typename T>
struct List<T> {
    typedef T head;
    typedef List<> next;
    constexpr static int size = 1;
};

/// List, contains head, next List, and Size.
template<typename T, typename ...TT>
struct List<T, TT...> {
    typedef T head;
    typedef List<TT...> next;
    constexpr static int size = (sizeof ...(TT) + 1);
};

#endif //OOP_HW5_LIST_H