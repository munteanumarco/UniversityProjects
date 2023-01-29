;Write a function that inserts in a linear list a given atom A after the 2nd, 4th, 6th, ... element

;insertAtomAfter(l1,...,ln,a,cp) = {
;   nil, n = 0
;   l1 U a U insertAtomAfter(l2,...,ln,a,cp+1), cp%2=0
;   l1 U insertAtomAfter(l2,...,ln,a,cp+1), otherwise
;}

(defun insertAtomAfter (l a cp)
    (cond
        ((null l) nil)
        ((= (mod cp 2) 0) (cons (car l) (cons a (insertAtomAfter (cdr l) a (+ cp 1)))))
        (T(cons (car l) (insertAtomAfter (cdr l) a (+ cp 1))))
    )
)

;(print (insertAtomAfter '(1 2 3 4 5 6 7 8 9 10) 0 1))

;Write a function to get from a given list the list of all atoms, on any level, but reverse order.

;insertPos(l1,...,ln,e,p,cp) = {
;   nil, n = 0
;   e U l1 U insertPos(l2,...,ln,e,p,cp+1), cp = p
;   l1 U insertPos(l1,...,ln,e,p,cp+1), otherwise
;}

(defun insertPos (l e p cp) 
    (cond
        ((null l) nil)
        ((= cp p) (cons e (cons (car l) (insertPos (cdr l) e p (+ cp 1)))))
        (T(cons (car l) (insertPos (cdr l) e p (+ cp 1))))
    )
)

;reverseAtoms(l1,...,ln,k) = {
;   nil, n = 0
;   reverseAtoms(l1) U reverseAtoms(l2,...,ln) ,l1 is list
;   insertPost(k,l1,1,1) U reverseAtoms(l2,...,ln), otherwise
;
;}


(defun reverseAtoms (l k)
    (cond 
        ((null l) k)
        ((listp (car l)) (or (reverseAtoms(car l) k) (reverseAtoms (cdr l) k) ))
        (T(or (insertPos k (car l) 1 1) (reverseAtoms (cdr l) k)))
    )
)


(print (reverseAtoms '(((A B) C)(D E)) ()))

