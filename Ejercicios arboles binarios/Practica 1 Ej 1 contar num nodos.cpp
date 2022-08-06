// Ejercicio 1 practica 1
//Implementa un subprograma que calcule el número de nodos de un árbol binario. 


template <typename T> int contar_num_nodos(const Abin<T> &A)
{
	return contar_num_nodos_rec(A.raiz(),A);
}

template <typename T> int contar_num_nodos_rec(const Abin<T>::nodo n, const Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		return 1 + contar_num_nodos_rec(A.hijoIzqdo(n),A) + contar_num_nodos_rec(A.hijoDrcho(n),A);
	}
}