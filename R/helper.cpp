#include <Rcpp.h>


using namespace Rcpp;
Environment myEnv = Environment::global_env();
Function split_digits = myEnv["split_digits"];
Function makeNumber = myEnv["makeNumber"];
Function paste = myEnv["p"];
Function trim = myEnv["trim"];
Function and_ = myEnv["and"];
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
CharacterVector helper(NumericVector x){
    CharacterVector digits = split_digits(x);
    Rcout << digits << "\n";
    int nDigits = digits.size();
    Rcout << nDigits << "\n";
    if (nDigits == 1){
        CharacterVector ans = ones[digits];
        Rcout << ans<< "\n";
        return ones[digits];
    }
    else if (nDigits ==2){
        if (x[0] <= 19){
            CharacterVector digit_1= CharacterVector::create(digits[0]);
            CharacterVector ans = teens[digit_1];
            Rcout << ans<< "\n";
            return ones[digits];
        }
        else{
            CharacterVector digit_2= CharacterVector::create(digits[1]);
            CharacterVector digit_1= CharacterVector::create(digits[0]);
            trim(paste(tens))
        }
    }
}

