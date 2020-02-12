#ifndef LISTADOBLEC_H_INCLUDED
#define LISTADOBLEC_H_INCLUDED
template<class T>
class ListaDobleC
{
    class Nodo{
    public:
        Nodo(T x)
        {
            next = 0;
            before = 0;
            dato = x;
        }

        Nodo *getNext(){ return next;}
        Nodo *getBefore() {return before;}
        void setNext(Nodo *n) { next = n;}
        void setBefore(Nodo *n){ before = n;}
        T getDato(){ return dato;}
     private:
        Nodo *next;
        Nodo *before;
        T dato;
    };
     public:
         ListaDobleC()
         {
             first = 0;
             size = 0;
         }

         int getSize(){return size;}
         void add_first(T dato);
         void add_last(T dato);
         void add_at(T dato, int index);
         T get_element_at(int index);

     private:
         bool isEmpty(){return size == 0;}
         int size;
         Nodo *first;
};

template<class T>
void ListaDobleC<T>::add_first(T dato)
{
    Nodo *n = new Nodo(dato);
    if(this->isEmpty())
    {
        this->first = n;
        this->first->setBefore(n);
        this->first->setNext(n);
        this->size++;
    }
    else
    {
        n->setNext(this->first);
        n->setBefore(this->first->getBefore());
        this->first->getBefore()->setNext(n);
        this->first->setBefore(n);
        this->first = n;
        this->size++;
    }
}

template<class T>
void ListaDobleC<T>::add_last(T dato)
{
    if(this->isEmpty())
    {
        this->add_first(dato);
    }
    else
    {
        Nodo *n = new Nodo(dato);
        this->first->getBefore()->setNext(n);
        n->setBefore(this->first->getBefore());
        n->setNext(this->first);
        this->first->setBefore(n);
        this->size++;
    }
}

template<class T>
void ListaDobleC<T>::add_at(T dato, int index)
{
    int v = 0;
    if(index >= 0 && index <= this->size)
    {
        if(index == 0){ this->add_first(dato); return;}
        if(index == this->size) {this->add_last(dato); return;}
        Nodo *aux = this->first;
        int x = 0;
        while(aux!=0 && v!= 0 )
        {
            if(x == index){break;}
            aux = aux->getNext();
            x++;
            if(x = size -1 ){v=1;}
        }
        Nodo *n = new Nodo(dato);
        aux->getBefore()->setNext(n);
        n->setBefore(aux->getBefore());
        n->setNext(aux);
        aux->setBefore(n);
        this->size++;
    }
}

template<class T>
T ListaDobleC<T>::get_element_at(int index)
{
    int v = 0;
    if(index >= 0 && index < size)
    {
        Nodo *iterador = this->first;
        int x = 0;
        while(iterador!=0 && v!= 0)
        {
            if(index == x){return iterador->getDato();}
            iterador = iterador->getNext();
            x++;
            if(x = size -1 ){v=1;}
        }
    }
    return 0;
}


#endif // LISTADOBLE_H_INCLUDED
