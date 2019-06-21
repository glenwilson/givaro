/* -*- mode: C++; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*- */
// vim:sts=4:sw=4:ts=4:noet:sr:cino=>s,f0,{0,g0,(0,\:0,t0,+0,=s
// ==========================================================================
// Copyright(c)'1994-2017 by The Givaro group
// This file is part of Givaro.
// Givaro is governed by the CeCILL-B license under French law
// and abiding by the rules of distribution of free software.
// see the COPYRIGHT file for more details.
// Authors: B. Grenet, R. Lebreton from existing files
// ==========================================================================

/*! @file ring/modular-implem.h
 * @ingroup ring
 * @brief Generic implementation of Modular
 */

#ifndef __GIVARO_plocal_implem_H
#define __GIVARO_plocal_implem_H

#include "givaro/givinteger.h"
#include "givaro/givrational.h"
#include "givaro/givcaster.h"
#include "givaro/givranditer.h"
#include "givaro/ring-interface.h"
#include "givaro/plocal-general.h"

namespace Givaro {

	/*! @brief This class implements the standard arithmetic with the ring of p-local integers.
	 * - The representation of an element a in Z_(p) is a rational number where p does not divide the denominator
	 */
	template<typename _Rational_t, typename _Integer_t>
	class PLocal_implem: public DVRInterface<_Rational_t>
	{
	public:
		using Element = _Rational_t;
		using Self_t = PLocal_implem<_Rational_t, _Integer_t>;
		using Rational_t = _Rational_t;
		using Integer_t = _Integer_t;

		// ----- Exported Types and constantes
		enum { size_rep = sizeof(Rational_t) } ;
		
		// ----- Constants
		const Element zero;
		const Element one;
		const Element mOne;

		// ----- Constructors
		PLocal_implem()
			: zero(static_cast<Element>(0))
			, one(static_cast<Element>(1))
			, mOne(static_cast<Element>(-1))
			, _p(static_cast<Integer_t>(0))
			{}

		PLocal_implem(const Integer_t p)
			: zero(static_cast<Element>(0))
			, one(static_cast<Element>(1))
			, mOne(static_cast<Element>(-static_cast<Element>(1)))
			, _p(static_cast<Integer_t>(p))
		{}


		PLocal_implem(const Self_t& F)
			: zero(F.zero), one(F.one), mOne(F.mOne), _p(F._p) {}

		// ----- Accessors
		// ----- Access to the prime
		inline Integer_t prime() const { return _p; }


		// ----- Checkers
		inline bool isZero(const Element& a) const override { return a == zero; }
		inline bool isOne (const Element& a) const override { return a == one; }
		inline bool isMOne(const Element& a) const override { return a == mOne; }
		inline bool areEqual(const Element& a, const Element& b) const override { return a == b; }
		inline bool isUnit(const Element& a) const override
		{
			Givaro::ZRing<Integer_t> ZZ;
			Integer_t r {};
			return (ZZ.mod(r, a.nume(), prime()) != 0);
		}
		inline size_t length(const Element a) const { return size_rep; }

		// ----- Ring-wise operators
		inline bool operator==(const Self_t& F) const { return _p == F._p; }
		inline bool operator!=(const Self_t& F) const { return _p != F._p; }
		inline Self_t& operator=(const Self_t& F)
		{
			F.assign(const_cast<Element&>(one),  F.one);
			F.assign(const_cast<Element&>(zero), F.zero);
			F.assign(const_cast<Element&>(mOne), F.mOne);
			_p = F._p;
			return *this;
		}

		Element& assign (Element& x, const Element& y) const override
		{
			return x = y;
		}

		// ----- Convert
		template<typename T> T& convert(T& r, const Element& a) const
		{ return Caster<T,Element>(r,a); }

    	// --------
    	// -- type_string

    	// --------
    	// ----- IO


		using RingInterface<Rational_t>::init;
		virtual Element& init (Element&, const Rational&) const = 0;

		std::ostream& write (std::ostream& s) const override
		{
			return s << "p-local integers at prime " << prime() ;;
		}
		
		inline std::ostream& write (std::ostream& s, const Element& a) const override
    	{
			return s << Caster<Element>(a);
    	}

		

	    // -- Input: (Z, <_p>)
	    inline std::istream& read (std::istream& s)
	    {
	    char ch;
	    s >> std::ws >> ch;
	    if (ch != '(')
	        std::cerr << "GivBadFormat(PLocal_implem::read: syntax error: no '('))" << std::endl;

	    s >> std::ws >> ch;
	    if (ch != 'Z')
	        std::cerr << "GivBadFormat(PLocal_implem::read: bad domain object))" << std::endl;

	    s >> std::ws >> ch;
	    if (ch != ',')
	        std::cerr << "GivBadFormat(PLocal_implem::read: syntax error: no ',')) " << std::endl;

	    s >> std::ws >> _p;

	    s >> std::ws >> ch;
	    if (ch != ')')
	        std::cerr << "GivBadFormat(PLocal_implem::read: syntax error: no ')')) " << std::endl;

	    return s;
		}

		inline std::istream& read (std::istream&, Element&) const override;

	protected:
		// -- data representation of the domain:
		Integer_t _p;
	};


	template<typename _Rational_t, typename _Integer_t>
	inline std::istream& PLocal_implem<_Rational_t, _Integer_t>::read (std::istream& s, Element& a) const
		{
		    Integer tmp;
		    s >> tmp;
		    this->init(a, tmp);
		    return s;
		}


}


#endif // __GIVARO_plocal_implem_H
