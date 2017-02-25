#ifndef GSATCK_H
#define GSATCK_H


#include <iostream>
#include<memory>

//using namespace std;
//enum T_FLAG{FILLED, EMPTY};
//template <typename T>
//struct BSTNode{

//    T val;
//    T_FLAG flag = T_FLAG::EMPTY;
//    unique_ptr<BSTNode> left, right;

//};


//void insertIntoBST(unique_ptr<BSTNode<int>> root, int val){


//    while(T_FLAG::EMPTY != root->flag){

//        if(root->val <= val) root = root->left;
//        else root = root->right;

//    }

//    root->val = val;
//    root->left = new BSTNode<int>;
//    root->right = new BSTNode<int>;
//}



template <typename T>
class gStack {
  public:
    int noElements=0;

    struct node {
        T val;
        node *next = nullptr;
    } *head = nullptr;

    void push(T val);
    void pop();
    bool empty();
    T top();
};


template <typename T>
void gStack<T>::push(T val) {
    node *b = new node;
    b->val = val;

    if (head == nullptr) {
        head = b;
    } else {
        b->next = head;
        head = b;
    }

    noElements++;
   // std::cout << noElements << std::endl;
}

template <typename T>
void gStack<T>::pop() {
    if(noElements ==0){
        return;
    }
    node *temp = head;
    head = head->next;
    delete temp;
    noElements--;
}

template <typename T> T
gStack<T>::top() { return head->val; }

template <typename T>
bool gStack<T>::empty(){
    if(noElements ==0) return true;
    else return false;
}

class aStack{


    int** subStack;
    int currSubstack =0;
    int maxNoElementes =2;
    int maxSubStacks = 10;

public:
    int* size;
    void pop();
    void push(int val);
    void clear();
    aStack();
    aStack(int);

};


//singly linked list
struct node{

    int val;
    node* next = NULL;

    node(int val_, node* next_):val(val_), next(next){}

};
class sll{

    node* head = NULL;
    node* tail = NULL;

public:
    sll(node* head_):head(head_){

        tail = head;
    }

    void insert(node* in){

        tail->next = in;

        tail = in;

    }

    void updateHead(node* head_){

        head = head_;

    }

    void updateTail(node* tail_){
        tail = tail_;
    }

    //friend grants access to private data

    friend std::ostream& operator<< (std::ostream& os, const sll& sll){
        node* l = sll.head;
        while(l != NULL){
            os << l->val << " " ;
            l = l->next;
        }
    }
};

#endif // GSATCK_H
