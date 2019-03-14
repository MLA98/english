#include <Rcpp.h>


using namespace Rcpp;
int loaded = 0;

CharacterVector ones = CharacterVector::create(Named("0")= "", Named("1")= "one", Named("2")= "two", Named("3") = "three", Named("4")= "four", Named("5")= "five", Named("6")= "six",Named("7")= "seven", Named("8")= "eight", Named("9")= "nine");
CharacterVector teens = CharacterVector::create(Named("0")= "ten", Named("1")= "eleven", Named("2")= "twelve", Named("3") = "thirteen", Named("4")= "fourteen", Named("5")= "fifteen", Named("6")= "sixteen",Named("7")= "seventeen", Named("8")= "eighteen", Named("9")= "nineteen");
CharacterVector tens = CharacterVector::create(Named("2")= "twenty", Named("3") = "thirty", Named("4")= "forty", Named("5")= "fifty", Named("6")= "sixty",Named("7")= "seventy", Named("8")= "eighty", Named("9")= "ninety");
CharacterVector suffixes = CharacterVector::create("thousand", "million", "billion", "trillion", "quadrillion", "quintillion", "sextillion", "septillion");



// [[Rcpp::export]]
RcppExport SEXP helper2(SEXP x_, SEXP UK){
    if (loaded == 0){    
        Environment myEnv = Environment::global_env();
        Function split_digits = myEnv["split_digits"];
        Function makeNumber = myEnv["makeNumber"];
        Function paste = myEnv["p"];
        Function trim = myEnv["trim"];
        Function and_ = myEnv["and"];
        loaded = loaded + 1;
        Rcout << ones;
    }
    NumericVector x = x_;
    LogicalVector UK_ = UK;
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
        return trim(paste(ones[digit_3], "hundred", and_(digit_2_to_1, UK), helper2(makeNumber(digit_2_to_1), UK)));
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
        // std::cout << "hi";
        IntegerVector nDigits_ = IntegerVector::create(nDigits - 1);
        IntegerVector times3_nSuf_plus_1 = IntegerVector::create((3 * nSuffix + 1 - 1));
        IntegerVector v1;
        // std::cout << "hi";
        if (nDigits > (3 * nSuffix + 1)){
            // std::cout << "hi";
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
            helper2(makeNumber(digits[v1]), UK), 
            sufix_charv, 
            and_(digits[v2], UK),
            helper2(makeNumber(digits[v2]), UK)
            );
        CharacterVector trimed = trim(pasted);
        return trimed;
    }
}

