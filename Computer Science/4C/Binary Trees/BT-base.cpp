#include <iostream>
using namespace std;

class Nodo {
  int dato;
  Nodo *ps;
  Nodo *pd;

public:
  Nodo();
  Nodo(int d);
  Nodo(int d, Nodo *sx, Nodo *dx);

  int getDato();
  void setDato(int d);
  Nodo *getPs();
  void setPs(Nodo *sx);
  Nodo *getPd();
  void setPd(Nodo *dx);
};

Nodo::Nodo() {
  dato = 0;
  ps = NULL;
  pd = NULL;
}

Nodo::Nodo(int d) {
  dato = d;
  ps = NULL;
  pd = NULL;
}

Nodo::Nodo(int d, Nodo *sx, Nodo *dx) {
  dato = d;
  ps = sx;
  pd = dx;
}

int Nodo::getDato() { return dato; }

void Nodo::setDato(int d) { dato = d; }

Nodo *Nodo::getPs() { return ps; }

void Nodo::setPs(Nodo *sx) { ps = sx; }

Nodo *Nodo::getPd() { return pd; }

void Nodo::setPd(Nodo *dx) { pd = dx; }

///////////////////////////////

class BTree {
  Nodo *head;

public:
  BTree();
  bool addChild(int d);
  void simVisit();
  void preOrder();
  void postOrder();
};

BTree::BTree() { head = NULL; }

bool BTree::addChild(int d) {
  Nodo *aux = new Nodo(d);
  Nodo *aux2;
  int trovato = 0;
  bool ins = false;

  if (head == NULL) {
    head = aux;
    ins = true;
  } else {
    aux2 = head;
    while ((aux2->getDato() != d) && ins == false) {
      if (aux2->getDato() > d) { // go to left
        if (aux2->getPs() != NULL)
          aux2 = aux2->getPs();
        else { // add
          aux2->setPs(aux);
          ins = true;
        }
      } else { // go to right
        if (aux2->getPd() != NULL)
          aux2 = aux2->getPd();
        else { // add
          aux2->setPd(aux);
          ins = true;
        }
      }

    } // while
  }

  return ins;
}

void printOSRic(Nodo *aux) {
  if (aux != NULL) {
    if (aux->getPs()) {
      printOSRic(aux->getPs());
    }
    cout << aux->getDato() << " ";
    if (aux->getPd()) {
      printOSRic(aux->getPd());
    }
  }
}

void BTree::simVisit() {
  Nodo *aux;

  aux = head;

  printOSRic(aux);
}

void printPORic(Nodo *aux) {
  if (aux != NULL) {
    cout << aux->getDato() << " ";
    if (aux->getPs()) {
      printPORic(aux->getPs());
    }

    if (aux->getPd()) {
      printPORic(aux->getPd());
    }
  }
}

void BTree::preOrder() {
  Nodo *aux;

  aux = head;

  cout << aux->getDato();

  printPORic(aux);
}

void BTree::postOrder() {}
int main() {
  Nodo n;
  int valore;
  BTree b;

  /*cout<<"\nDigita valore\n===: ";
  cin >> valore;*/
  b.addChild(10);
  b.addChild(15);
  b.addChild(22);
  b.addChild(5);
  b.addChild(7);
  b.addChild(14);
  b.addChild(18);

  cout << "\nElementi in ordine crescente ";
  b.simVisit();

  cout << "\nElementi in pre ordine ";
  b.preOrder();

  system("pause");
  return 0;
}
