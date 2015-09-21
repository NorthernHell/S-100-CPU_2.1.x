#ifndef __COMPLEX__
#define __COMPLEX__

#include <cmath>

class istream;
class ostream;


template <class _FLT>
class complex
{
public:
  complex (_FLT r = 0, _FLT i = 0): re (r), im (i) { }
  complex& operator += (const complex&);
  complex& operator -= (const complex&);
  complex& operator *= (const complex&);
  complex& operator /= (const complex&);
  _FLT real () const { return re; }
  _FLT imag () const { return im; }
private:
  _FLT re, im;

  friend complex& __doapl<> (complex *, const complex&);
  friend complex& __doami<> (complex *, const complex&);
  friend complex& __doaml<> (complex *, const complex&);
  friend complex& __doadv<> (complex *, const complex&);
};

template <class _FLT>
inline complex<_FLT>&
__doapl (complex<_FLT>* ths, const complex<_FLT>& r)
{
  ths->re += r.re;
  ths->im += r.im;
  return *ths;
}
template <class _FLT>
inline complex<_FLT>&
complex<_FLT>::operator += (const complex<_FLT>& r)
{
  return __doapl (this, r);
}

template <class _FLT>
inline complex<_FLT>&
__doami (complex<_FLT>* ths, const complex<_FLT>& r)
{
  ths->re -= r.re;
  ths->im -= r.im;
  return *ths;
}
template <class _FLT>
inline complex<_FLT>&
complex<_FLT>::operator -= (const complex<_FLT>& r)
{
  return __doami (this, r);
}

template <class _FLT>
inline complex<_FLT>&
__doaml (complex<_FLT>* ths, const complex<_FLT>& r)
{
  _FLT f = ths->re * r.re - ths->im * r.im;
  ths->im = ths->re * r.im + ths->im * r.re;
  ths->re = f;
  return *ths;
}
template <class _FLT>
inline complex<_FLT>&
complex<_FLT>::operator *= (const complex<_FLT>& r)
{
  return __doaml (this, r);
}

template <class _FLT>
inline complex<_FLT>&
complex<_FLT>::operator /= (const complex<_FLT>& r)
{
  return __doadv (this, r);
}

template <class _FLT> inline _FLT
imag (const complex<_FLT>& x) __attribute__ ((const));

template <class _FLT> inline _FLT
imag (const complex<_FLT>& x)
{
  return x.imag ();
}

template <class _FLT> inline _FLT
real (const complex<_FLT>& x) __attribute__ ((const));

template <class _FLT> inline _FLT
real (const complex<_FLT>& x)
{
  return x.real ();
}

template <class _FLT> inline complex<_FLT>
operator + (const complex<_FLT>& x, const complex<_FLT>& y) __attribute__ ((const));

template <class _FLT> inline complex<_FLT>
operator + (const complex<_FLT>& x, const complex<_FLT>& y)
{
  return complex<_FLT> (real (x) + real (y), imag (x) + imag (y));
}

template <class _FLT> inline complex<_FLT>
operator + (const complex<_FLT>& x, _FLT y) __attribute__ ((const));

template <class _FLT> inline complex<_FLT>
operator + (const complex<_FLT>& x, _FLT y)
{
  return complex<_FLT> (real (x) + y, imag (x));
}

template <class _FLT> inline complex<_FLT>
operator + (_FLT x, const complex<_FLT>& y) __attribute__ ((const));

template <class _FLT> inline complex<_FLT>
operator + (_FLT x, const complex<_FLT>& y)
{
  return complex<_FLT> (x + real (y), imag (y));
}

template <class _FLT> inline complex<_FLT>
operator - (const complex<_FLT>& x, const complex<_FLT>& y) __attribute__ ((const));

template <class _FLT> inline complex<_FLT>
operator - (const complex<_FLT>& x, const complex<_FLT>& y)
{
  return complex<_FLT> (real (x) - real (y), imag (x) - imag (y));
}

template <class _FLT> inline complex<_FLT>
operator - (const complex<_FLT>& x, _FLT y) __attribute__ ((const));

template <class _FLT> inline complex<_FLT>
operator - (const complex<_FLT>& x, _FLT y)
{
  return complex<_FLT> (real (x) - y, imag (x));
}

template <class _FLT> inline complex<_FLT>
operator - (_FLT x, const complex<_FLT>& y) __attribute__ ((const));

template <class _FLT> inline complex<_FLT>
operator - (_FLT x, const complex<_FLT>& y)
{
  return complex<_FLT> (x - real (y), - imag (y));
}

template <class _FLT> inline complex<_FLT>
operator * (const complex<_FLT>& x, const complex<_FLT>& y) __attribute__ ((const));

template <class _FLT> inline complex<_FLT>
operator * (const complex<_FLT>& x, const complex<_FLT>& y)
{
  return complex<_FLT> (real (x) * real (y) - imag (x) * imag (y),
			   real (x) * imag (y) + imag (x) * real (y));
}

template <class _FLT> inline complex<_FLT>
operator * (const complex<_FLT>& x, _FLT y) __attribute__ ((const));

template <class _FLT> inline complex<_FLT>
operator * (const complex<_FLT>& x, _FLT y)
{
  return complex<_FLT> (real (x) * y, imag (x) * y);
}

template <class _FLT> inline complex<_FLT>
operator * (_FLT x, const complex<_FLT>& y) __attribute__ ((const));

template <class _FLT> inline complex<_FLT>
operator * (_FLT x, const complex<_FLT>& y)
{
  return complex<_FLT> (x * real (y), x * imag (y));
}

template <class _FLT> complex<_FLT>
operator / (const complex<_FLT>& x, _FLT y) __attribute__ ((const));

template <class _FLT> complex<_FLT>
operator / (const complex<_FLT>& x, _FLT y)
{
  return complex<_FLT> (real (x) / y, imag (x) / y);
}

template <class _FLT> inline complex<_FLT>
operator + (const complex<_FLT>& x) __attribute__ ((const));

template <class _FLT> inline complex<_FLT>
operator + (const complex<_FLT>& x)
{
  return x;
}

template <class _FLT> inline complex<_FLT>
operator - (const complex<_FLT>& x) __attribute__ ((const));

template <class _FLT> inline complex<_FLT>
operator - (const complex<_FLT>& x)
{
  return complex<_FLT> (-real (x), -imag (x));
}

template <class _FLT> inline bool
operator == (const complex<_FLT>& x, const complex<_FLT>& y) __attribute__ ((const));

template <class _FLT> inline bool
operator == (const complex<_FLT>& x, const complex<_FLT>& y)
{
  return real (x) == real (y) && imag (x) == imag (y);
}

template <class _FLT> inline bool
operator == (const complex<_FLT>& x, _FLT y) __attribute__ ((const));

template <class _FLT> inline bool
operator == (const complex<_FLT>& x, _FLT y)
{
  return real (x) == y && imag (x) == 0;
}

template <class _FLT> inline bool
operator == (_FLT x, const complex<_FLT>& y) __attribute__ ((const));

template <class _FLT> inline bool
operator == (_FLT x, const complex<_FLT>& y)
{
  return x == real (y) && imag (y) == 0;
}

template <class _FLT> inline bool
operator != (const complex<_FLT>& x, const complex<_FLT>& y) __attribute__ ((const));

template <class _FLT> inline bool
operator != (const complex<_FLT>& x, const complex<_FLT>& y)
{
  return real (x) != real (y) || imag (x) != imag (y);
}

template <class _FLT> inline bool
operator != (const complex<_FLT>& x, _FLT y) __attribute__ ((const));

template <class _FLT> inline bool
operator != (const complex<_FLT>& x, _FLT y)
{
  return real (x) != y || imag (x) != 0;
}

template <class _FLT> inline bool
operator != (_FLT x, const complex<_FLT>& y) __attribute__ ((const));

template <class _FLT> inline bool
operator != (_FLT x, const complex<_FLT>& y)
{
  return x != real (y) || imag (y) != 0;
}

// Some targets don't provide a prototype for hypot when -ansi.
extern "C" double hypot (double, double) __attribute__ ((const));

template <class _FLT> inline _FLT
abs (const complex<_FLT>& x) __attribute__ ((const));

template <class _FLT> inline _FLT
abs (const complex<_FLT>& x)
{
  return hypot (real (x), imag (x));
}

template <class _FLT> inline _FLT
arg (const complex<_FLT>& x) __attribute__ ((const));

template <class _FLT> inline _FLT
arg (const complex<_FLT>& x)
{
  return atan2 (imag (x), real (x));
}

template <class _FLT> inline complex<_FLT>
polar (_FLT r, _FLT t) __attribute__ ((const));

template <class _FLT> inline complex<_FLT>
polar (_FLT r, _FLT t)
{
  return complex<_FLT> (r * cos (t), r * sin (t));
}

template <class _FLT> inline complex<_FLT>
conj (const complex<_FLT>& x)  __attribute__ ((const));

template <class _FLT> inline complex<_FLT>
conj (const complex<_FLT>& x) 
{
  return complex<_FLT> (real (x), -imag (x));
}

template <class _FLT> inline _FLT
norm (const complex<_FLT>& x) __attribute__ ((const));

template <class _FLT> inline _FLT
norm (const complex<_FLT>& x)
{
  return real (x) * real (x) + imag (x) * imag (x);
}

// Declarations of templates in complext.ccI

template <class _FLT> complex<_FLT>
  operator / (const complex<_FLT>&, const complex<_FLT>&) __attribute__ ((const));
template <class _FLT> complex<_FLT>
  operator / (_FLT, const complex<_FLT>&) __attribute__ ((const));
template <class _FLT> complex<_FLT>
  cos (const complex<_FLT>&) __attribute__ ((const));
template <class _FLT> complex<_FLT>
  cosh (const complex<_FLT>&) __attribute__ ((const));
template <class _FLT> complex<_FLT>
  exp (const complex<_FLT>&) __attribute__ ((const));
template <class _FLT> complex<_FLT>
  log (const complex<_FLT>&) __attribute__ ((const));
template <class _FLT> complex<_FLT>
  pow (const complex<_FLT>&, const complex<_FLT>&) __attribute__ ((const));
template <class _FLT> complex<_FLT>
  pow (const complex<_FLT>&, _FLT) __attribute__ ((const));
template <class _FLT> complex<_FLT>
  pow (const complex<_FLT>&, int) __attribute__ ((const));
template <class _FLT> complex<_FLT>
  pow (_FLT, const complex<_FLT>&) __attribute__ ((const));
template <class _FLT> complex<_FLT>
  sin (const complex<_FLT>&) __attribute__ ((const));
template <class _FLT> complex<_FLT>
  sinh (const complex<_FLT>&) __attribute__ ((const));
template <class _FLT> complex<_FLT>
  sqrt (const complex<_FLT>&) __attribute__ ((const));

template <class _FLT> istream& operator >> (istream&, complex<_FLT>&);
template <class _FLT> ostream& operator << (ostream&, const complex<_FLT>&);

template <class FLOAT> complex<FLOAT>
cos (const complex<FLOAT>& x)
{
  return complex<FLOAT> (cos (real (x)) * cosh (imag (x)),
			   - sin (real (x)) * sinh (imag (x)));
}

template <class FLOAT> complex<FLOAT>
cosh (const complex<FLOAT>& x)
{
  return complex<FLOAT> (cosh (real (x)) * cos (imag (x)),
			   sinh (real (x)) * sin (imag (x)));
}

template <class FLOAT> complex<FLOAT>
exp (const complex<FLOAT>& x)
{
  return polar (FLOAT (exp (real (x))), imag (x));
}

template <class FLOAT> complex<FLOAT>
log (const complex<FLOAT>& x)
{
  return complex<FLOAT> (log (abs (x)), arg (x));
}

template <class FLOAT> complex<FLOAT>
pow (const complex<FLOAT>& x, const complex<FLOAT>& y)
{
  FLOAT logr = log (abs (x));
  FLOAT t = arg (x);

  return polar (FLOAT (exp (logr * real (y) - imag (y) * t)),
		FLOAT (imag (y) * logr + real (y) * t));
}

template <class FLOAT> complex<FLOAT>
pow (const complex<FLOAT>& x, FLOAT y)
{
  return exp (FLOAT (y) * log (x));
}

template <class FLOAT> complex<FLOAT>
pow (FLOAT x, const complex<FLOAT>& y)
{
  return exp (y * FLOAT (log (x)));
}

template <class FLOAT> complex<FLOAT>
sin (const complex<FLOAT>& x)
{
  return complex<FLOAT> (sin (real (x)) * cosh (imag (x)),
			   cos (real (x)) * sinh (imag (x)));
}

template <class FLOAT> complex<FLOAT>
sinh (const complex<FLOAT>& x)
{
  return complex<FLOAT> (sinh (real (x)) * cos (imag (x)),
			   cosh (real (x)) * sin (imag (x)));
}

#include <iostream.h>

template <class FLOAT> istream&
operator >> (istream& is, complex<FLOAT>& x)
{
  FLOAT re, im = 0;
  char ch = 0;

  if (is.ipfx0 ())
    {
      if (is.peek () == '(')
	is >> ch;
      is >> re;
      if (ch == '(')
	{
	  is >> ch;
	  if (ch == ',')
	    is >> im >> ch;
	}
    }
  is.isfx ();

  if (ch != 0 && ch != ')')
    is.setstate (ios::failbit);
  else if (is.good ())
    x = complex<FLOAT> (re, im);

  return is;
}

template <class FLOAT> ostream&
operator << (ostream& os, const complex<FLOAT>& x)
{
  return os << '(' << real (x) << ',' << imag (x) << ')';
}

// The code below is adapted from f2c's libF77, and is subject to this
// copyright:

/****************************************************************
Copyright 1990, 1991, 1992, 1993 by AT&T Bell Laboratories and Bellcore.

Permission to use, copy, modify, and distribute this software
and its documentation for any purpose and without fee is hereby
granted, provided that the above copyright notice appear in all
copies and that both that the copyright notice and this
permission notice and warranty disclaimer appear in supporting
documentation, and that the names of AT&T Bell Laboratories or
Bellcore or any of their entities not be used in advertising or
publicity pertaining to distribution of the software without
specific, written prior permission.

AT&T and Bellcore disclaim all warranties with regard to this
software, including all implied warranties of merchantability
and fitness.  In no event shall AT&T or Bellcore be liable for
any special, indirect or consequential damages or any damages
whatsoever resulting from loss of use, data or profits, whether
in an action of contract, negligence or other tortious action,
arising out of or in connection with the use or performance of
this software.
****************************************************************/

template <class FLOAT> complex<FLOAT>&
__doadv (complex<FLOAT>* ths, const complex<FLOAT>& y)
{
  FLOAT ar = abs (y.re);
  FLOAT ai = abs (y.im);
  FLOAT nr, ni;
  FLOAT t, d;
  if (ar <= ai)
    {
      t = y.re / y.im;
      d = y.im * (1 + t*t);
      nr = (ths->re * t + ths->im) / d;
      ni = (ths->im * t - ths->re) / d;
    }
  else
    {
      t = y.im / y.re;
      d = y.re * (1 + t*t);
      nr = (ths->re + ths->im * t) / d;
      ni = (ths->im - ths->re * t) / d;
    }
  ths->re = nr;
  ths->im = ni;
  return *ths;
}

template <class FLOAT> complex<FLOAT>
operator / (const complex<FLOAT>& x, const complex<FLOAT>& y)
{
  FLOAT ar = abs (real (y));
  FLOAT ai = abs (imag (y));
  FLOAT nr, ni;
  FLOAT t, d;
  if (ar <= ai)
    {
      t = real (y) / imag (y);
      d = imag (y) * (1 + t*t);
      nr = (real (x) * t + imag (x)) / d;
      ni = (imag (x) * t - real (x)) / d;
    }
  else
    {
      t = imag (y) / real (y);
      d = real (y) * (1 + t*t);
      nr = (real (x) + imag (x) * t) / d;
      ni = (imag (x) - real (x) * t) / d;
    }
  return complex<FLOAT> (nr, ni);
}

template <class FLOAT> complex<FLOAT>
operator / (FLOAT x, const complex<FLOAT>& y)
{
  FLOAT ar = abs (real (y));
  FLOAT ai = abs (imag (y));
  FLOAT nr, ni;
  FLOAT t, d;
  if (ar <= ai)
    {
      t = real (y) / imag (y);
      d = imag (y) * (1 + t*t);
      nr = x * t / d;
      ni = -x / d;
    }
  else
    {
      t = imag (y) / real (y);
      d = real (y) * (1 + t*t);
      nr = x / d;
      ni = -x * t / d;
    }
  return complex<FLOAT> (nr, ni);
}

template <class FLOAT> complex<FLOAT>
pow (const complex<FLOAT>& xin, int y)
{
  if (y == 0)
    return complex<FLOAT> (1.0);
  complex<FLOAT> r (1.0);
  complex<FLOAT> x (xin);
  if (y < 0)
    {
      y = -y;
      x = 1/x;
    }
  for (;;)
    {
      if (y & 1)
	r *= x;
      if (y >>= 1)
	x *= x;
      else
	return r;
    }
}

template <class FLOAT> complex<FLOAT>
sqrt (const complex<FLOAT>& x)
{
  FLOAT r = abs (x);
  FLOAT nr, ni;
  if (r == 0.0)
    nr = ni = r;
  else if (real (x) > 0)
    {
      nr = sqrt (0.5 * (r + real (x)));
      ni = imag (x) / nr / 2;
    }
  else
    {
      ni = sqrt (0.5 * (r - real (x)));
      if (imag (x) < 0)
	ni = - ni;
      nr = imag (x) / ni / 2;
    }
  return complex<FLOAT> (nr, ni); 
}

#endif
