//minheap using linked list
#include <iostream>
#include <queue>
using namespace std;
class Node {
private:
    int data;
    Node* parent;
    Node* left;
    Node* right;
public:
    Node(int a) {
        data = a;
        left = right = parent = NULL;
    }
    void setD(int a) { data = a; }
    int getD() { return data; }
    void setL(Node* l) {
        left = l;
    }
    Node* getL() { return left; }
    void setR(Node* l) {
        right = l;
    }
    Node* getR() { return right; }
    void setP(Node* l) {
        parent = l;
    }
    Node* getP() { return parent; }
};
class Heap {
private:
    Node* head;
    void swap(Node* a, Node* b) {
        int temp = a->getD();
        a->setD(b->getD());
        b->setD(temp);
    }
public:
    Heap() {
        head = NULL;
    }
    Node* lastparent() {
        queue<Node*> q;
        Node* temp = NULL;
        q.push(head);
        while (!q.empty()) {
            temp = q.front();
            q.pop();
            if (temp->getL() && temp->getR()) {
                q.push(temp->getL());
                q.push(temp->getR());
            }
            else { break; }
        }
        return temp;
    }

    void upheapify(Node* node) {
        if (node->getP() == NULL) { return; }
        if (node->getP()->getD() > node->getD()) {
            swap(node->getP(), node);
            upheapify(node->getP());
        }


    }
    void insert(int data) {
        Node* node = new Node(data);
        cout << "ins: " << data << endl;
        if (head == NULL) {
            head = node;
            return;

        }
        Node* lstparent = lastparent();
        if (lstparent->getR() == NULL) {
            lstparent->setR(node);
            node->setP(lstparent);
        }
        else {
            lstparent->setL(node);
            node->setP(lstparent);
        }
        upheapify(node);
    }
    Node* last() {
        if (head == nullptr) return nullptr;

        queue<Node*> q;
        q.push(head);
        Node* last = nullptr;

        while (!q.empty()) {
            last = q.front();
            q.pop();
            if (last->getL() != nullptr) {
                q.push(last->getL());
            }
            if (last->getR() != nullptr) {
                q.push(last->getR());
            }
        }

        return last;
    }

    void downheapify(Node* node) {
        if (node == nullptr) return;

        

        Node* small = node;
        if (node->getL() != nullptr && node->getL()->getD() < small->getD()) {
            small = node->getL();
        }
        if (node->getR() != nullptr && node->getR()->getD() < small->getD()) {
            small = node->getR();
        }
        if (small != node) {
            swap(node, small);
            downheapify(small);
        }
    }


    void ROOT() {
        if (head == nullptr) {
            cout << "Heap is empty. Cannot delete root." << endl;
            return;
        }

        cout << "Deleted: " << head->getD() << endl;
        Node* lastNode = last();

        if (head == lastNode) {
            delete head;
            head = nullptr;
            return;
        }

        swap(head, lastNode);
        Node* pr = lastNode->getP();

        if (pr->getL() == lastNode) {
            delete lastNode;
            pr->setL(nullptr);
        }
        else {
            delete lastNode;
            pr->setR(nullptr);
        }

        

        downheapify(head); 
    }


    void inorder(Node* n) {
        if (n == NULL) { return; }
        inorder(n->getL());
        cout << n->getD() << " ";
        inorder(n->getR());
    }

    void display() {
        Node* temp = head;
        inorder(temp);
        cout << endl;
    }
};
int main() {
    Heap h;
    h.insert(50);
    h.insert(70);
    h.insert(56);
    h.insert(58);
    h.insert(86);
    h.insert(54);
    h.insert(9);
    h.display();
    h.ROOT();
    h.display();
    return 0;
}
