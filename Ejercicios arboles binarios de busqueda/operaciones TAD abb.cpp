//operaciones TAD abb

//precondicion:
//postcondicion: construye un arbol binario de busqueda vacio
Abb()

//precondicion:
//postcondicion:si el elemento e pertenece al arbol, devuelve el subarbol
//donde se encuentra, si no, devuelve un arbol vacio
const Abb& buscar(const T& e) const

//precondicion:
//postcondicion:si e no pertenece al arbol, lo inserta. En caso contrario, no se modifica
void insertar(const T& e)

//precondicion:
//postcondicion:elimina el elemento e del arbol en caso de estar
void eliminar(const T& e)

//precondicion:
//postcondicion: devuelve true si el arbol esta vacio y false si no
bool vacio() const

//precondicion: el arbol no esta vacio
//postcondicion: devuelve el elemento de la raiz del abb
const T& elemento() const

//precondicion: arbol no vacio
//postcondicion: devuelve el subarbol izqdo
const Abb& izqdo() const

//precondicion: arbol no vacio
//postcondicion: devuelve el subarbol drcho
const Abb& drcho() const
