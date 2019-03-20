#include <Rcpp.h>


using namespace Rcpp;
//Obtain R's environment
Environment myEnv = Environment::namespace_env("englishcpp");
// Make function callable from c++
Function split_digits = myEnv["split_digits"];
Function myMakeNumber = myEnv["makeNumber"];
Function paste = myEnv["p"];
Function trim = myEnv["trim"];
Function myAnd = myEnv["and"];
// CharacterVector ones = myEnv["ones"];
// CharacterVector suffixes = myEnv["suffixes"];
// CharacterVector teens = myEnv["teens"];
// CharacterVector tens = myEnv["tens"];

// create the new dictionary in cpp
CharacterVector ones = CharacterVector::create(Named("0")= "", Named("1")= "one", Named("2")= "two", Named("3") = "three", Named("4")= "four", Named("5")= "five", Named("6")= "six",Named("7")= "seven", Named("8")= "eight", Named("9")= "nine");
CharacterVector teens = CharacterVector::create(Named("0")= "ten", Named("1")= "eleven", Named("2")= "twelve", Named("3") = "thirteen", Named("4")= "fourteen", Named("5")= "fifteen", Named("6")= "sixteen",Named("7")= "seventeen", Named("8")= "eighteen", Named("9")= "nineteen");
CharacterVector tens = CharacterVector::create(Named("2")= "twenty", Named("3") = "thirty", Named("4")= "forty", Named("5")= "fifty", Named("6")= "sixty",Named("7")= "seventy", Named("8")= "eighty", Named("9")= "ninety");
CharacterVector suffixes = CharacterVector::create("thousand", "million", "billion", "trillion", "quadrillion", "quintillion", "sextillion", "septillion");

//written in Cpp credit to 
// CharacterVector split_digits(NumericVector& digit){
//     CharacterVector digit_ = as<CharacterVector>(digit);
//     std::string digit_str = as<std::string>(digit_); 
//     char * chararr = new char[digit_str.size()];
//     std::copy(digit_str.begin(), digit_str.end(), chararr);
//     CharacterVector retV;
//     for (int i = digit_str.size() - 1; i>=0; i-- ){
//         retV.push_back(chararr[i]);
//     }
//     return retV;
// }


// Cpphelper help convert the number to english
CharacterVector helper2(NumericVector x, LogicalVector UK){
    CharacterVector digits = split_digits(x);
    int nDigits = digits.size();
    if (nDigits == 1){
        return ones[digits];
    }
    else if (nDigits == 2){
        if (x[0] <= 19){
            CharacterVector digit_1= CharacterVector::create(digits[0]);
            return teens[digit_1];
        }
        else{
            CharacterVector digit_2= CharacterVector::create(digits[1]);
            std::string digit_1_ = as<std::string>(digits[0]);
            int digit_1__ = std::stod(digit_1_);
            NumericVector digit_1 = NumericVector::create(digit_1__);
            return trim(paste(tens[digit_2], helper2(digit_1, UK)));
            }
    }
    else if (nDigits == 3){
        CharacterVector digit_3= CharacterVector::create(digits[2]);
        NumericVector two_to_one = NumericVector::create(1,0);
        CharacterVector digit_2_to_1 = digits[two_to_one];
        return trim(paste(ones[digit_3], "hundred", myAnd(digit_2_to_1, UK), helper2(myMakeNumber(digit_2_to_1), UK)));
    }
    else{
        int nSuffix = (nDigits + 2) / 3 - 1;
        if (nSuffix > suffixes.size()) {
            Rcerr << (paste(x, "is too large!"));
            //CharacterVector x_ = CharacterVector::create(x);
            std::string x_ = as<std::string>(x);
            CharacterVector x__ = CharacterVector::create(x_);
            return(x__);
        }
        IntegerVector nDigits_ = IntegerVector::create(nDigits - 1);
        IntegerVector times3_nSuf_plus_1 = IntegerVector::create((3 * nSuffix + 1 - 1));
        IntegerVector v1;
        if (nDigits > (3 * nSuffix + 1)){
            v1 = rev(seq(max(times3_nSuf_plus_1), min(nDigits_)));
        }
        else{
            v1 = seq(max(nDigits_), min(times3_nSuf_plus_1));
        }
        IntegerVector times3_nSuf = IntegerVector::create((3 * nSuffix) - 1);
        IntegerVector zero = IntegerVector::create(0);
        IntegerVector v2 = rev(seq(max(zero), min(times3_nSuf)));
        std::string sufix_string = as<std::string>(suffixes[nSuffix - 1]);
        CharacterVector sufix_charv = CharacterVector::create(sufix_string);
        CharacterVector pasted = paste(
            helper2(myMakeNumber(digits[v1]), UK), 
            sufix_charv, 
            myAnd(digits[v2], UK),
            helper2(myMakeNumber(digits[v2]), UK)
            );
        CharacterVector trimed = trim(pasted);
        return trimed;
    }
}

//wrapper of helper since .Call could not use Rcpp arguments
RcppExport SEXP helper(SEXP x_, SEXP UK){
    return (helper2(x_, UK));
}