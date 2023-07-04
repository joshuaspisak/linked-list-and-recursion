/******************************************************
** Program: linked_list.cpp
** Author: Joshua Spisak
** Date: 3/20/2023
** Description: implements linked_list functionality and methods.
** Input: Linked_List values must be populated.
** Output: Depends on method used.
******************************************************/


#include <iostream>

#include "linked_list.h"

using namespace std;

Linked_List::Linked_List(){
    this->length = 0;
    this->head = NULL;
}

unsigned int Linked_List::get_length(){
    return this->length;
}

Node* Linked_List::get_head(){
    return this->head;
}

/*********************************************************************
** Function: print
** Description: goes through each member of list and prints "val"
** Parameters: none
** Pre-Conditions: list is populated
** Post-Conditions: "vals" printed
*********************************************************************/

void Linked_List::print(){
    Node* temp = this->head;
    if(temp == NULL){
        cout << endl;
        return;
    }
    while(temp->next != NULL){
        cout << temp->val << " "; // prints out val
        temp = temp->next;
    }
    cout << temp->val << endl;
}

/*********************************************************************
** Function: clear
** Description: deletes every element in the list and set sht esize to 0
** Parameters: none
** Pre-Conditions: list with some elements
** Post-Conditions: empty list
*********************************************************************/

void Linked_List::clear(){
    if(this->head == NULL){
        cout << endl << "Already empty." << endl;
        return;
    }
    if(this->head->next == NULL){
        delete this->head;
        this->head = NULL;
        this->length--;
        return;
    }
    Node* temp = this->head;
    while(this->get_length() != 1){ //loops until size is 1
        temp = this->head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        this->length--;
    }
    delete this->head;
    this->head = NULL;
    this->length--; //takes away one from length to make it zero
}

void Linked_List::push_front(int val){
    Node* front = new Node;
    front->val = val;
    if(this->head == NULL){
        front->next = NULL;
    }
    else{
        front->next = this->head;
    }
    this->head = front;
    this->length++;
}

void Linked_List::push_back(int val){
    Node* back = new Node;
    back->val = val;
    back-> next = NULL;
    if(this->head == NULL){
        this->head = back;
        this->length++;
        return;
    }
    Node* temp = this->head; // sets a new pointer to the first element
    while(temp->next != NULL){ //loops through each node
        temp = temp->next;
    }
    temp->next = back;
    this->length++;
}

void Linked_List::insert(int val, unsigned int index){
    if(index == 0){
        this->push_front(val); //edge case
        return;
    }
    if(index == this->length){
        this->push_back(val); //edge case
        return;
    }
    if(index > this->length){
        return;
    }
    Node* addition = new Node;
    addition->val = val;
    Node* current = this->head;
    for (int i = 0; i < index - 1; i++)
    {
        current = current->next;
    }
    Node* temp = current->next;
    current->next = addition;
    addition->next = temp;
    this->length++;
}

/*********************************************************************
** Function: merge_sort_a
** Description: recursive merge sort for ascending sort
** Parameters: a referencce to the header pointer
** Pre-Conditions: sorted or not sorted
** Post-Conditions: sorted
*********************************************************************/

void Linked_List::merge_sort_a(Node*& start){

    int size = 0;
    Node* temp = start;
    while(temp != NULL){
        size++;
        temp = temp->next;
    }
    if(size == 0 || size == 1){ // base case
        return;
    }

    Node* left_list = start;
    Node* right_list = NULL;
    split(left_list, right_list);

    merge_sort_a(left_list);

    merge_sort_a(right_list);

    start = merge_a(left_list, right_list);

}

Node* Linked_List::merge_a(Node* left_list, Node* right_list){
    Node* temp_left = left_list;
    Node* temp_right = right_list;

    Node* merged_start;
    Node* merged_start_temp;

    if(temp_right->val > temp_left->val){
        merged_start = temp_left;
        temp_left = temp_left->next;
    }
    else{
        merged_start = temp_right;
        temp_right = temp_right->next;
    }

    merged_start->next = NULL;
    merged_start_temp = merged_start;

    while(temp_left != NULL && temp_right != NULL){
        if(temp_right->val > temp_left->val){
            merged_start_temp->next = temp_left;
            merged_start_temp = merged_start_temp->next;
            temp_left = temp_left->next;
            merged_start_temp->next = NULL;
        }
        else{
            merged_start_temp->next = temp_right;
            merged_start_temp = merged_start_temp->next;
            temp_right = temp_right->next;
            merged_start_temp->next = NULL;
        }
    }

    if(temp_left == NULL){ //appends leftover
        while(temp_right != NULL){
            merged_start_temp->next = temp_right;
            merged_start_temp = merged_start_temp->next;
            temp_right = temp_right->next;
            merged_start_temp->next = NULL;
        }
    }
    else if(temp_right == NULL){ //appends leftover
        while(temp_left != NULL){
            merged_start_temp->next = temp_left;
            merged_start_temp = merged_start_temp->next;
            temp_left = temp_left->next;
            merged_start_temp->next = NULL;
        }
    }

    return merged_start;
}

void Linked_List::split(Node*& left_list, Node*& right_list){
    int size = 0;
    Node* temp = left_list;
    while(temp != NULL){
        size++;
        temp = temp->next;
    }
    temp = left_list;
    for (int i = 0; i < size / 2 - 1; i++)
    {
        temp = temp->next;
    }
    right_list = temp->next; //set right list to the midpoint
    temp->next = NULL;
}

/*********************************************************************
** Function: merge_sort_d
** Description: recursive merge sort for descending sort
** Parameters: a referencce to the header pointer
** Pre-Conditions: sorted or not sorted
** Post-Conditions: sorted
*********************************************************************/

void Linked_List::merge_sort_d(Node*& start){

    int size = 0;
    Node* temp = start;
    while(temp != NULL){
        size++;
        temp = temp->next;
    }
    if(size == 0 || size == 1){ //base case
        return;
    }

    Node* left_list = start;
    Node* right_list = NULL;
    split(left_list, right_list);

    merge_sort_d(left_list);

    merge_sort_d(right_list);

    start = merge_d(left_list, right_list);

}

Node* Linked_List::merge_d(Node* left_list, Node* right_list){
    Node* temp_left = left_list;
    Node* temp_right = right_list;

    Node* merged_start;
    Node* merged_start_temp;

    if(temp_right->val < temp_left->val){
        merged_start = temp_left;
        temp_left = temp_left->next;
    }
    else{
        merged_start = temp_right;
        temp_right = temp_right->next;
    }

    merged_start->next = NULL;
    merged_start_temp = merged_start;

    while(temp_left != NULL && temp_right != NULL){
        if(temp_right->val < temp_left->val){
            merged_start_temp->next = temp_left;
            merged_start_temp = merged_start_temp->next;
            temp_left = temp_left->next;
            merged_start_temp->next = NULL;
        }
        else{
            merged_start_temp->next = temp_right;
            merged_start_temp = merged_start_temp->next;
            temp_right = temp_right->next;
            merged_start_temp->next = NULL;
        }
    }

    if(temp_left == NULL){ // appends leftover
        while(temp_right != NULL){
            merged_start_temp->next = temp_right;
            merged_start_temp = merged_start_temp->next;
            temp_right = temp_right->next;
            merged_start_temp->next = NULL;
        }
    }
    else if(temp_right == NULL){ // appends leftover
        while(temp_left != NULL){
            merged_start_temp->next = temp_left;
            merged_start_temp = merged_start_temp->next;
            temp_left = temp_left->next;
            merged_start_temp->next = NULL;
        }
    }

    return merged_start;
}

void Linked_List::sort_ascending(){
    merge_sort_a(this->head);
}

void Linked_List::sort_descending(){
    merge_sort_d(this->head);
}

unsigned int count_prime(Linked_List& linked_list){

    unsigned int num_prime = 0;

    Node* temp = linked_list.get_head();

    while(temp != NULL){
        if(is_prime(temp->val) == true){ // calls to check if val is prime
            num_prime++;
        }
        temp = temp->next;
    }

    return num_prime;
    
}

bool is_prime(int n){
  if (n <= 1) {
    return false;
  }

  // loop to check if n is prime
  for (int i = 2; i <= n/2; ++i) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}