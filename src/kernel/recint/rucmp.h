/* ruint/cmp.h - Comparison functions for ruint

Copyright Université Joseph Fourier - Grenoble
Contributors :
    Alexis BREUST (alexis.breust@gmail.com 2014)
    Christophe CHABOT (christophechabotcc@gmail.com 2011)

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


#ifndef RUINT_CMP_H
#define RUINT_CMP_H

#include "ruruint.h"

// --------------------------------------------------------------
// ----------------------- DEFINTIONS ---------------------------

namespace RecInt
{
    template <size_t K> bool operator==(const ruint<K>&, const ruint<K>&);
    template <size_t K, typename T> __RECINT_IS_ARITH(T, bool) operator==(const ruint<K>&, const T&);
    template <size_t K, typename T> __RECINT_IS_ARITH(T, bool) operator==(const T&, const ruint<K>&);

    template <size_t K> bool operator!=(const ruint<K>&, const ruint<K>&);
    template <size_t K, typename T> __RECINT_IS_ARITH(T, bool) operator!=(const ruint<K>&, const T&);
    template <size_t K, typename T> __RECINT_IS_ARITH(T, bool) operator!=(const T&, const ruint<K>&);

    template <size_t K> bool operator>(const ruint<K>&, const ruint<K>&);
    template <size_t K, typename T> __RECINT_IS_ARITH(T, bool) operator>(const ruint<K>&, const T&);
    template <size_t K, typename T> __RECINT_IS_ARITH(T, bool) operator>(const T&, const ruint<K>&);

    template <size_t K> bool operator>=(const ruint<K>&, const ruint<K>&);
    template <size_t K, typename T> __RECINT_IS_ARITH(T, bool) operator>=(const ruint<K>&, const T&);
    template <size_t K, typename T> __RECINT_IS_ARITH(T, bool) operator>=(const T&, const ruint<K>&);

    template <size_t K> bool operator<(const ruint<K>&, const ruint<K>&);
    template <size_t K, typename T> __RECINT_IS_ARITH(T, bool) operator<(const ruint<K>&, const T&);
    template <size_t K, typename T> __RECINT_IS_ARITH(T, bool) operator<(const T&, const ruint<K>&);

    template <size_t K> bool operator<=(const ruint<K>&, const ruint<K>&);
    template <size_t K, typename T> __RECINT_IS_ARITH(T, bool) operator<=(const ruint<K>&, const T&);
    template <size_t K, typename T> __RECINT_IS_ARITH(T, bool) operator<=(const T&, const ruint<K>&);

    // Compare a and b
    // returns -1 if a < b
    // returns  0 if a == b
    // returns +1 if a > b
    template <size_t K> int cmp(const ruint<K>& a, const ruint<K>& b);
    template <size_t K, typename T> inline __RECINT_IS_UNSIGNED(T, int) cmp(const ruint<K>& a, const T& b);
    template <size_t K, typename T> inline __RECINT_IS_SIGNED(T, int) cmp(const ruint<K>& a, const T& b);
}


// --------------------------------------------------------------
// --------------------- IMPLEMENTATION -------------------------

namespace RecInt
{
    // Operator ==
    template <size_t K> inline bool operator==(const ruint<K>& a, const ruint<K>& b) {
        return cmp(a, b) == 0;
    }
    template <size_t K, typename T>
    inline __RECINT_IS_ARITH(T, bool) operator==(const ruint<K>& a, const T& b) {
        return cmp(a, b) == 0;
    }
    template <size_t K, typename T>
    inline __RECINT_IS_ARITH(T, bool) operator==(const T& b, const ruint<K>& a) {
        return cmp(a, b) == 0;
    }

    // Operator !=
    template <size_t K> inline bool operator!=(const ruint<K>& a, const ruint<K>& b) {
        return cmp(a, b) != 0;
    }
    template <size_t K, typename T>
    inline __RECINT_IS_ARITH(T, bool) operator!=(const ruint<K>& a, const T& b) {
        return cmp(a, b) != 0;
    }
    template <size_t K, typename T>
    inline __RECINT_IS_ARITH(T, bool) operator!=(const T& b, const ruint<K>& a) {
        return cmp(a, b) != 0;
    }

    // Operator >
    template <size_t K> inline bool operator>(const ruint<K>& a, const ruint<K>& b) {
        return cmp(a, b) > 0;
    }
    template <size_t K, typename T>
    inline __RECINT_IS_ARITH(T, bool) operator>(const ruint<K>& a, const T& b) {
        return cmp(a, b) > 0;
    }
    template <size_t K, typename T>
    inline __RECINT_IS_ARITH(T, bool) operator>(const T& b, const ruint<K>& a) {
        return cmp(a, b) < 0;
    }

    // Operator >=
    template <size_t K> inline bool operator>=(const ruint<K>& a, const ruint<K>& b) {
        return cmp(a, b) >= 0;
    }
    template <size_t K, typename T>
    inline __RECINT_IS_ARITH(T, bool) operator>=(const ruint<K>& a, const T& b) {
        return cmp(a, b) >= 0;
    }
    template <size_t K, typename T>
    inline __RECINT_IS_ARITH(T, bool) operator>=(const T& b, const ruint<K>& a) {
        return cmp(a, b) <= 0;
    }

    // Operator <
    template <size_t K> inline bool operator<(const ruint<K>& a, const ruint<K>& b) {
        return cmp(a, b) < 0;
    }
    template <size_t K, typename T>
    inline __RECINT_IS_ARITH(T, bool) operator<(const ruint<K>& a, const T& b) {
        return cmp(a, b) < 0;
    }
    template <size_t K, typename T>
    inline __RECINT_IS_ARITH(T, bool) operator<(const T& b, const ruint<K>& a) {
        return cmp(a, b) > 0;
    }

    // Operator <=
    template <size_t K> inline bool operator<=(const ruint<K>& a, const ruint<K>& b) {
        return cmp(a, b) <= 0;
    }
    template <size_t K, typename T>
    inline __RECINT_IS_ARITH(T, bool) operator<=(const ruint<K>& a, const T& b) {
        return cmp(a, b) <= 0;
    }
    template <size_t K, typename T>
    inline __RECINT_IS_ARITH(T, bool) operator<=(const T& b, const ruint<K>& a) {
        return cmp(a, b) >= 0;
    }


    //----------- COMPARE ------------

    // returns -1 if a < b
    // returns  0 if a == b
    // returns +1 if a > b
    template <size_t K> inline int cmp(const ruint<K>& a, const ruint<K>& b) {
        int ch;
        ch = cmp(a.High, b.High);
        if (ch == 0) return cmp(a.Low, b.Low);
        return ch;
    }
    template <> inline int cmp(const ruint<__RECINT_LIMB_SIZE>& a, const ruint<__RECINT_LIMB_SIZE>& b) {
        if (a.Value < b.Value) return -1;
        else if (a.Value == b.Value) return 0;
        else return 1;
    }

    //---- Unsigned ----
    template <size_t K, typename T> inline __RECINT_IS_UNSIGNED(T, int) cmp(const ruint<K>& a, const T& b) {
        if (a.High == 0) return cmp(a.Low, b);
        else return 1;
    }
    template <typename T> inline __RECINT_IS_UNSIGNED(T, int) cmp(const ruint<__RECINT_LIMB_SIZE>& a, const T& b) {
        if (a.Value < b) return -1;
        else if (a.Value == b) return 0;
        else return 1;
    }

    //---- Signed ----
    template <size_t K, typename T> inline __RECINT_IS_SIGNED(T, int) cmp(const ruint<K>& a, const T& b) {
        if (b < 0) return 1;
        else if (a.High == 0) return cmp(a.Low, b);
        else return 1;
    }
    template <typename T> inline __RECINT_IS_SIGNED(T, int) cmp(const ruint<__RECINT_LIMB_SIZE>& a, const T& b) {
        if (b < 0) return 1;
        else if (a.Value < limb(b)) return -1;
        else if (a.Value == limb(b)) return 0;
        else return 1;
    }
}

#endif

/* -*- mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
// vim:sts=4:sw=4:ts=4:et:sr:cino=>s,f0,{0,g0,(0,\:0,t0,+0,=s
