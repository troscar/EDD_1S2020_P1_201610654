#ifndef LISTASENLAZADA_H_INCLUDED
#define LISTASENLAZADA_H_INCLUDED
template<class T>
class Lista
{
    class Nodo{
    public:
        Nodo(T x)
        {
            next = 0;
            dato = x;
        }

        Nodo *getNext(){ return next;}
        void setNext(Nodo *n) { next = n;}
        T getDato(){ return dato;}
     private:
        Nodo *next;
        T dato;
    };
     public:
         Lista()
         {
             first = 0;
             last = 0;
             size = 0;
         }

         int getSize(){return size;}
         void add_first(T dato);
         void add_last(T dato);
         void add_at(T dato, int index);
         T get_element_at(int index);
         void remove_at(int index);

     private:
         bool isEmpty(){return size == 0;}
         int size;
         Nodo *first;
         Nodo *last;
};

template<class T>
void Lista<T>::add_first(T dato)
{
    Nodo *n = new Nodo(dato);
    if(this->isEmpty())
    {
        this->first = n;
        this->last = n;
        this->size++;
    }
    else
    {
        n->setNext(this->first);
        this->first = n;
        this->size++;
    }
}

template<class T>
void Lista<T>::add_last(T dato)
{
    if(this->isEmpty())
    {
        this->add_first(dato);
    }
    else
    {
        Nodo *n = new Nodo(dato);
        this->last->setNext(n);
        this->last = n;
        this->size++;
    }
}

template<class T>
void Lista<T>::add_at(T dato, int index)
{
    if(index >= 0 && index <= this->size)
    {
        if(index == 0){ this->add_first(dato); return;}
        if(index == this->size) {this->add_last(dato); return;}
        Nodo *aux = this->first;
        Nodo *aux2 = 0;
        int x = 0;
        while(aux!=0)
        {
            if(x == index){break;}
            aux2 = aux;
            aux = aux->getNext();
            x++;
        }
        Nodo *n = new Nodo(dato);
        aux2->setNext(n);
        n->setNext(aux);
        this->size++;
    }
}

template<class T>
T Lista<T>::get_element_at(int index)
{
    if(index >= 0 && index < size)
    {
        Nodo *iterador = this->first;
        int x = 0;
        while(iterador!=0)
        {
            if(index == x){return iterador->getDato();}
            iterador = iterador->getNext();
            x++;
        }
    }
    return 0;
}



#endif // LISTASIMPLE_H_INCLUDED
