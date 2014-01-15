(let ((input->string
       (lambda (x)
         (cond
          ((symbol? x) (symbol->string x))
          ((number? x) (number->string x))
          ((string? x) x)
          (else #f)))))
  (define (read-list l)
    (let ((data (input->string (read))))
      (if data (read-list (cons data l)) l)))
  (define (display-list l)
    (cond ((null? l) #t)
          (else
           (display (car l))
           (newline)
           (display-list (cdr l)))))
  (define (my-sort l)
    (define (reverse-list l)
      (define (reverse-list-helper l acc)
	(if (null? l)
	    acc
	    (reverse-list-helper (cdr l) (cons (car l) acc))))
      (reverse-list-helper l '()))
    (define (join-list l1 l2)
      (define (join-list-helper l1 l2)
	(if (null? l1)
	    l2
	    (join-list-helper (cdr l1) (cons (car l1) l2))))
      (join-list-helper (reverse-list l1) l2))
    (define (join-3list l1 l2 l3)
      (join-list l1 (join-list l2 l3)))
    (define (pred-string lst pivot pred)
      (define (helper lst acc)
	(if (null? lst)
	    acc
	    (let ((head (car lst))
		  (tail (cdr lst)))
	      (if (pred pivot head)
		  (helper tail (cons head acc))
		  (helper tail acc)))))
      (helper lst '()))
    (define (less-or-equal-string lst pivot)
      (define (less-or-equal-pred p head)
	(or (string=? p head) (string<? p head)))
      (pred-string lst pivot less-or-equal-pred))
    (define (larger-string lst pivot)
      (define (larger-pred p head)
	(string>? p head))
      (pred-string lst pivot larger-pred))
    (if (null? l)
	l
	(let* ((head (car l))
	       (tail (cdr l))
	       (left (less-or-equal-string tail head))
	       (right (larger-string tail head)))
	  (join-3list (my-sort right) (list head) (my-sort left)))))
  (display-list (my-sort (read-list (list)))))
