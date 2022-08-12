//Ej 1 practica 4
//Implementa una nueva operación (nos dijeron que lo cambiaramos por un subprograma) del TAD Abb 
//que tomando un elemento del mismo elimine al completo el subárbol que cuelga de él.

void eliminar_subarbol(Abb<int> &A,int x)
{
	 if(A.buscar(x) != A.vacio())
	 {
	 	A = A.buscar(x);
	 	while(!A.vacio())
	 	{
	 		A.eliminar(A.elemento());
	 	}
	 }
}


