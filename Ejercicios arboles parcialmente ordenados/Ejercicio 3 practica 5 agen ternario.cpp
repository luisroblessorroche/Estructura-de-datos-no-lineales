/*
Ejercicio 3 practica apos y otros arboles:
Un árbol es estrictamente ternario si todos sus nodos son hojas o tienen tres hijos.
Escribe una función que, dado un árbol de grado arbitrario, nos indique si es o no
estrictamente ternario.
*/


template <typename T> bool agen_ternario(const Agen<T> &A)
{
	return agen_ternario_rec(A.raiz(),A);
}

template <typename T> bool agen_ternario_rec(typename Agen<T>::nodo n, const Agen<T> &A)
{
	if(n == Agen<T>::NODO_NULO)
	{
		return true;
	}
	else
	{
		return (nodo_es_hoja(n,A) || nodo_tiene_3_hijos(A.hijoIzqdo(n),A)) && agen_ternario_rec(A.hijoIzqdo(n),A) && agen_ternario_rec(A.hermDrcho(n),A);
	}
}

template <typename T> bool nodo_es_hoja(typename Agen<T>::nodo n, const Agen<T> &A)
{
	return A.hijoIzqdo(n) == Agen<T>::NODO_NULO;
}

template <typename T> bool nodo_tiene_3_hijos(typename Agen<T>::nodo n, const Agen<T> &A)
{
	n = A.hijoIzqdo(n);
	int cont = 0;
	while(n != Agen<T>::NODO_NULO)
	{
		cont++;
		n = A.hermDrcho(n);
	}
	return cont == 3;
}