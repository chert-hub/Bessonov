#include <iostream>
#include <thread>
#include <atomic>

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& data_) : data(data_), next(nullptr) {}
};

template <typename T>
class LockFreeQueue {
private:
    Node<T>* head;
    std::atomic<Node<T>*> tail;

public:
    LockFreeQueue() : head(new Node<T>(T())), tail(head) {}

    void push(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        while (true) {
            Node<T>* currentTail = tail.load();
            Node<T>* next = currentTail->next;
            if (currentTail == tail.load()) {
                if (next == nullptr) {
                    if (currentTail->next.compare_exchange_strong(next, newNode)) {
                        break;
                    }
                }
                else {
                    tail.compare_exchange_strong(currentTail, next);
                }
            }
        }
        tail.store(newNode);
    }

    T pop() {
        while (true) {
            Node<T>* currentHead = head;
            Node<T>* currentTail = tail.load();
            Node<T>* firstNode = currentHead->next;
            if (currentHead == head) {
                if (currentHead == currentTail) {
                    if (firstNode == nullptr) {
                        return T(); // ���������� �������� �� ���������, ���� ������� �����
                    }
                    tail.compare_exchange_strong(currentTail, firstNode);
                }
                else {
                    if (head.compare_exchange_strong(currentHead, firstNode)) {
                        T res = firstNode->data;
                        delete currentHead;
                        return res;
                    }
                }
            }
        }
    }
};

int main() {
    LockFreeQueue<int> queue;

    // ����� 1 ��������� �������� � �������
    std::thread t1([&queue]() {
        for (int i = 0; i < 10; ++i) {
            queue.push(i);
        }
        });

    // ����� 2 ��������� �������� �� �������
    std::thread t2([&queue]() {
        for (int i = 0; i < 10; ++i) {
            std::cout << "Popped: " << queue.pop() << std::endl;
        }
        });

    t1.join();
    t2.join();

    return 0;
}
