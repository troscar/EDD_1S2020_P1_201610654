#ifndef PILAGENERICA_H_INCLUDED
#define PILAGENERICA_H_INCLUDED

template <class T> // DECLARA QUE SE UTILIZARA UN TEMPLATE
class Pila
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
        Pila<T>()
        {
            cima = 0; // LA CIMA APUNTA A NULO
            size = 0; // LA CANTIDAD DE ELEMENTOS ES 0 AL INICIO
        }

        //DECLARACION DE METODOS
        bool estaVacia();
        void push(T dato);
        T pop();
        T peek();

    private:
        Nodo *cima;
        int size;

};

// IMPEMENTACION DE LOS METDODOS DELCARADOS EN LA CLASE PILA
template<class T>
bool Pila<T>::estaVacia()
{
    return this->size == 0;
}

// INSERTA UN ELEMENTO EN LA PILA
template<class T>
void Pila<T>::push(T dato)
{
    Nodo *n = new Nodo(dato);
    if(estaVacia())
    {
        this->cima = n;
        this->size++;
    }
    else
    {
        n->setNext(this->cima);
        this->cima = n;
        this->size++;
    }
}

// REMUEVE UN ELEMENTO EN LA CIMA DE LA PILA
template<class T>
T Pila<T>::pop()
{
    T aux = this->cima->getDato();
    this->cima = this->cima->getNext();
    this->size--;
    return aux;
}

// SOLO PERMITE DEVOLVER EL ELEMENTO EN LA CIMA PERO NO LA REMUEVE
template<class T>
T Pila<T>::peek()
{
    T aux = this->cima->getDato();
    return aux;
}

#endif // PILAGENERICA_H_INCLUDED
