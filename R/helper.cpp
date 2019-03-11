#include <Rcpp.h>


using namespace Rcpp;
Environment myEnv = Environment::global_env();
Function split_digits = myEnv["split_digits"];
Function makeNumber = myEnv["makeNumber"];
Function paste = myEnv["p"];
Function trim = myEnv["trim"];
CharacterVector ones = myEnv["ones"];
CharacterVector suffixes = myEnv["suffixes"];
CharacterVector teens = myEnv["teens"];
CharacterVector tens = myEnv["tens"];


// // [[Rcpp::export]]
// void functions_import(Function split_digits_,Function paste_){
//     Function split_digits = split_digits_;
//     Function paste = paste_;
//     CharacterVector pasted = paste(ones,teens);
//     Rcout<<pasted;
//     // NumericVector v = NumericVector::create(1,2,3);
    
// }


//[[Rcpp::export]]
void helper(NumericVector x){
    CharacterVector splited = split_digits(100);
    CharacterVector pasted = paste(ones,teens);
    Rcout<<pasted;
    Rcout << splited;
    Rcout<<x;
    std::cout<<"hi";
}

