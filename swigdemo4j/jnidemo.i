%module swigdemo4j

%{
#include "../src/jni_test.h"
%}

/* Map Java double[] to C/C++ double* */
%typemap(jni) double * "jdoubleArray"
%typemap(jtype) double * "double[]"
%typemap(jstype) double * "double[]"
%typemap(javain) double * "$javainput"
%typemap(in) double * {
  $1 = (double *) JCALL2(GetDoubleArrayElements, jenv, $input, 0);
}
%typemap(freearg) double * {
  if ($1) {
    JCALL3(ReleaseDoubleArrayElements, jenv, $input, (double *) $1, 0);
  }
}
%typemap(argout) double * {
  JCALL3(ReleaseDoubleArrayElements, jenv, $input, (double *) $1, 0);
  $1 = NULL;
}

%include "../src/jni_test.h"
