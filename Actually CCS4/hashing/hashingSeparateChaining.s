	.file	"hashingSeparateChaining.c"
	.text
	.def	printf;	.scl	3;	.type	32;	.endef
	.seh_proc	printf
printf:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movq	%r9, 56(%rbp)
	leaq	40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rbx
	movl	$1, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rbx, %r8
	movq	32(%rbp), %rdx
	movq	%rax, %rcx
	call	__mingw_vfprintf
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.globl	initializeTable
	.def	initializeTable;	.scl	2;	.type	32;	.endef
	.seh_proc	initializeTable
initializeTable:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L4
.L5:
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movb	$110, (%rax)
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movq	$0, 8(%rax)
	addl	$1, -4(%rbp)
.L4:
	cmpl	$9, -4(%rbp)
	jle	.L5
	nop
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "Input data: \12\0"
	.text
	.globl	inputData
	.def	inputData;	.scl	2;	.type	32;	.endef
	.seh_proc	inputData
inputData:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	$24, %ecx
	call	malloc
	movq	%rax, -8(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movq	-8(%rbp), %rax
	movl	$5, %edx
	movq	%rax, %rcx
	call	stringInput
	movq	-8(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 16(%rax)
	movq	-8(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC2:
	.ascii "count: %d\12\0"
	.text
	.globl	convertString_Option3
	.def	convertString_Option3;	.scl	2;	.type	32;	.endef
	.seh_proc	convertString_Option3
convertString_Option3:
	pushq	%rbp
	.seh_pushreg	%rbp
	subq	$64, %rsp
	.seh_stackalloc	64
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	movaps	%xmm6, 0(%rbp)
	.seh_savexmm	%xmm6, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	32(%rbp), %rcx
	call	strlen
	movl	%eax, -12(%rbp)
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L10
.L11:
	movl	-12(%rbp), %eax
	subl	-8(%rbp), %eax
	cltq
	leaq	-1(%rax), %rdx
	movq	32(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	pxor	%xmm6, %xmm6
	cvtsi2sdl	%eax, %xmm6
	pxor	%xmm0, %xmm0
	cvtsi2sdl	-8(%rbp), %xmm0
	movq	.LC1(%rip), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	pow
	mulsd	%xmm0, %xmm6
	movapd	%xmm6, %xmm1
	pxor	%xmm0, %xmm0
	cvtsi2sdl	-4(%rbp), %xmm0
	addsd	%xmm1, %xmm0
	cvttsd2sil	%xmm0, %eax
	movl	%eax, -4(%rbp)
	addl	$1, -8(%rbp)
.L10:
	movl	-8(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jl	.L11
	movl	-4(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	-4(%rbp), %eax
	movaps	0(%rbp), %xmm6
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	hash_Truncation
	.def	hash_Truncation;	.scl	2;	.type	32;	.endef
	.seh_proc	hash_Truncation
hash_Truncation:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	16(%rbp), %ecx
	movslq	%ecx, %rax
	imulq	$1717986919, %rax, %rax
	shrq	$32, %rax
	sarl	$2, %eax
	movl	%ecx, %r8d
	sarl	$31, %r8d
	subl	%r8d, %eax
	movl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%ecx, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC3:
	.ascii "hi\12\0"
.LC4:
	.ascii "strcmp: %d\12\0"
.LC5:
	.ascii "I went left;\0"
.LC6:
	.ascii "hello\12\0"
.LC7:
	.ascii "yes\12\0"
.LC8:
	.ascii "chain2 is null\12\0"
.LC9:
	.ascii "I added left\12\0"
.LC10:
	.ascii "end of insertion\12\0"
	.text
	.globl	insertChain
	.def	insertChain;	.scl	2;	.type	32;	.endef
	.seh_proc	insertChain
insertChain:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movb	$0, -1(%rbp)
	movq	24(%rbp), %rax
	movq	%rax, %rcx
	call	convertString_Option3
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movl	%eax, %ecx
	call	hash_Truncation
	movl	%eax, -32(%rbp)
	movl	-32(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	je	.L16
	movl	-32(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
	movl	-32(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L17
.L20:
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	24(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	strcmp
	movl	%eax, %edx
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movq	24(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	strcmp
	testl	%eax, %eax
	jns	.L18
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	leaq	.LC5(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L19
.L18:
	movq	24(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	strcmp
	testl	%eax, %eax
	jle	.L19
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -24(%rbp)
.L19:
	leaq	.LC6(%rip), %rax
	movq	%rax, %rcx
	call	printf
.L17:
	cmpq	$0, -24(%rbp)
	jne	.L20
	leaq	.LC7(%rip), %rax
	movq	%rax, %rcx
	call	printf
	cmpq	$0, -24(%rbp)
	jne	.L21
	leaq	.LC8(%rip), %rax
	movq	%rax, %rcx
	call	printf
.L21:
	movq	24(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	strcmp
	testl	%eax, %eax
	jns	.L22
	movq	-16(%rbp), %rax
	movq	24(%rbp), %rdx
	movq	%rdx, 8(%rax)
	leaq	.LC9(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L23
.L22:
	movq	24(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	strcmp
	testl	%eax, %eax
	jle	.L23
	movq	-16(%rbp), %rax
	movq	24(%rbp), %rdx
	movq	%rdx, 16(%rax)
.L23:
	movb	$1, -1(%rbp)
	jmp	.L24
.L16:
	movl	-32(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rax, %rdx
	movq	24(%rbp), %rax
	movq	%rax, 8(%rdx)
	movb	$1, -1(%rbp)
.L24:
	leaq	.LC10(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movzbl	-1(%rbp), %eax
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	searchDelete
	.def	searchDelete;	.scl	2;	.type	32;	.endef
	.seh_proc	searchDelete
searchDelete:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	nop
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC11:
	.ascii "[%d]: %s\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$208, %rsp
	.seh_stackalloc	208
	.seh_endprologue
	call	__main
	leaq	-176(%rbp), %rax
	movq	%rax, %rcx
	call	initializeTable
	call	inputData
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rdx
	leaq	-176(%rbp), %rax
	movq	%rax, %rcx
	call	insertChain
	call	inputData
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rdx
	leaq	-176(%rbp), %rax
	movq	%rax, %rcx
	call	insertChain
	call	inputData
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rdx
	leaq	-176(%rbp), %rax
	movq	%rax, %rcx
	call	insertChain
	movl	$0, -4(%rbp)
	jmp	.L28
.L30:
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	addq	%rbp, %rax
	subq	$168, %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	je	.L29
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	addq	%rbp, %rax
	subq	$168, %rax
	movq	(%rax), %rax
	movq	%rax, %rdx
	movl	-4(%rbp), %eax
	movq	%rdx, %r8
	movl	%eax, %edx
	leaq	.LC11(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	addq	%rbp, %rax
	subq	$168, %rax
	movq	(%rax), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L29
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	addq	%rbp, %rax
	subq	$168, %rax
	movq	(%rax), %rax
	movq	16(%rax), %rax
	movq	%rax, %rdx
	movl	-4(%rbp), %eax
	movq	%rdx, %r8
	movl	%eax, %edx
	leaq	.LC11(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	addq	%rbp, %rax
	subq	$168, %rax
	movq	(%rax), %rax
	movq	16(%rax), %rax
	movq	16(%rax), %rax
	movq	%rax, %rdx
	movl	-4(%rbp), %eax
	movq	%rdx, %r8
	movl	%eax, %edx
	leaq	.LC11(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	addq	%rbp, %rax
	subq	$168, %rax
	movq	(%rax), %rax
	movq	16(%rax), %rax
	movq	8(%rax), %rax
	movq	%rax, %rdx
	movl	-4(%rbp), %eax
	movq	%rdx, %r8
	movl	%eax, %edx
	leaq	.LC11(%rip), %rax
	movq	%rax, %rcx
	call	printf
.L29:
	addl	$1, -4(%rbp)
.L28:
	cmpl	$9, -4(%rbp)
	jle	.L30
	movq	__imp__getch(%rip), %rax
	call	*%rax
	movl	$0, %eax
	addq	$208, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC1:
	.long	0
	.long	1075576832
	.ident	"GCC: (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders) 11.2.0"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	malloc;	.scl	2;	.type	32;	.endef
	.def	stringInput;	.scl	2;	.type	32;	.endef
	.def	strlen;	.scl	2;	.type	32;	.endef
	.def	pow;	.scl	2;	.type	32;	.endef
	.def	strcmp;	.scl	2;	.type	32;	.endef
