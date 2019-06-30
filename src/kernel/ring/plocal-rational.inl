// ==========================================================================
// $Source: /var/lib/cvs/Givaro/src/kernel/zpz/givzpzInt.inl,v $
// Copyright(c)'1994-2009 by The Givaro group
// This file is part of Givaro.
// Givaro is governed by the CeCILL-B license under French law
// and abiding by the rules of distribution of free software.
// see the COPYRIGHT file for more details.
// Authors: JG Dumas
// $Id: givzpzInt.inl,v 1.11 2011-02-02 17:16:43 briceboyer Exp $
// ==========================================================================
#ifndef __GIVARO_plocal_rational_INL
#define __GIVARO_plocal_rational_INL
// Description:

namespace Givaro {

  // ------------------------- Arithmetic functions

  inline typename PLocal<Rational, Integer>::Element&
  PLocal<Rational, Integer>::mul (Element& r, const Element& a, const Element& b) const
  {
    return r = a*b;
  }
  
  inline typename PLocal<Rational, Integer>::Element&
  PLocal<Rational, Integer>::sub (Element& r, const Element& a, const Element& b) const
  {
    return r = a - b;
  }
  
  inline typename PLocal<Rational, Integer>::Element&
  PLocal<Rational, Integer>::add (Element& r, const Element& a, const Element& b) const
  {
    return r = a + b;
  }

  inline typename PLocal<Rational, Integer>::Element&
  PLocal<Rational, Integer>::neg (Element& r, const Element& a) const
  {
    return r = -a;
  }

  inline typename PLocal<Rational, Integer>::Element&
  PLocal<Rational, Integer>::negin (Element& r) const
  {
    return r = -r;
  }

  inline typename PLocal<Rational, Integer>::Element&
  PLocal<Rational, Integer>::inv (Element& r, const Element& a) const
  {
    if ( this->isUnit(a))
      {
	r = one / a;
      }
    else r = one;
    return r;
  }

  inline typename PLocal<Rational, Integer>::Element&
  PLocal<Rational, Integer>::div (Element& r, const Element& a, const Element& b) const
  {
    if ( this->isUnit(b))
      {
	r = a / b;
      }
    else r = zero;
    return r;
  }

  inline typename PLocal<Rational, Integer>::Element&
  PLocal<Rational, Integer>::mulin (Element& r, const Element& a) const
  {
    return r *= a;
  }

  inline typename PLocal<Rational, Integer>::Element&
  PLocal<Rational, Integer>::divin (Element& r, const Element& a) const
  {
    if (this->isUnit(a))
      {
	r /= a;
      }
    else r = zero;
    return r;
  }

  inline typename PLocal<Rational, Integer>::Element&
  PLocal<Rational, Integer>::addin (Element& r, const Element& a) const
  {
    return r += a;
  }

  inline typename PLocal<Rational, Integer>::Element&
  PLocal<Rational, Integer>::subin (Element& r, const Element& a) const
  {
    return r -= a;
  }

  inline typename PLocal<Rational, Integer>::Element&
  PLocal<Rational, Integer>::invin (Element& r) const
  {
    if (this->isUnit(r))
      {
	r = one / r;
      }
    else r = zero;
    return r;
  }

  typename PLocal<Rational, Integer>::Element&
  PLocal<Rational, Integer>::pow (Element& r, const int64_t& l) const
  {
    r = Givaro::pow(r, l);
    return r;
  }
  
  inline typename PLocal<Rational, Integer>::Element&
  PLocal<Rational, Integer>::axpy (Element& r, const Element& a, const Element& b, const Element& c) const
  {
    return r = a*b + c;
  }

  inline typename PLocal<Rational, Integer>::Element&
  PLocal<Rational, Integer>::axpyin (Element& r, const Element& a, const Element& b) const
  {
    return r += a*b;
  }

  inline typename PLocal<Rational, Integer>::Element&
  PLocal<Rational, Integer>::axmy (Element& r, const Element& a, const Element& b, const Element& c) const
  {
    return r = a*b -c;
  }

  // r = c - a*b
  inline typename PLocal<Rational, Integer>::Element&
  PLocal<Rational, Integer>::maxpy (Element& r, const Element& a, const Element& b, const Element& c) const
  {
    return r = c - a*b ; 
  }

  // r -= a*b
  inline typename PLocal<Rational, Integer>::Element&
  PLocal<Rational, Integer>::maxpyin (Element& r, const Element& a, const Element& b) const
  {
    return r -= a*b;
  }

  // r = a*b - r
  inline typename PLocal<Rational, Integer>::Element&
  PLocal<Rational, Integer>::axmyin (Element& r, const Element& a, const Element& b) const
  {
    return r = a*b - r;
  }

  // --------------------
  // ----- Initialisation

  inline typename PLocal<Rational, Integer>::Element&
  PLocal<Rational, Integer>::init(Element& x) const
  {
    return x = this->zero;
  }

  // ------------
  // ----- Unit and valuation
  int64_t&
  PLocal<Rational, Integer>::valuation (int64_t& n, const Element& a ) const 
  {
    if (this->isZero(a))
      {
	n = -1;
      }
    else
      {
	n = -1;
	Integer_t q {a.nume()}, r {0};
	while (r == 0)
	  {
	    Integer::divmod(q,r,q,this->prime());
	    n += 1;
	  }
      }
    return n;
  }

  int64_t
  PLocal<Rational, Integer>::valuation (const Element& a ) const 
  {
    int64_t n {};
    if (this->isZero(a))
      {
	n = -1;
      }
    else
      {
	n = -1;
	Integer_t q {a.nume()}, r {0};
	while (r == 0)
	  {
	    Integer::divmod(q,r,q,this->prime());
	    n += 1;
	  }
      }
    return n;
  }

  
  typename PLocal<Rational, Integer>::Element&
  PLocal<Rational, Integer>::uniformizer_factor(Element& q, const Element& a) const
  {
    if (this->isZero(a))
      {
	q = 0;
      }
    else
      {
	int64_t n {};
	valuation(n, a);
	q = ::Givaro::pow(this->prime(), n);
      }
    return q;
  }

  typename PLocal<Rational, Integer>::Element&
  PLocal<Rational, Integer>::unit_factor (Element& u, const Element& a) const
  {
    if (this->isZero(a))
      {
	u = 0;
      }
    else
      {
	Element q {};
	uniformizer_factor(q, a);
	u = a / q;
      }
    return u;
  }
  

} // namespace Givaro

#endif // __GIVARO_plocal_rational_INL

