#include "Lista.h"

Lista::Lista() : _primer(NULL), _ultimo(NULL)
{

}

void Lista::Agregar(Elemento* elemento)
{
    /* IMPLEMENTE ESTE METODO
    Dado un objeto de tipo puntero a Elemento, agréguelo a la lista.
    
    Tenga en cuenta que el atributo _primer guarda un puntero al primer elemento de la lista y que _ultimo es un puntero al último elemento de la lista.
    */

    if (_primer != NULL)
    {
        _ultimo->SetSiguiente(elemento);
        _ultimo = elemento;
    }
    else
    {
        _primer = elemento;
        _ultimo = elemento;
    }
}

bool Lista::Eliminar(int indice)
{
    /* IMPLEMENTE ESTE METODO
    Dado un indice entero, elimine el objeto en esa posición. 
    Ejemplo: si el parámetro indice es igual a 0, se eliminará el primer elemento.
    
    Esta función retorna un booleano, retornando verdadero si el índice está contenido en la lista.
    Ejemplo: si la lista tiene 4 elementos y se pide eliminar el índice 9, este método retornará falso porque ese índice no está contenido en la lista.
    */

    if (indice >= 0)
    {
        if (indice == 0)
        {
            Elemento* elementoBorrado = _primer;
            _primer = _primer->GetSiguiente();
            delete elementoBorrado;
            return true;
        }
        else
        {
            Elemento* elementoAnterior = _primer;
            for (int i = 1; i < indice; i++)
            {
                elementoAnterior = elementoAnterior->GetSiguiente();
                if (elementoAnterior == NULL)
                    return false;  // El índice está fuera de los límites de la lista
            }

            Elemento* elementoBorrado = elementoAnterior->GetSiguiente();
            if (elementoBorrado != NULL)
            {
                elementoAnterior->SetSiguiente(elementoBorrado->GetSiguiente());
                if (elementoAnterior->GetSiguiente() == NULL)
                    _ultimo = elementoAnterior;
                delete elementoBorrado;
                return true;
            }
        }
    }

    return false;
}
