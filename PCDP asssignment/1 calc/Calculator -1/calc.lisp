
(defvar a)
(defvar b)
(defvar c)
(defvar d)


(write-line " Enter two numbers in binary format with prefix #b : ")

	
	(setf a(read))
	(setf b(read))

	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(+ a b))
				(print "ADDITION in binary: ")
				(format t " ~b" c )
				(print "ADDITION in decimal: ")
				(print c))))

	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(- a b))
				(print "SUBTRACTION in binary: ")
				(format t " ~b" c )
				(print "SUBTRACTION in decimal: ")
				(print c))))

 	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(* a b))
				(print "MULTIPLICATION in binary: ")
				(format t " ~b" c )
				(print "MULTIPLICATION IN DECIMAL: ")
				(print c))))
	
	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(* a a))
				(print "SQUARE in binary: ")
				(format t " ~b" c )
				(print "SQUARE OF 1st NUMBER  : ")
				(print c))))

	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(* b b b))
				(print "CUBE OF 2ND NUMBER : ")
				(print c))))	


	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(sin a))
				(print "SINE OF 1ST NUMBER : ")
				(print c))))

	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(tan a))
				(print "TAN OF 1ST NUMBER : ")
				(print c))))

	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(cos a))
				(print "COSINE OF 1ST NUMBER : ")
				(print c))))

	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(min a b))
				(print "MINIMUM NUMBER : ")
				(print c))))

	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(max a b))
				(print "MAXIMUM NUMBER : ")
				(print c))))

       

(exit)

;output:
;student@B4L0106:~$ sbcl
;This is SBCL 1.0.55.0.debian, an implementation of ANSI Common Lisp.
;More information about SBCL is available at <http://www.sbcl.org/>.

;SBCL is free software, provided as is, with absolutely no warranty.
;It is mostly in the public domain; some portions are provided under
;BSD-style licenses.  See the CREDITS and COPYING files in the
;distribution for more information.
;* (load "cal1.lisp")
 ;Enter two numbers in binary format with prefix #b : 
;8
;6

;"ADDITION in binary: "  1110
;"ADDITION in decimal: " 
;14 
;"SUBTRACTION in binary: "  10
;"SUBTRACTION in decimal: " 
;2 
;"MULTIPLICATION in binary: "  110000
;"MULTIPLICATION IN DECIMAL: " 
;48 
;"SQUARE in binary: "  1000000
;"SQUARE OF 1st NUMBER  : " 
;64 
;"CUBE OF 2ND NUMBER : " 
;216 
;"SINE OF 1ST NUMBER : " 
;0.98935825 
;"COSINE OF 1ST NUMBER : " 
;-0.14550003 
;"TAN OF 1ST NUMBER : " 
;-6.799711 
;"MINIMUM NUMBER : " 
;6 
;"MAXIMUM NUMBER : " 
;8 

; file: /home/student/cal1.lisp
; in: EXIT
;     (EXIT)
; 
; caught STYLE-WARNING:
;   undefined function: EXIT
; 
; compilation unit finished
;   Undefined function:
;     EXIT
;   caught 1 STYLE-WARNING condition
;5 
;debugger invoked on a UNDEFINED-FUNCTION in thread
;#<THREAD "initial thread" RUNNING {1002998D33}>:
 ; The function COMMON-LISP-USER::EXIT is undefined.

;Type HELP for debugger help, or (SB-EXT:QUIT) to exit from SBCL.

;restarts (invokable by number or by possibly-abbreviated name):
 ; 0: [RETRY   ] Retry EVAL of current toplevel form.
  ;1: [CONTINUE] Ignore error and continue loading file "/home/student/cal1.lisp".
  ;2: [ABORT   ] Abort loading file "/home/student/cal1.lisp".
  ;3:            Exit debugger, returning to top level.

;("undefined function")
;0] 

