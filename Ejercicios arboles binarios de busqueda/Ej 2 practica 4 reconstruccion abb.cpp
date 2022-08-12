//Ej 2 practica 4
//Un árbol binario de búsqueda se puede equilibrar realizando el recorrido en inorden
//del árbol para obtener el listado ordenado de sus elementos y a continuación, repartir
//equitativamente los elementos a izquierda y derecha colocando la mediana en la raíz y
//construyendo recursivamente los subárboles izquierdo y derecho de cada nodo.
//Implementa este algoritmo para equilibrar un ABB.

template <typename T> void equilibrar_abb(Abb<T> &A)
{
	std::vector<T> vec;
	lectura_abb(vec,A);
	vaciar_abb(A);
	reconstruccion_abb(vec.size()/2;,A);
}

template <typename T> void lectura_abb(std::vector<T> vec, Abb<T> &A)
{
	if(!A.vacio())
	{
		izqdo();
		vec.push_back(A.elemento());
		drcho();
	}
}

template <typename T> void vaciar_abb(Abb<T> &A)
{
	while(!A.vacio())
	{
		A.eliminar(A.elemento());
	}
}

template <typename T> void reconstruccion_abb(std::vector vec,int mediana, Abb<T> &A)
{
	if(med >= 0 || med <= vec.size())
	{
		A.insertar(vec.at(mediana));
		reconstruccion_abb(vec,(mediana-1)/2,A);
		reconstruccion_abb(vec,(mediana+1 + vec.size()-mediana+1)/2,A);
	}
}



