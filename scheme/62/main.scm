(define (my-reverse l)
  (define (my-reverse-helper l acc)
    (if (equal? l '())
	acc
	(let ((head (car l))
	      (tail (cdr l)))
	  (my-reverse-helper tail (cons head acc)))))
  (my-reverse-helper l '()))

(define (my-append a b)
  (define (my-append-helper a b)
    (if (equal? a '())
	b
	(my-append-helper (cdr a) (cons (car a) b))))
  (my-append-helper (my-reverse a) b))
	
