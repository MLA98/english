#include <R.h>
#include <Rinternals.h>
// [[Rcpp::export]]
// int fibonacci(int n){
//     if(n<2) return n;
//     return fibonacci(n-1) + fibonacci(n-2);
// }

SEXP try(SEXP a){
    SEXP result = PROTECT (allocVector(INTSXP, 10));
    result[0] = asReal(a);
    printf("%f", REAL(result)[0]);
    // REAL(result)[0] = asReal(a) + asReal(b);
    UNPROTECT(1);
    return result;
}