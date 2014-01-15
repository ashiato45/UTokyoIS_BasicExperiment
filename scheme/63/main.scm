(define (my-fold op acc l)
  (if (null? l)
      acc
      (my-fold op (op (car l) acc) (cdr l))))

(define (my-length2 l)
  (my-fold (lambda (elem acc) (+ acc 1)) 0 l))

(define (my-reverse2 l)
  (my-fold (lambda (elem acc) (cons elem acc)) '() l))
