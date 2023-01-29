;Sum of elements with and without collector variable

;suma(l1,...,ln) = {
;   0, n = 0
;   l1 + suma(l2,...,ln), otherwise
;}


(defun suma (l)
    (cond
        ((null l) 0)
        (T (+ (car l) (suma (cdr l))))
    )
)

(print (suma '(1 2 3 4 5)))

;sumaC(l1,...,ln, c) = {
;   c, n = 0
;   suma(l2,...,ln, c + l1), otherwise
;}


(defun sumaC (l c)
    (cond 
        ((null l) c)
        (T (sumaC (cdr l) (+ c (car l))))
    )
)

(defun mainSumaC(l) (sumaC l 0))
(print (mainSumaC '(1 2 3 4 5)))

