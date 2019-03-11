#include <Rcpp.h>
#include <iostream>


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
CharacterVector helper(NumericVector x, LogicalVector UK_){
    LogicalVector UK = UK_;
    CharacterVector digits = split_digits(x);
    Rcout << digits << "\n";
    int nDigits = digits.size();
    Rcout << nDigits << "\n";
    if (nDigits == 1){
        CharacterVector ans = ones[digits];
        Rcout << ans<< "\n";
        return ones[digits];
    }
    else if (nDigits == 2){
        if (x[0] <= 19){
            CharacterVector digit_1= CharacterVector::create(digits[0]);
            CharacterVector ans = teens[digit_1];
            Rcout << ans<< "\n";
            return ones[digits];
        }
        else{
            CharacterVector digit_2= CharacterVector::create(digits[1]);
            Rcout << digit_2 << "\n";
            std::string digit_1_ = as<std::string>(digits[0]);
            std::cout << digit_1_ << "\n";
            int digit_1__ = std::stod(digit_1_);
            NumericVector digit_1 = NumericVector::create(digit_1__);
            Rcout << digit_1<< "\n";
            return trim(paste(tens[digit_2], helper(digit_1, UK)));
        }
    }
    else if (nDigits == 3){
        CharacterVector digit_3= CharacterVector::create(digits[2]);
        std::cout<< "adf";
        NumericVector two_to_one = NumericVector::create(1,0);
        CharacterVector digit_2_to_1 = digits[two_to_one];
        std::cout<< "adf";
        CharacterVector ans = trim(paste(ones[digit_3], "hundred", and_(digit_2_to_1, UK), helper(makeNumber(digit_2_to_1), UK)));
        Rcout << ans<< "\n";
        return ans;
    }
    else{
        int nSuffix = (nDigits + 2) / 3 - 1;
        if (nSuffix > suffixes.size()) {
            Rcerr << (paste(x, "is too large!"));
            //CharacterVector x_ = CharacterVector::create(x);
            std::string x_ = as<std::string>(x);
            CharacterVector x__ = CharacterVector::create(x_);
            return(x_);
        }
        std::cout << "hi";
        IntegerVector nDigits_ = IntegerVector::create(nDigits);
        IntegerVector times3_nSuf_plus_1 = IntegerVector::create((3 * nSuffix + 1 - 1));
        IntegerVector v1;
        std::cout << "hi";
        if (nDigits > (3 * nSuffix + 1)){
            v1 = rev(seq(max(times3_nSuf_plus_1), min(nDigits_)));
        }
        else{
            v1 = seq(max(nDigits_), min(times3_nSuf_plus_1));
        }
        std::cout << "hi";
        // IntegerVector nDigits_ = IntegerVector::create(nDigits);
        // IntegerVector times3_nSuf_plus_1 = IntegerVector::create((3 * nSuffix + 1));
        // IntegerVector v1 = seq(max(nDigits_), min(times3_nSuf_plus_1));
        IntegerVector times3_nSuf = IntegerVector::create((3 * nSuffix) - 1);
        std::cout << "hi";
        IntegerVector zero = IntegerVector::create(0);
        IntegerVector v2 = rev(seq(max(zero), min(times3_nSuf)));
        std::cout << "hi";
        return trim(paste(
            helper(makeNumber(digits[v1]), UK), 
            suffixes[nSuffix], 
            and_(digits[v2], UK),
            helper(makeNumber(digits[v2]), UK)
            ));
        std::cout << "hi";
    }
}

