(define (even<odd? a b c d e)
  (define (count-even l acc)
    (cond
     ((equal? l '()) acc)
     ((even? (car l)) (count-even (cdr l) (+ acc 1)))
     (else (count-even (cdr l) acc))))
  (< (count-even (list a b c d e) 0) 3))
