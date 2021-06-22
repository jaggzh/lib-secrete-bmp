test: test.c libsecretebmp.c libsecretebmp.h
	cc -o test test.c libsecretebmp.c

vi:
	vim Makefile test.c libsecretebmp.c libsecretebmp.h original_bmppost_reference.c
