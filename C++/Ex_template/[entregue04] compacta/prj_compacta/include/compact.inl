#include <vector>

#include "compact.h"

template <typename T1, typename T2>
void compact( std::vector<T1> &_V, bool (*predicate)(T2) )
{
    auto iSlow(0ul);
    auto iFast(0ul);
    for( /* empty */ ; iFast < _V.size() ; ++iFast )
    {
        if( predicate( _V[ iFast ] ) )
            _V[ iSlow++ ] = _V[ iFast ];
    }
    _V.resize( iSlow ); // New vector size.
}

