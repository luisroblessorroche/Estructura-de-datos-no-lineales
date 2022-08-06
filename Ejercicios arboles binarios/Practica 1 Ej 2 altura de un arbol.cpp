//Ejercicio 2 practica 1
//Implementa un subprograma que calcule la altura de un árbol binario.

template <typename T> int contar_altura(const Abin<T> &A)
{
	return contar_altura_rec(A.raiz(),A);
}

template <typename T> int contar_altura_rec(const Abin<T>::nodo n, const Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return -1;
	}
	else
	{
		return 1 + max(contar_altura_rec(A.hijoIzqdo(n),A),contar_altura_rec(A.hijoDrcho(n),A));
	}
}