//
// Created by student on 13.05.2020.
//

#ifndef CARRENTAL_REPOSITORY_H
#define CARRENTAL_REPOSITORY_H
#include "model/typedefs.h"
#include <list>
template<class T> class Repository
{
protected:
    std::list<std::shared_ptr<T>> objects;
public:
    void add(std::shared_ptr<T>);
    int RepoSize();
    std::_List_iterator<std::shared_ptr<T>> begin();
    std::_List_iterator<std::shared_ptr<T>> end();
};
template<class T>
void Repository<T>::add(std::shared_ptr<T> ptr) {
    objects.push_back(ptr);
}

template<class T>
int Repository<T>::RepoSize() {
    return objects.size();
}

template<class T>
std::_List_iterator<std::shared_ptr<T>> Repository<T>::begin() {
    return objects.begin();
}

template<class T>
std::_List_iterator<std::shared_ptr<T>> Repository<T>::end() {
    return objects.end();
}

#endif //CARRENTAL_REPOSITORY_H
