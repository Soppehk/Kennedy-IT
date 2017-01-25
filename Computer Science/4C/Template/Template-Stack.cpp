#include <iostream>
using namespace std;

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
////////////////////////////

template <class tipo>
class Stack{
      Nodo<tipo> *head;
      Nodo<tipo> *tail;
      int selezione;
      public:
          Stack();
          Stack(int d);
          ~Stack();
          void ins(tipo d);
          tipo estr();
          tipo top();
          bool empty();
          void stampa();
          
          void insLIFO(tipo d);
          void insFIFO(tipo d);
          void insOrdinato(tipo d);
          
          tipo estrLIFO();
          tipo estrFIFO();
          tipo estrOrdinato();
};

template <class tipo>
Stack<tipo>::Stack(){ 
	head = NULL;
	selezione = 1;
}

template <class tipo>
Stack<tipo>::Stack(int d){
	head = NULL;
	selezione = d;
	tail = NULL;
}

template <class tipo>
Stack<tipo>::~Stack(){ cout<<"\nDISTRUTTORE"; }

template <class tipo>
void Stack<tipo>::ins(tipo d){
     switch(selezione){
          case 1 : {
               insLIFO(d);
               } break;
               
          case 2 : {
               insFIFO(d);
               } break;
               
          case 3 : {
               insOrdinato(d);
               } break;
     }
}

template <class tipo>
void Stack<tipo>::insLIFO(tipo d){
	Nodo<tipo> *aux;
    aux = new Nodo<tipo>(d,head);
    head = aux;
}

template <class tipo>
void Stack<tipo>::insFIFO(tipo d){
	Nodo<tipo> *aux;
    aux = new Nodo<tipo>(d);
    if(tail == NULL){
    	head = aux;
    	tail = aux;
	}else{
		tail->setNext(aux);
		tail = aux;
	}
}

template <class tipo>
void Stack<tipo>::insOrdinato(tipo d){
    Nodo<tipo> *aux, *prec, *succ;
	aux = new Nodo<tipo>(d);
	
	
	if(aux != NULL)
	   cout<<"\nHo avuto la cella";

	if(head==NULL || (head->getDato())>d){
		aux->setNext(head);
		head = aux;
	}
	else{
		prec = head;
		succ = head->getNext();
		while(succ!=NULL && (succ->getDato())<(aux->getDato())){
			prec = prec->getNext();
			succ = succ->getNext();
		}
		prec->setNext(aux);
		aux->setNext(succ);
	}
	
}

template <class tipo>
tipo Stack<tipo>::estr(){
	tipo scelta;
    switch(selezione){
          case 1 : {
               scelta = estrLIFO();
               } break;
               
          case 2 : {
               scelta = estrFIFO();
               } break;
               
          case 3 : {
               scelta = estrOrdinato();
               } break;
     }
     return scelta;
}

template <class tipo>
tipo Stack<tipo>::estrLIFO(){
	tipo info;
    Nodo<tipo> *aux;
    
    info = head->getDato();
    aux = head;
    head = head->getNext();
    delete aux;
    
    return info;
}

template <class tipo>
tipo Stack<tipo>::estrFIFO(){
	tipo info;
    Nodo<tipo> *aux;
    
    info = head->getDato();
    aux = head;

    if(head == tail){
    	head = NULL;
    	tail = NULL;
	}
	else{
		head = head->getNext();
	}
	delete aux;
	
    return info;
}

template <class tipo>
tipo Stack<tipo>::estrOrdinato(){
	tipo info;
	Nodo<tipo> *aux;
	
	info = head->getDato();
	aux = head;
	head = head->getNext();
	delete(aux);
	
	return info;
}

template <class tipo>
tipo Stack<tipo>::top(){
     return head->getDato();
}

template <class tipo>
bool Stack<tipo>::empty(){
     return (head == NULL);
}

template <class tipo>
void Stack<tipo>::stampa(){
     Nodo<tipo> *aux;
     
     aux = head;
     cout<<"\n [ ";
     while(aux!=NULL){
         cout<<aux->getDato()<<", ";
         aux = aux->getNext();
         }
     cout<<"]";
}

int menu(){
    int s;
    system("cls");
		cout<<"\n _-_ GESTIONE LISTE _-_\n";
		cout<<"\n   1| INSERIMENTO \n   2| ESTRAZIONE \n   3| TOP";
		cout<<"\n   4| STAMPA TUTTI\n   0| ESCI \n\n ===: ";
		cin>>s;
		return s;
}

int menu2(){
    int s;
    system("cls");
		cout<<"\n _-_ SCELTA TIPO _-_\n";
		cout<<"\n   1| LIFO \n   2| FIFO";
		cout<<"\n   3| ORDINATO \n\n ===: ";
		do{
            cin>>s;
            if(s<1 || s>3) cout<<"\nErrore : Inserimento scorretto";
        }while(s<1 || s>3);
		
		return s;
}

int main(){
    Stack<int> pila(menu2());
	int scelta,n;
	
	do{
		scelta = menu();
		switch(scelta) {
			
			case 1 : {
				cout<<"\nInserisci il numero \n ===: ";
				cin>>n;
				pila.ins(n);
				break;
			}
			
			case 2 : {
				cout<<"\nNumero estratto : "<<pila.estr();
				break;
			}
			
			case 3 : {
				cout<<"\nNumero attuale : "<<pila.top();
				break;
			}
			
			case 4 : {
				cout<<"Pila attuale : ";
				pila.stampa();
				break;
			}
            
			case 0 : {
				cout<<"\nUscita...";
				break;
			}
			default: cout<<"\nErrore : Scelta non corretta";
		}
		
		cout<<endl<<endl<<endl;
		system("pause");
	}while(scelta != 0);
	
    getchar();
return 0;
}
