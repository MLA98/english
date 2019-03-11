#include <Rcpp.h>


using namespace Rcpp;
CharacterVector ones;
CharacterVector suffixs;
CharacterVector teens;
CharacterVector tens;
Function split_digits = NULL;

// [[Rcpp::export]]
void dictionaries_import(CharacterVector ones_, CharacterVector suffixs_, CharacterVector teens_, CharacterVector tens_){
    ones = ones_;
    suffixs = suffixs_;
    teens = teens_;
    tens = tens_;
    NumericVector a = NumericVector::create(1);
    CharacterVector b = split_digits(a);
    Rcout << b[0];
}

// [[Rcpp::export]]
void functions_import(Function split_digits_){
    split_digits = split_digits_;
    // NumericVector v = NumericVector::create(1,2,3);
    
}


//[[Rcpp::export]]
void helper(NumericVector x){
    // NumericVector digits = split_digit(x);
    /*** R
       
    */
    // return ones;
    // if (nDigits == 1){
        
    // }
}

