// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <iostream>
#include <string>

template<typename T>
class TPQueue {
 private:
    struct OBJECT {
        T data;
        OBJECT *next;
        OBJECT *prev;
    };
    TPQueue::OBJECT* create(const T& data) {
        OBJECT* obj = new OBJECT;
        obj->data = data;
        obj->next = nullptr;
        obj->prev = nullptr;
        return obj;
    }
    OBJECT *head;
    OBJECT *tail;

 public:
    T pop() { //извлечение из очереди
        if (head) {
            OBJECT* cur = head->next;
            if (cur)
                cur->prev = nullptr;
            T data = head->data;
            delete head;
            head = cur;
            return data;
        } else {
            throw std::string("empty!!!");
        }
    }
    void push(const T& data) { //встлавка элемента
        OBJECT* cur = head;
        OBJECT* obj = create(data);
        while (cur && cur->data.prior >= data.prior)
            cur = cur->next;
        if (!cur && !head) {//в пустой список
            head = tail = obj;
        } else if (!cur->prev) { //в начало
            cur->prev = obj;
            obj->next = cur;
            head = obj;
        } else if (!cur && head) { //в конец
            tail->next = obj;
            tail->next->prev = tail;
            tail = obj;
        } else { //в середину
            cur->prev->next = obj;
            obj->prev = cur->prev;
            obj->next = cur;
            cur->prev = obj;
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
