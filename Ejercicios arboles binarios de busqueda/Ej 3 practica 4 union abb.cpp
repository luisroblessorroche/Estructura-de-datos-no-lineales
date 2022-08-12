//Ej 3 practica 4 uniones dos conjuntos
//Dados dos conjuntos representados mediante árboles binarios de búsqueda,
//implementa la operación unión de dos conjuntos que devuelva como resultado otro
//conjunto que sea la unión de ambos, representado por un ABB equilibrado.


template <typename T> void union_abb(const Abb<T> &A, const Abb<T> &B)
{
	std::vector<T> vec_A;
	std::vector<T> vec_B;

	lectura_abb(A,vec_A);
	lectura_abb(B,vec_B);
	std::vector<T> vec_C;
	union(vec_A,vec_B,vec_C);
	Abb<T> C = Abb();
	equilibrar_abb_union(C,vec_C,vec_C.size()/2);
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

template <typename T> void union(std::vector<T> vec_A, std::vector<T> vec_B, std::vector<T> &vec_C)
{
	for(vec_A.iterator it = vec_A.begin(), it < vec_A.end(),it++)
	{
		vec_C.push_back(vec_A.at(it));
	}

	for(vec_B.iterator it2 = vec_B.begin(), it2 < vec_B.end(),it++)
	{
		bool existe_en_vec_C = false;
		for(vec_C.iterator it3 = vec_C.begin(),it3 < vec_C.end(),it3++)
		{
			if(vec_B.at(it2) == vec_C.at(it3))
			{
				bool existe_en_vec_C = true;
			}
		}
		if(!existe_en_vec_C)
		{
			vec_C.push_back(vec_B.at(it2));
		}
	}
}

template <typename T> void equilibrar_abb_union(Abb<T> &C, std::vector<T> vec_C,int mediana)
{
	C.insertar(vec_C.at(mediana));
	equilibrar_abb_union(C,vec_C,(mediana-1)/2);
	equilibrar_abb_union(C.vec_C,mediana+1 + vec_C.size()-(mediana+1)/2);
}