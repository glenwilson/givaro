// ==========================================================================
// Copyright(c)'1994-2015 by The Givaro group
// This file is part of Givaro.
// Givaro is governed by the CeCILL-B license under French law
// and abiding by the rules of distribution of free software.
// see the COPYRIGHT file for more details.
// Authors: JG Dumas
//          A. Breust (taken from FFLAS-FFPACK)
// ==========================================================================

#ifndef __GIVARO_plocal_rational_H
#define __GIVARO_plocal_rational_H

#include "givaro/givbasictype.h"
#include "givaro/giverror.h"
#include "givaro/givinteger.h"
#include "givaro/givrational.h"
#include "givaro/givcaster.h"
#include "givaro/givranditer.h"
#include "givaro/ring-interface.h"
#include "givaro/plocal-implem.h"

namespace Givaro
{

    /*! @brief 
      This class implement the standard arithmetic with p-local integers.
     * - The representation of a p-local integer is a rational number a, whose denominator is not divisible by p.
     * .
     */
  template<>
  class PLocal<Rational, Integer>: public PLocal_implem<Rational, Integer>
  {
  public:
    // ----- Exported Types and constantes
    
    using Rational_t = Rational;
    using Integer_t = Integer;
    using Element = Rational_t;
    using Self_t = PLocal<Rational_t, Integer_t>;
    using Parent_t = PLocal_implem<Rational_t, Integer_t>;
    
    // Constructors
    using Parent_t::PLocal_implem;
    using Parent_t::_p;
    
    // ----- Initialisation
    //These are used to initialize elements.
    Element& init (Element& x) const override;
    
    Element& init(Element& r, const Rational& a) const override
    {
      Givaro::ZRing<Integer_t> ZZ;
      Integer_t temp ;
      // This checks if denomenator is divisible by p. If it is,
      // raises an error. 
      if (ZZ.mod(temp, a.deno(), this->prime() ) == 0 )
	{
	  r = Rational(a.nume(), ZZ.zero);
	}
      r = a;
      return r;
    }
    
    // ----- Unit and valuation
    Element& unit_factor (Element& u, const Element& a) const override;
    Element& uniformizer_factor (Element& q, const Element& a) const override;
    int64_t& valuation (int64_t& n, const Element& a) const override;
    
    // ----- Classic arithmetic
    Element& mul(Element& r, const Element& a, const Element& b) const override;
    Element& div(Element& r, const Element& a, const Element& b) const override;
    Element& add(Element& r, const Element& a, const Element& b) const override;
    Element& sub(Element& r, const Element& a, const Element& b) const override;
    Element& neg(Element& r, const Element& a) const override;
    Element& inv(Element& r, const Element& a) const override;

    Element& mulin(Element& r, const Element& a) const override;
    Element& divin(Element& r, const Element& a) const override;
    Element& addin(Element& r, const Element& a) const override;
    Element& subin(Element& r, const Element& a) const override;
    Element& negin(Element& r) const override;
    Element& invin(Element& r) const override;
    
    // -- axpy:   r <- a * x + y
    // -- axpyin: r <- a * x + r
    Element& axpy  (Element& r, const Element& a, const Element& x, const Element& y) const override;
    Element& axpyin(Element& r, const Element& a, const Element& x) const override;
    
    // -- axmy:   r <- a * x - y
    // -- axmyin: r <- a * x - r
    Element& axmy  (Element& r, const Element& a, const Element& x, const Element& y) const override;
    Element& axmyin(Element& r, const Element& a, const Element& x) const override;

    // -- maxpy:   r <- y - a * x
    // -- maxpyin: r <- r - a * x
    Element& maxpy  (Element& r, const Element& a, const Element& x, const Element& y) const override;
    Element& maxpyin(Element& r, const Element& a, const Element& x) const override;

    // ----- Random generators
    typedef ModularRandIter<Self_t> RandIter;
    typedef GeneralRingNonZeroRandIter<Self_t> NonZeroRandIter;
    template< class Random > Element& random(Random& g, Element& r) const
    { return init(r, g()); }
    template< class Random > Element& nonzerorandom(Random& g, Element& a) const
    { while (this->isZero(init(a, g())))
	;
      return a; }
    
  };


}// namespace Givaro

#include "givaro/plocal-rational.inl"

#endif // __GIVARO_plocal+rational_H
// vim:sts=4:sw=4:ts=4:noet:sr:cino=>s,f0,{0,g0,(0,\:0,t0,+0,=s
