#ifndef SORT_CPP_H
#define SORT_CPP_H

#include <set>

namespace SortCpp
{

	template<class T>
	void BubbleSort( T* l, T* r )
	{
		if ( ( r - l ) <= 1 ) return;

		bool is_sorted = false;
		while(!is_sorted)
		{
			is_sorted = true;
			for( T* i = l; i + 1 < r; i++ )
			{
				if( *i > *(i + 1) )
				{
					T tmp = *i;
					*i = *(i + 1);
					*(i + 1) = tmp;

					is_sorted = false;
				}
			}
			r--;
		}
	}

	template<class T>
	void SelectionSort( T* l, T* r )
	{
		if ( ( r - l ) <= 1 ) return;

		for ( T* i = l; i < r; i++ )
		{
			for ( T* j = i + 1; j < r; j++ )
			{
				if ( *i > *j )
				{
					T tmp = *i;
					*i = *j;
					*j = tmp;
				}
			}
		}
	}

	template<class T>
	void InsertionSort( T* l, T* r )
	{
		if ( ( r - l ) <= 1 ) return;

		for( T* i = l + 1; i < r; i++ )
		{
			T* j = i;
			while( j > l && *(j - 1) > *j )
			{
				T tmp = *(j - 1);
				*(j - 1) = *j;
				*j = tmp;

				j--;
			}
		}
	}
	
	template<class T>
	void ShellSort( T* l, T* r )
	{
		unsigned long sz = r - l;
		if ( sz <= 1 ) return;

		unsigned long gap = sz / 2;
		while( gap >= 1 )
		{
			for( T* i = l + gap; i < r; i++ )
			{
				T* j = i;
				T* diff = j - gap;
				while( diff >= l && *diff > *j )
				{
					T tmp = *diff;
					*diff = *j;
					*j = tmp;

					j = diff;
					diff = j - gap;
				}
			}
			gap /= 2;
		}
	}

	template<class T>
	void TreeSort( T* l, T* r )
	{
		if ( ( r - l ) <= 1 ) return;

		std::multiset<T> m;
		for( T* i = l; i < r; i++ ) m.insert(*i);
		for( T q : m ) *l = q, l++;
	}

	template<class T>
	void MergeSort( T* l, T* r )
	{
		T* temp = new T[r - l];
		_mergesort<T>( l, r, temp );
		delete[] temp;
	}
	template<class T>
	void _mergesort( T* l, T* r, T* temp )
	{
		if ( ( r - l ) <= 1 ) return;

		T* m = l + (r - l) / 2;
		_mergesort<T>( l, m, temp );
		_mergesort<T>( m, r, temp );
		_merge<T>( l, m, r, temp );
	}
	template<class T>
	void _merge( T* l, T* m, T* r, T* temp )
	{
		T *cl = l, *cr = m, cur = 0;
		while( cl < m && cr < r )
		{
			if( *cl < *cr ) temp[cur++] = *cl, cl++;
			else temp[cur++] = *cr, cr++;
		}
		while( cl < m ) temp[cur++] = *cl, cl++;
		while( cr < r ) temp[cur++] = *cr, cr++;
		cur = 0;
		for( T* i = l; i < r; i++ ) *i = temp[cur++];
	}

	template<class T>
	void QuickSort( T* l, T* r )
	{
		if( (r - l) <= 1 ) return;

		T z = *( l + ( r - l ) / 2 );	// Pivot = median
		T *ll = l, *rr = r - 1;
		while( ll <= rr )
		{
			while( *ll < z ) ll++;
			while ( *rr > z ) rr--;
			if( ll <= rr )
			{
				T tmp = *ll;
				*ll = *rr;
				*rr = tmp;

				ll++;
				rr--;
			}
		}
		if( l < rr ) QuickSort( l, rr + 1 );
		if( ll < r ) QuickSort( ll, r );
	}

}

#endif // SORT_CPP_H
