dyn.load("helper.so")

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

try <- function(a) {
   a = split_digits(a)
   .Call("try", a)
}