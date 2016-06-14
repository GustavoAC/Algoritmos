#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

//#include "functions.h"

int bus_seq_it( std::vector<long int> &V, long int k, long int l, long int r );

int bus_seq_rec( std::vector<long int> &V, long int k, long int l, long int r );

int bus_bin_it( std::vector<long int> &V, long int k, long int l, long int r );

int bus_bin_rec( std::vector<long int> &V, long int k, long int l, long int r );

int bus_ter_it( std::vector<long int> &V, long int k, long int l, long int r );

int bus_ter_rec( std::vector<long int> &V, long int k, long int l, long int r );

int wrap_sys_bsearch( std::vector<long int> &V, long int k, long int l, long int r );

int wrap_sys_search( std::vector<long int> &V, long int k, long int l, long int r );

int compare (const void* a, const void* b);

int wrapper ( std::vector<long int> &, long int, long int, long int, int, int,
              int ( *func ) ( std::vector<long int>&, long int, long int, long int ) );

void randomFill( std::vector<long int> &V, const int lower, const int upper, const unsigned long int seed);

long int casethree( std::vector<long int> &, const int, const unsigned long int, const int);

#endif