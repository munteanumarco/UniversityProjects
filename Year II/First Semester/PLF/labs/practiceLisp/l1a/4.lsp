;Write a function to return the n-th element of a list, or NIL if such an element does not exist.

;findNthElem(l1,...,ln,p,cp) = {
;   nil, n = 0
;   l1, cp = p
;   findNthElem(l2,...,ln,p,cp+1), otherwise
;}


(defun findNthElem (l p cp)
    (cond
        ((null l) nil)
        ((= cp p) (car l))
        ((< cp p) (findNthElem (cdr l) p (+ cp 1)))
    )
)

(defun mainFind (l p) (findNthElem l p 1))


;(print (mainFind '(1 2 3 4 5) 6))

;checkAtom(l1,...,ln,e) = {
;   nil, n = 0
;   checkAtom(l1,e) U checkAtom(l2,...,ln,e), l1 is list
;   true, l1 = e
;   checkAtom(l2,...,ln, e), otherwise
;}

(defun checkAtom (l e)
    (cond
        ((null l) nil)
        ((listp (car l)) (or (checkAtom (car l) e) (checkAtom (cdr l) e)))
        ((and (atom (car l)) (equal (car l) e)) T)
        (T (checkAtom (cdr l) e))
    )
)

;(print (checkAtom '(1 2 (3 4) 5) 4))


;listOfSublists(l1,l2,...,ln) = {
;   nil, n = 0
;   l1 U listOfSublists(l1,...,ln) U listOfSublists(l2,...,ln), l1 is list
;   listOfSublists(l2,...,ln), otherwise
;
;
;
;}

(defun listOfSublists (l)
    (cond
        ((null l) nil)
        ((listp (car l)) (list (car l) (listOfSublists(cdr l)) ) )
        (T(listOfSublists(cdr l)))
    )
)

(print (listOfSublists '(1 2 (3 (4 5)(6 7)) 8 (9 10)) ) )


