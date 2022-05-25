
#ifndef QUEUE
#define QUEUE 1

/*
Priority Queue : FIFO
10(0) : head-> 10(0)
20(1) : head-> 20(1) -> 10(0)
30(2) : head-> 30(2) -> 20(1) -> 10(1)
40(0) : head-> 30(2) -> 20(1) -> 10(1) -> 40(0)
*/

enum priority
{
    LOW = 0, // 4 bytes
    MEDIUM,  // 4 bytes
    HIGH     // 4 bytes
};

template <typename T>
struct node
{
    T data;                         // 4 bytes
    enum priority priority;         // 12 bytes (if no aligment)
    struct node<T>(*previous_node); // 8 bytes
};

template <typename T>
class queue
{
private:
    int size;
    struct node<T>(*head_node);

public:
    explicit queue();
    bool enqueue(T, enum priority);
    bool dequeue();
    T peek(T);
    void print_items();
};

#include "queue.tpp"

#endif