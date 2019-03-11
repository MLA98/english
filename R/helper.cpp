#include <Rcpp.h>


using namespace Rcpp;
CharacterVector ones;
CharacterVector suffixs;
CharacterVector teens;
CharacterVector tens;

// [[Rcpp::export]]
void dictionaries_import(CharacterVector ones_, CharacterVector suffixs_, CharacterVector teens_, CharacterVector tens_){
    ones = ones_;
    suffixs = suffixs_;
    teens = teens_;
    tens = tens_;
}

// [[Rcpp::export]]
void functions_import(Function split_digits_,Function paste){
    //split_digits = split_digits_;
    CharacterVector pasted = paste(ones,teens);
    Rcout<<pasted;
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

