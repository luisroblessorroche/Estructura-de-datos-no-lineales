//Practica 2 Ejercicio 1
//Dos árboles binarios son similares cuando tienen idéntica estructura de ramificación,
//es decir, ambos son vacíos, o en caso contrario, tienen subárboles izquierdo y derecho
//similares. Implementa un subprograma que determine si dos árboles binarios son
//similares.


template <typename T> bool abin_similares(const Abin<T> &A, const Abin<T> &B)
{
	return abin_similares_rec(A.raiz(),A,B.raiz(),B);
}

template <typename T> bool abin_similares_rec(typename Abin<T>::nodo n1, const Abin<T> &A, typename Abin<T>::nodo n2, const Abin<T> &B)
{
	if(n1 == Abin<T>::NODO_NULO || n2 == Abin<T>::NODO_NULO)
	{
		return (n1 == Abin<T>::NODO_NULO && n2 == Abin<T>::NODO_NULO);
	}
	else
	{
		return abin_similares_rec(A.hijoIzqdo(n1),A,B.hijoIzqdo(n2)) && abin_similares_rec(A.hijoDrcho(n1),A,B.hijoDrcho(n2),B);
	}
}