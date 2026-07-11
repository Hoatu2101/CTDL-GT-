#include <iostream>
using namespace std;
struct Node {
    Node* next;
    int info;
};
struct linkedList {
    Node* head;
};

bool isEmpty(linkedList ls) {
    return ls.head == nullptr;
}
void init(linkedList& ls) {
    ls.head = nullptr;
}
Node* createNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->next = nullptr;
    return p;
}
void addHead(linkedList& ls, int x) {
    Node* p = createNode(x);
    if (isEmpty(ls)) {
        ls.head = p;
    }
    else {
        p->next = ls.head;
        ls.head = p;
    }
}
void printList(linkedList& ls) {
    if (isEmpty(ls)) {
        cout << "Danh sach rong ";
        return;
    }
    Node* p = ls.head;
    while (p!=nullptr)
    {
        cout << p->info << " ";
        p = p->next;

    }
    cout << endl;
}
void deleteHead(linkedList& ls) {
    Node* p = ls.head;
    if (isEmpty(ls)) {
        cout << "Khong co gi de xoa !";
        return;
    }
    ls.head = p->next;
    p->next = nullptr;
    delete p;
}
void destroyList(linkedList& ls) {

    while (ls.head != nullptr)
    {
        deleteHead(ls);
    }
    cout << "Da xoa thanh cong !";

}
//tim mot phan tu trong danh sach
Node* search(linkedList ls, const int key) {
    Node* q = ls.head;
    while (q!=nullptr && q->info!=key)
 
        q = q->next;
    
    return q;
}
void insertAfter(linkedList& ls, int x, int y) {
    Node* q = ls.head;
    while (q != nullptr && q->info != y) {
        q = q->next;
    }

    if (q == nullptr) {
        cout << "Khong tim thay gia tri!";
        return;
    }

   
    Node* p = createNode(x);
    p->next = q->next; // gắn dây  cho node sau sau node chen
    q->next = p;      // nối dây cho node phía trước node chèn
}
void deleteTail(linkedList&ls) {
    Node *tail = ls.head;
    Node* prev = nullptr;
    while(tail->next != nullptr) {
        prev = tail;
        tail = tail->next;
    }
    if (prev == nullptr) {
        ls.head = nullptr;
    }
    else {
        prev->next = nullptr;
        delete tail;
    }

}
void insertTail(linkedList &ls,int x) {
    Node* p = createNode(x);
    if (ls.head == nullptr) {
        ls.head = p;

    }
    else {
        Node* tail = ls.head;
        while (tail->next != nullptr)
            tail = tail->next;
        tail->next = p;
    }
}
void addBefore(linkedList& ls, int x, int y) {
    Node* p = createNode(x);
    Node* q = ls.head;
        Node * prev = nullptr;
    while (q != nullptr && q->info != y) {
        q = prev;
        q = q->next;
    }

    if (q == nullptr) {
        cout << "Khong tim thay gia tri!";
        return;
    }
    p->next = q;
    if (prev != nullptr) {
        prev->next = p;

    }else{
        ls.head = p;
    }
}
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void sortList(linkedList l) {
    for (Node* p = l.head; p ->next!= nullptr; p = p->next) {
        for (Node* q = p->next; q != nullptr; q = q->next)
            if (p->info > q->info) {
                swap(p->info, q->info);
            }
    }
}
int getIndex(linkedList l, int x) {
    if (!isEmpty(l)) {
        Node* p = l.head;
        int i = 0;

        while (p != nullptr && p->info != x) {
            p = p->next;
            i++;
        }

        if (p != nullptr)
            return i;   // tìm thấy x
    }

    return -1; // không tìm thấy hoặc danh sách rỗng
}
int main() {
    linkedList ls;
    init(ls);
    addHead(ls, 4);
    addHead(ls, 6);
    addHead(ls, 2);
    addHead(ls, 5);
    addHead(ls, 1);
    addHead(ls, 3);
    sortList(ls);
   
    cout << getIndex(ls, 6);
   /* insertTail(ls, 9);
    insertAfter(ls, 5, 2);*/
  /*  deleteTail(ls);*/
    /*deleteHead(ls);*/
    cout << endl;
    printList(ls);
   /* Node* kq = search(ls, 6);
    cout << kq;*/
  
    destroyList(ls);
   /* cout << endl;
    printList(ls);*/







    return 0;

}