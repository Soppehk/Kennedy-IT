template <class tipo>
class Nodo{
      tipo dato;
      Nodo<tipo> *next;
      public:
          Nodo();
          Nodo(tipo d);
          Nodo(tipo d, Nodo<tipo> *n);
          void setDato(tipo d);
          tipo getDato();
          void setNext(Nodo<tipo> *n);
          Nodo<tipo> *getNext();
};
 
template <class tipo>
Nodo<tipo>::Nodo(){ next = NULL; }
 
template <class tipo>
Nodo<tipo>::Nodo(tipo d){ dato = d; next = NULL; }
 
template <class tipo>
Nodo<tipo>::Nodo(tipo d, Nodo<tipo> *n){ dato = d; next = n; }
 
template <class tipo>
void Nodo<tipo>::setDato(tipo d){ dato = d; }
 
template <class tipo>
tipo Nodo<tipo>::getDato(){ return dato; }
 
template <class tipo>
Nodo<tipo> *Nodo<tipo>::getNext(){ return next; }
 
template <class tipo>
void Nodo<tipo>::setNext(Nodo<tipo> *n){ next = n; }
