#include <Rcpp.h>
using namespace Rcpp;
extern CharacterVector ones;
extern CharacterVector suffixs;
extern CharacterVector teens;
extern CharacterVector tens;

//[[Rcpp::export]]
void dictionaries(CharacterVector ones_, CharacterVector suffixs_, CharacterVector teens_, CharacterVector tens_){
    ones = ones_;
    suffixs = suffixs_;
    teens = teens_;
    tens = tens_;
}



// //[[Rcpp::export]]
// void hehe(NumericVector a){
//     int nDigits = a.size();
//     Rcout<<a[1]<<"\n";
    
//     // return ones;
//     // if (nDigits == 1){
        
//     // }
// }

