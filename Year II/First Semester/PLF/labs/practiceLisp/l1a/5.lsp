;a) Write a function to return the product of two vectors.

;dotProduct(l1,...,ln,k1,...,kn) = {
;   0, n = 0
;   l1 * k1 + dotProduct(l2,..,lm,k2,...,kn), otherwise
;
;}


(defun dotProduct (l k)
    (cond
        ((or (null l)(null k)) 0)
        (T(+ (* (car l) (car k)) (dotProduct (cdr l) (cdr k))))
    )
)

;(print (dotProduct '(1 3 -5) '(4 -2 -1)))

;Write a function to sort a linear list without keeping the double values.

;insertSorted(l1,...,ln,e) = {
;   list(e) ,n = 0
;   l1,....,ln ,l1 = e 
;   e U l1,...,ln , e < l1
;   l1 U insertSorted(l2,...,ln, e), otherwise
;}

(defun insertSorted (l e)
    (cond
        ((null l) (list e))
        ((= (car l) e) l)
        ((< e (car l)) (cons e l))
        (T(cons (car l) (insertSorted (cdr l) e)))
    )
)


;Write a function to return the intersection of two sets.

;contains(l1,...,ln,e) = {
;   nil, n = 0
;   true, l1 = e
;   contains(l2,...,ln,e), otherwise
;}

(defun contains(l e)
    (cond
        ((null l) nil)
        ((= (car l) e) T)
        (T (contains (cdr l) e))
    )
)


;intersesction(l1,...,ln,k1,...,km) = {
;   nil, n = 0 or m = 0
;   l1 U intersection(l2,...,ln,k1,...,km), contains(k l1)
;   intersection(l2,...,ln,k1,...,km), otherwise
;}
(defun intersectionS(l k) 
    (cond
        ((or (null l)(null k)) nil)
        ((contains k (car l)) (cons (car l) (intersectionS (cdr l) k)))
        (T(intersectionS (cdr l) k))
    )
)

(print (intersectionS ()))