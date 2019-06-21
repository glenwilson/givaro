// ========================================================================
// Copyright(c)'1994-2015 by The Givaro group
// This file is part of Givaro.
// Givaro is governed by the CeCILL-B license under French law
// and abiding by the rules of distribution of free software.
// see the COPYRIGHT file for more details.
// Authors: A. Breust
// Time-stamp: <28 May 15 09:40:00 Alexis.Breust@imag.fr>
// ========================================================================
// Description:
// Forward declarations for Givaro::Modular and associated functions

#pragma once

namespace Givaro
{
    /*! Forward declaration for Givaro::Modular.
     *  Elements will be stored in the storage type.
     *  While arithmetics will occur on the unsigned version of COMP type.
     *  Example: Modular<int32_t, uint64_t>
     */
    //template<typename Storage_t, typename COMP = Storage_t> class Modular;
    template<typename _Rational_t, typename _Integer_t> class PLocal;

    //! Generalized extended GCD used by specialized Modular.
    // template<typename Storage_t>
    // inline Storage_t& gcdext(Storage_t& d,  Storage_t& u, Storage_t& v, const Storage_t a, const Storage_t b);

    //! Generalized inversion used by specialized Modular.
    // template<typename _Rational_t , typename _Integer_t>
    // inline _Rational_t& invext(_Rational_t& u, const _Rational_t a, const _Rational_t b);

    // //! Generalized inversion used by specialized Modular.
    // template<typename _Rational_t>
    // inline _Rational_t invext(const _Rational_t a, const _Rational_t b);
}

#include "givaro/plocal-general.inl"
