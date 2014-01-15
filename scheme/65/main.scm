(define (if-fun exp1 exp2 exp3)
  (if exp1 exp2 exp3))

(define (fact3 n)
(lazy  (if-fun (< n 1)
          1
          (* n ((force (fact3 (- n 1)))))))
)
