// max using linked list
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

    void swapValues(Node* a, Node* b) {
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
        q.push(head);
        Node* temp = NULL;

        while (!q.empty()) {
            temp = q.front();
            q.pop();
            if (temp->getL() && temp->getR()) {
                q.push(temp->getL());
                q.push(temp->getR());
            }
            else {
                break;
            }
        }
        return temp;
    }

    void upHeapify(Node* temp) {
        if (temp->getP() == NULL) {
            return;
        }
        if (temp->getP()->getD() < temp->getD()) {
            swapValues(temp->getP(), temp);
            upHeapify(temp->getP());
        }
    }

    void insert(int data) {
        Node* newnode = new Node(data);
        cout << "Inserting: " << data << "\n";

        if (head == NULL) {
            head = newnode;
            return;
        }

        Node* lpar = lastparent();

        if (lpar->getL() == NULL) {
            lpar->setL(newnode);
            newnode->setP(lpar);
        }
        else {
            lpar->setR(newnode);
            newnode->setP(lpar);
        }
        upHeapify(newnode);
    }

    void inorder(Node* he) {
        if (he == NULL) {
            return;
        }
        inorder(he->getL());
        cout << he->getD() << " ";
        inorder(he->getR());
    }

    void display() {
       
        Node* temp = head;
        inorder(temp);
        cout << endl;
    }

    bool isEmpty() {
        return head == NULL;
    }

    Node* lastnode() {
        queue<Node*> q;
        q.push(head);
        Node* last = NULL;
        while (!q.empty()) {
            last = q.front();
            q.pop();
            if (last->getL()) {
                q.push(last->getL());
            }
            if (last->getR()) {
                q.push(last->getR());
            }
        }
        return last;
    }

    void downHeapify(Node* k) {
        Node* largest = k;

        if (k->getL() && k->getL()->getD() > largest->getD()) {
            largest = k->getL();
        }

        if (k->getR() && k->getR()->getD() > largest->getD()) {
            largest = k->getR();
        }

        if (largest != k) {
            swapValues(largest, k);
            downHeapify(largest);
        }
    }

    void ROOT() {
        if (isEmpty()) {
            cout << "Heap is empty\n";
            return;
        }
        cout << "Deleting: " << head->getD() << endl;

        Node* last = lastnode();
        if (last == head) {
            delete last;
            head = NULL;
            return;
        }
        swapValues(head, last);
        Node* pr = last->getP();

        if (pr->getL() == last) {
            delete last;
            pr->setL(NULL);
        }
        else {
            delete last;
            pr->setR(NULL);
        }

        downHeapify(head);
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
