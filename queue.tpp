

#include <iostream>
#include "queue.h"

template <typename T>
queue<T>::queue() : size(0), head_node(nullptr)
{
}

template <typename T>
bool queue<T>::enqueue(T data, enum priority priority)
{
    struct node<T>(*new_node) = new struct node<T>;
    new_node->data = data;
    new_node->priority = priority;

    if (this->head_node == nullptr) // not first time?
        this->head_node = new_node;
    else // nope
    {
        struct node<T>(*lower_priority_node) = this->head_node;
        struct node<T>(*pre_lower_priority_node) = lower_priority_node;
        bool is_head = true; // starting from head
        while (lower_priority_node != nullptr)
        {
            if (priority >= lower_priority_node->priority) // iterate through greater priorties
                break;
            is_head = false;
            pre_lower_priority_node = lower_priority_node;
            lower_priority_node = lower_priority_node->previous_node;
        }
        // we found lower priority than new node!
        if (lower_priority_node != nullptr)
        {
            new_node->previous_node = lower_priority_node;
            if (is_head)
                this->head_node = new_node;
            else
                pre_lower_priority_node->previous_node = new_node;
        }
        else // there is no lower priority than new node! new node is lowest priority!
            pre_lower_priority_node->previous_node = new_node;
    }
    this->size++;
    return true;
}

template <typename T>
bool queue<T>::dequeue()
{
    if (this->size == 0)
        return false;
    if (this->size == 1) // we're in head
    {
        this->head_node = nullptr;
        this->size--;
        return true;
    }
    struct node<T>(*iter) = this->head_node;
    struct node<T>(*prev_node_ptr) = iter;
    while (iter->previous_node != nullptr)
    {
        prev_node_ptr = iter;
        iter = iter->previous_node;
    }
    prev_node_ptr->previous_node = nullptr;
    this->size--;
    return true;
}

template <typename T>
T queue<T>::peek(T data)
{
    if (this->size == 0)
        return false;
    struct node<T>(*iter) = this->head_node;
    while (iter != nullptr)
    {
        if (iter->data == data)
            return data; // founded!
        iter = iter->previous_node;
    }
    return static_cast<T>(0); // not found!
}

template <typename T>
void queue<T>::print_items()
{
    if (this->size == 0)
        return;
    std::cout << "*********************" << std::endl;
    struct node<T>(*iter) = this->head_node;
    while (iter != nullptr)
    {
        std::cout << "Address : " << iter << " -- Priority : " << iter->priority << " -- Value : " << iter->data << " -- Prev : " << iter->previous_node << std::endl;
        iter = iter->previous_node;
    }
    return;
}
