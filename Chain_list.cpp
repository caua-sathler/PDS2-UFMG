#include "Chain_list.hpp"

Chain_list::Chain_list(){
    this->head = nullptr;
    this->tail = nullptr;
    this->num_elements = 0;
    this->p = &num_elements;
}


void Chain_list::insert_node(int data) {
    Node* ctrl = new Node;
    ctrl->data = data;
    ctrl->next = nullptr;

    if(head == nullptr) {
        head = ctrl;
        ctrl->previous = nullptr;
        tail = ctrl;
    } else {
        tail->next = ctrl;
        ctrl->previous = tail;
        tail = ctrl;
    }
    *p += 1;
}

void Chain_list::delete_node(int data) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data == data) {
            if (current->previous == nullptr) { 
                head = current->next;
                if (head != nullptr) {
                    head->previous = nullptr;
                }
                if (current == tail) { 
                    tail = nullptr;
                }
            } else if (current->next == nullptr) { 
                tail = current->previous;
                tail->next = nullptr;
            } else { 
                current->previous->next = current->next;
                current->next->previous = current->previous;
            }
            delete current;
            *p -= 1;
            return; 
        }
        current->previous = current;
        current = current->next;
    }
}

bool Chain_list::is_on_list(int data) {
    Node* current = head;

    while(current != nullptr) {
        if(current->data ==  data)
            return true;
        else 
            current = current->next;
    }
    return false;
}










