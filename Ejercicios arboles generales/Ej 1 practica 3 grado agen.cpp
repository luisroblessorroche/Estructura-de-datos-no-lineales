//Ejercicio 1 practica 3
//Implementa un subprograma que dado un árbol general nos calcule su grado.


template <typename T> int grado_agen(const Agen<T> &A)
{
	return grado_agen_rec(A.raiz(), A);
}

template <typename T> int grado_agen_rec(typename Agen<T>::nodo n, const Agen<T> &A)
{
	if(n == Agen<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		int grado = grado_nodo(n,A);
		return max3(grado, grado_agen_rec(A.hijoIzqdo(n)),grado_agen_rec(A.hermDrcho(n)));
	}
}

template <typename T> int grado_nodo(typename Agen<T>::nodo n, const Agen<T> &A)
{
	int cont = 0;
	n = A.hijoIzqdo(n);
	while(n != Agen<T>::NODO_NULO)
	{
		cont++;
		n = A.hermDrcho(n);
	}
	return cont;
}