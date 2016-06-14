#ifndef DOUBLE_ARRAY_H
#define DOUBLE_ARRAY_H

#include <new>
using std::bad_alloc;

#include <stdexcept>
#include <iostream>

template< typename T >
void DoubleArray ( T *(&vet), int &tam )
{
    // 1) Alocar a nova memoria
	T *newVet = new T[tam*2];

    // 2) Copiar valores de A para o novo vetor
	for (int i = 0; i < tam; ++i){
		newVet[i] = vet[i];
	}

    // 3) Liberar a memoria associada ao ponteiro A
	delete [] vet;

    // 4) Fazer o A apontar p/ a nova memoria
	vet = newVet;

    // 5) Atualizar o novo tamanho do arranjo A.
    tam *= 2;
}

#endif

/* ------------------- [ End of the doublearray.h source ] ------------------- */
/* =========================================================================== */
