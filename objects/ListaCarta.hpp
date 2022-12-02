#pragma once

#include <iostream>
#include "classBaraja.hpp"
using namespace std;

struct Node {
    Card carta;
    Node* next;

    Node() : carta(), next(nullptr) {}
    Node(Card cartaActual, Baraja &baraja, Node* tempNext);
};
Node::Node(Card cartaActual, Baraja &baraja, Node* tempNext) {
    
    cartaActual = baraja.popCard();
    next = tempNext;
}

class LinkedList {
private:

    Node* head;

public:
    LinkedList();

    void insert(Card, Baraja &baraja, Node* tempNext);
    Card pop(Card);
    void remove(Card);   
    void print();
};
LinkedList::LinkedList() :head(nullptr) {}

void LinkedList::insert(Card carta, Baraja &baraja, Node* tempNext) {
    // make a new node
    Node* new_node = new Node(carta, baraja, tempNext);

    // If list is empty, make the new node, the head
    if (head == nullptr) {
        head = new_node;
    }
    // else, make the new_node the head and its next, the previous
    // head
    else {
        new_node->next = head;
        head = new_node;
    }
}
Card LinkedList::pop(Card carta){
    
    Node* temp = head;

    if (temp!= nullptr && temp)

}
/*
void LinkedList::remove(Card val) {

    Node* temp = head;
    // If the head is to be deleted
    if (temp != nullptr && temp->data == val) {

        head = temp->next;
        delete temp;
        return;
    }
    // Else loop over the list and search for the node to delete
    else {

        Node* curr = head;
        while (temp != nullptr && temp->data != val) {
            // When node is found, delete the node and modify the pointers
            curr = temp;
            temp = temp->next;
        }
        // If values is not found in the linked list
        if (!temp) {

            cout << "Value not found" << endl;
            return;
        }

        curr->next = temp->next;
        delete temp;
    }
}
*/
void LinkedList::print() {

    Node* temp = head;

    while (temp != nullptr) {

        temp->carta.print();
        temp = temp->next;
    }
    cout << endl;
}
