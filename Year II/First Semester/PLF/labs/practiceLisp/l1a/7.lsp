;Write a function to eliminate the n-th element of a linear list.

;elmNth(l1,...,ln,p,cp) = {
;   nil, n = 0
;   elmNth(l2,...,ln,p,cp+1), cp = p
;   l1 U elmNth(l2,...,ln,p,cp+1), otherwise
;}

(defun elmNth (l p cp)
    (cond
        ((null l) nil)
        ((= cp p) (elmNth (cdr l) p (+ cp 1)))
        (T(cons (car l) (elmNth(cdr l) p (+ cp 1))))
    )
)

(print (elmNth '(1 2 3 4 5 6) 5 1))