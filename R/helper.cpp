#include <Rcpp.h>
#include <RInside.h>                    // for the embedded R via RInside


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



//[[Rcpp::export]]
NumericVector helper(NumericVector x){
    // NumericVector digits = split_digit(x);
    /*** R
       
    */
    return tens;
    // return ones;
    // if (nDigits == 1){
        
    // }
}


/*** R
  and <- function (dvec) {
    if(UK && (d <- makeNumber(dvec)) > 0 && d < 100) "and" else ""
  }

ones <- c(`0` = "", `1` = "one", `2` = "two", `3` = "three", `4` = "four",
          `5` = "five", `6` = "six", `7` = "seven", `8` = "eight", `9` = "nine")

suffixes <- c("thousand", "million", "billion", "trillion", "quadrillion",
              "quintillion", "sextillion", "septillion")

teens <- c(`0` = "ten", `1` = "eleven", `2` = "twelve", `3` = "thirteen",
           `4` = "fourteen", `5` = "fifteen", `6` = "sixteen", `7` = "seventeen",
           `8` = "eighteen", `9` = "nineteen")

tens <- c(`2` = "twenty", `3` = "thirty", `4` = "forty", `5` = "fifty",
          `6` = "sixty", `7` = "seventy", `8` = "eighty", `9` = "ninety")




trim <- function (text)
  sub("^ *", "", sub(" *$", "", gsub("  +", " ", text)))

split_digits <- function(x) {
  d <- character()
  while(x > 0) {
    d <- c(d, x %% 10)
    x <- x %/% 10
  }
  if(length(d) == 0)
    d <- "0"
  d
}

makeNumber <- function (n)
  as.numeric(paste(n, collapse = ""))


*/
