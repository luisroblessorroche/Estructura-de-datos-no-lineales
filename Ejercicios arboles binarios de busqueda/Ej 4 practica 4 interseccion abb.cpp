//Ej 4 practica 4
//Dados dos conjuntos representados mediante árboles binarios de búsqueda,
//implementa la operación intersección de dos conjuntos, que devuelva como resultado
//otro conjunto que sea la intersección de ambos. El resultado debe quedar en un árbol
//equilibrado.

template <typename T> void interseccion_abb(const Abb<T> &A, const Abb<T> &B)
{
	std::vector<T> vec_A;
	std::vector<T> vec_B;

	lectura_abb(A,vec_A);
	lectura_abb(B,vec_B);
	std::vector<T> vec_C;
	interseccion(vec_A,vec_B,vec_C);
	Abb<T> C = Abb();
	equilibrar_abb_interseccion(C,vec_C,vec_C.size()/2);
}

template <typename T> void lectura_abb(const Abb<T> &A, std::vector<T> vec_A)
{
	if(!A.vacio())
	{
		lectura_abb(A.izqdo(),vec_A);
		vec_A.push_back(A.elemento());
		lectura_abb(A.drcho(),vec_A);
	}
}

template <typename T> void lectura_abb_B(const Abb<T> &B, std::vector<T> vec_B)
{
	if(!B.vacio())
	{
		lectura_abb(B.izqdo(),vec_B);
		vec_B.push_back(B.elemento());
		lectura_abb(B.drcho(),vec_B);
	}
}

template <typename T> void interseccion(std::vector<T> vec_A, std::vector<T> vec_B, std::vector<T> vec_C)
{
	for(vec_A.iterator it = vec_A.begin(), it < vec_A.end(), it++)
	{
		bool ocurrencia_en_B = false;
		for(vec_B.iterator it2 = vec_B.begin(), it < vec_B.end() || !ocurrencia_en_B,it2++)
		{
			if(vec_A.at(it) == vec_B.at(it2))
			{
				vec_C.push_back(vec_A.at(it));
				ocurrencia_en_B = true;
			}
		}
	}
}

template <typename T> void equilibrar_abb_interseccion(Abb<T> &C, std::vector<T> vec_C,int mediana)
{
	C.insertar(vec_C.at(mediana));
	equilibrar_abb_interseccion(C,vec_C,(mediana-1)/2);
	equilibrar_abb_interseccion(C.vec_C,mediana+1 + vec_C.size()-(mediana+1)/2);
}