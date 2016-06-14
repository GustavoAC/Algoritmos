#ifndef _COMPACT_H_
#define _COMPACT_H_

#include <vector>

// Function prototypes.
template <typename T1, typename T2>
void compact( std::vector<T1> &_V, bool (*predicate)(T2) );

#include "compact.inl"

#endif
