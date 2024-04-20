#ifndef QUEUETP_H_
#define QUEUETP_H_

template <typename Item>
class QueueTp
{
private:
    enum{ Q_SIZE = 10 };
    struct Node
    {
        Item item;
        struct Node *next;
    };
    Node *front;
    Node *rear;
    int items;
    const int qsize;
    QueueTp(const QueueTp &q) : qsize(0) {}
    QueueTp &operator=(const QueueTp &q) { return *this; }

public:
    QueueTp(int qs = Q_SIZE);
    ~QueueTp();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item &item);
    bool dequeue(Item &item);
};

template <typename Item>
QueueTp<Item>::QueueTp(int qs) : qsize(qs)
{
    front = rear = nullptr;
    items = 0;
}

template <typename Item>
QueueTp<Item>::~QueueTp()
{
    Node *temp;

    while (front != nullptr)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}

template <typename Item>
bool QueueTp<Item>::isempty() const
{
    return 0 == items;
}

template <typename Item>
bool QueueTp<Item>::isfull() const
{
    return qsize == items;
}

template <typename Item>
int QueueTp<Item>::queuecount() const
{
    return items;
}

template <typename Item>
bool QueueTp<Item>::enqueue(const Item &item)
{
    if (isfull())
    {
        return false;
    }
    Node *add = new Node;
    add->item = item;
    add->next = nullptr;
    ++items;
    if (nullptr == front)
    {
        front = add;
    }
    else
    {
        rear->next = add;
    }
    rear = add;
    return true;
}

template <typename Item>
bool QueueTp<Item>::dequeue(Item &item)
{
    if (isempty())
    {
        return false;
    }
    item = front->item;
    --items;
    Node *temp = front;
    front = front->next;
    delete temp;
    if (0 == items)
    {
        rear = nullptr;
    }
    return true;
}

#endif
