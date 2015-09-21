#ifndef FFTIEE_H
#define FFTIEE_H

#ifndef ACE_QNX4
	#include <complex>
	using namespace std;
#else
	#include "qnxcomplex.h"
#endif


#define FFTNPOINT 256
#define FFTNGARM   FFTNPOINT / 2

void ini_fft(unsigned n=FFTNGARM);
// direct=-1 => forward direct=1 =>inverse transform
// divide items by 1/N for forward is absent! 
void fft_bidir_complex_radix2( int size, complex<double> *data, int direct);
void fft_bidir_complex_radix2( int size, complex<float> *data, int direct);
void fft_power(double rz[],int n=FFTNPOINT);
void fft_power(float rz[],int n=FFTNPOINT);
#endif
