#ifndef COLAGENERICA_H_INCLUDED
#define COLAGENERICA_H_INCLUDED

template <class T> // DECLARA QUE SE UTILIZARA UN TEMPLATE
class Cola
{
    class Nodo
    {
        public:
            // CONSTRUCTOR DEL NODO, RECIBE UN DATO GENERICO T
            Nodo(T x)
            {
                dato = x;
                next = 0;
            }

            // SETTERS Y GETTERS...
            void setNext(Nodo *n)
            {
                next = n;
            }

            Nodo *getNext()
            {
                return next;
            }

            T getDato()
            {
                return dato;
            }

        private:
            // ATRIBUTOS PRIVADOS DEL NODO
            Nodo *next;
            T dato;
    };

    public:
        // CONSTRUCTOR DE LA PILA
        Cola<T>()
        {
            first = 0; // LA CIMA APUNTA A NULO
            last = 0;
            size = 0; // LA CANTIDAD DE ELEMENTOS ES 0 AL INICIO

        }

        //DECLARACION DE METODOS
        bool estaVacia();
        void push(T dato);
        T pop();
        T peek();

    private:
        Nodo *first;
        Nodo *last;
        int size;

};

// IMPEMENTACION DE LOS METDODOS DELCARADOS EN LA CLASE PILA
template<class T>
bool Cola<T>::estaVacia()
{
    return this->size == 0;
}

// INSERTA UN ELEMENTO EN LA PILA
template<class T>
void Cola<T>::push(T dato)
{
    Nodo *n = new Nodo(dato);
    if(estaVacia())
    {
         this->first = n;
        this->last = n;
        this->size++;
    }
    else
    {
         Nodo *n = new Nodo(dato);
        this->last->setNext(n);
        this->last = n;
        this->size++;
    }
}

// REMUEVE UN ELEMENTO EN LA CIMA DE LA PILA
template<class T>
T Cola<T>::pop()
{
    T aux = this->first->getDato();
    this->first = this->first->getNext();
    this->size--;
    return aux;
}

// SOLO PERMITE DEVOLVER EL ELEMENTO EN LA CIMA PERO NO LA REMUEVE
template<class T>
T Cola<T>::peek()
{
    T aux = this->first->getDato();
    return aux;
}

#endif // COLAGENERICA_H_INCLUDED
