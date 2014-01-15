(define (min-of-four a b c d)
  (define (min_mine a b) (if (< a b) a b))
  (min_mine (min_mine a b) (min_mine c d)))
