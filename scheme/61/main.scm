(define (my-assoc key dict)
  (if (equal? dict '())
      #f
      (let ((head (car dict))
	    (tail (cdr dict)))
	(if (equal? (car head) key)
	    head
	    (my-assoc key tail)))))
