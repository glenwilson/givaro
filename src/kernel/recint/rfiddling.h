/* rint/fiddling.h - Bits manipulation for rint

   Copyright Université Joseph Fourier - Grenoble
Contributors :
Alexis BREUST (alexis.breust@gmail.com 2014)
Jean-Guillaume DUMAS

Time-stamp: <14 May 19 17:37:51 Jean-Guillaume.Dumas@imag.fr>

This software is a computer program whose purpose is to provide an fixed precision arithmetic library.

This software is governed by the CeCILL-B license under French law and
abiding by the rules of distribution of free software.  You can  use,
modify and/ or redistribute the software under the terms of the CeCILL-B
license as circulated by CEA, CNRS and INRIA at the following URL
"http://www.cecill.info".

As a counterpart to the access to the source code and  rights to copy,
modify and redistribute granted by the license, users are provided only
with a limited warranty  and the software's author,  the holder of the
economic rights,  and the successive licensors  have only  limited
liability.

In this respect, the user's attention is drawn to the risks associated
with loading,  using,  modifying and/or developing or reproducing the
software by the user in light of its specific status of free software,
that may mean  that it is complicated to manipulate,  and  that  also
therefore means  that it is reserved for developers  and  experienced
professionals having in-depth computer knowledge. Users are therefore
encouraged to load and test the software's suitability as regards their
requirements in conditions enabling the security of their systems and/or
data to be ensured and,  more generally, to use and operate it in the
same conditions as regards security.

The fact that you are presently reading this means that you have had
knowledge of the CeCILL-B license and that you accept its terms.
*/


#ifndef RINT_FIDDLING_H
#define RINT_FIDDLING_H

#include "rrint.h"
#include "rufiddling.h"

// --------------------------------------------------------------
// ----------------------- DEFINTIONS ---------------------------

namespace RecInt
{
    template <size_t K> rint<K> operator~(const rint<K>& c);
    template <size_t K> rint<K> operator-(const rint<K>& c);

    template <size_t K> rint<K>& operator|=(rint<K>& b, const rint<K>& c);
    template <size_t K> rint<K>& operator^=(rint<K>& b, const rint<K>& c);
    template <size_t K> rint<K>& operator&=(rint<K>& b, const rint<K>& c);

    template <size_t K, typename T> __RECINT_IS_ARITH(T, rint<K>&) operator|=(rint<K>& b, const T& c);
    template <size_t K, typename T> __RECINT_IS_ARITH(T, rint<K>&) operator^=(rint<K>& b, const T& c);
    template <size_t K, typename T> __RECINT_IS_ARITH(T, rint<K>&) operator&=(rint<K>& b, const T& c);

    template <size_t K> rint<K> operator|(const rint<K>& b, const rint<K>& c);
    template <size_t K> rint<K> operator^(const rint<K>& b, const rint<K>& c);
    template <size_t K> rint<K> operator&(const rint<K>& b, const rint<K>& c);

    template <size_t K, typename T> __RECINT_IS_ARITH(T, rint<K>) operator|(const rint<K>& b, const T& c);
    template <size_t K, typename T> __RECINT_IS_ARITH(T, rint<K>) operator^(const rint<K>& b, const T& c);
    template <size_t K, typename T> __RECINT_IS_ARITH(T, T) operator&(const rint<K>& b, const T& c);

    template <size_t K, typename T> rint<K> operator<<(const rint<K>&, const T&);
    template <size_t K, typename T> rint<K> operator>>(const rint<K>&, const T&);
    template <size_t K, typename T> rint<K>& operator<<=(rint<K>&, const T&);
    template <size_t K, typename T> rint<K>& operator>>=(rint<K>&, const T&);

}


// --------------------------------------------------------------
// ----------------------- Operators ----------------------------

namespace RecInt
{
    // Operator ~
    template <size_t K> inline rint<K> operator~(const rint<K>& c) {
        return rint<K>(~c.Value);
    }

    // Operator - unary
    template <size_t K> inline rint<K> operator-(const rint<K>& c) {
        return rint<K>(-c.Value);
    }

    // Operator |=
    template <size_t K> inline rint<K>& operator|=(rint<K>& b, const rint<K>& c) {
        b.Value |= c.Value;
        return b;
    }

    // Operator ^=
    template <size_t K> inline rint<K>& operator^=(rint<K>& b, const rint<K>& c) {
        b.Value ^= c.Value;
        return b;
    }
    template <size_t K, typename T> inline __RECINT_IS_ARITH(T, rint<K>&) operator^=(rint<K>& b, const T& c) {
        b.Value ^= c;
        return b;
    }

    // Operator &=
    template <size_t K> inline rint<K>& operator&=(rint<K>& b, const rint<K>& c) {
        b.Value &= c.Value;
        return b;
    }
    template <size_t K, typename T> inline __RECINT_IS_ARITH(T, rint<K>&) operator&=(rint<K>& b, const T& c) {
        b.Value &= c;
        return b;
    }

    // Operator |
    template <size_t K> inline rint<K> operator|(const rint<K>& b, const rint<K>& c) {
        return rint<K>(b.Value | c.Value);
    }

    // Operator &
    template <size_t K> inline rint<K> operator&(const rint<K>& b, const rint<K>& c) {
        return rint<K>(b.Value & c.Value);
    }

    // Operator ^
    template <size_t K> inline rint<K> operator^(const rint<K>& b, const rint<K>& c) {
        return rint<K>(b.Value ^ c.Value);
    }

        // Shifts
    template <size_t K, typename T> rint<K>& operator<<=(rint<K>& b, const T& c) {
        b.Value <<= c;
        return b;
    }

    template <size_t K, typename T> rint<K>& operator>>=(rint<K>& b, const T& c) {
        b.Value >>= c;
        return b;
    }

    template <size_t K, typename T> rint<K> operator<<(const rint<K>& b, const T& c) {
        rint<K> r(b);
        return r <<= c;
    }

    template <size_t K, typename T> rint<K> operator>>(const rint<K>& b, const T& c) {
        rint<K> r(b);
        return r >>= c;
    }

}

#endif

/* -*- mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
// vim:sts=4:sw=4:ts=4:et:sr:cino=>s,f0,{0,g0,(0,\:0,t0,+0,=s
