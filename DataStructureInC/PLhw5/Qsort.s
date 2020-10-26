	.file	"Qsort.c"
	.comm	i,4,4
	.comm	students,40,32
	.globl	names
	.section	.rodata
.LC0:
	.string	"John"
.LC1:
	.string	"Eric"
.LC2:
	.string	"Paul"
.LC3:
	.string	"Carol"
.LC4:
	.string	"Jim"
	.data
	.align 4
	.type	names, @object
	.size	names, 20
names:
	.long	.LC0
	.long	.LC1
	.long	.LC2
	.long	.LC3
	.long	.LC4
	.globl	grades
	.align 4
	.type	grades, @object
	.size	grades, 20
grades:
	.long	1119092736
	.long	1117257728
	.long	1117782016
	.long	1116471296
	.long	1114636288
	.text
	.globl	compare1
	.type	compare1, @function
compare1:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	8(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -8(%ebp)
	movl	-4(%ebp), %eax
	flds	4(%eax)
	movl	-8(%ebp), %eax
	flds	4(%eax)
	fxch	%st(1)
	fucomip	%st(1), %st
	fstp	%st(0)
	jbe	.L6
	movl	$1, %eax
	jmp	.L4
.L6:
	movl	$-1, %eax
.L4:
	leave
	ret
	.size	compare1, .-compare1
	.globl	compare2
	.type	compare2, @function
compare2:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	subl	$8, %esp
	pushl	%edx
	pushl	%eax
	call	strcmp
	addl	$16, %esp
	leave
	ret
	.size	compare2, .-compare2
	.section	.rodata
.LC6:
	.string	"(1)"
.LC7:
	.string	"(%s, %f) "
.LC8:
	.string	"(2)"
	.text
	.globl	main
	.type	main, @function
main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$20, %esp
	movl	$0, i
	jmp	.L10
.L11:
	movl	i, %eax
	movl	i, %edx
	movl	names(,%edx,4), %edx
	movl	%edx, students(,%eax,8)
	movl	i, %eax
	movl	i, %edx
	flds	grades(,%edx,4)
	fstps	students+4(,%eax,8)
	movl	i, %eax
	addl	$1, %eax
	movl	%eax, i
.L10:
	movl	i, %eax
	cmpl	$4, %eax
	jle	.L11
	movl	$students, -12(%ebp)
	pushl	$compare1
	pushl	$8
	pushl	$5
	pushl	-12(%ebp)
	call	qsort
	addl	$16, %esp
	subl	$12, %esp
	pushl	$.LC6
	call	printf
	addl	$16, %esp
	movl	$0, i
	jmp	.L12
.L13:
	movl	i, %eax
	flds	students+4(,%eax,8)
	movl	i, %eax
	movl	students(,%eax,8), %eax
	leal	-8(%esp), %esp
	fstpl	(%esp)
	pushl	%eax
	pushl	$.LC7
	call	printf
	addl	$16, %esp
	movl	i, %eax
	addl	$1, %eax
	movl	%eax, i
.L12:
	movl	i, %eax
	cmpl	$4, %eax
	jle	.L13
	subl	$12, %esp
	pushl	$10
	call	putchar
	addl	$16, %esp
	pushl	$compare2
	pushl	$8
	pushl	$5
	pushl	-12(%ebp)
	call	qsort
	addl	$16, %esp
	subl	$12, %esp
	pushl	$.LC8
	call	printf
	addl	$16, %esp
	movl	$0, i
	jmp	.L14
.L15:
	movl	i, %eax
	flds	students+4(,%eax,8)
	movl	i, %eax
	movl	students(,%eax,8), %eax
	leal	-8(%esp), %esp
	fstpl	(%esp)
	pushl	%eax
	pushl	$.LC7
	call	printf
	addl	$16, %esp
	movl	i, %eax
	addl	$1, %eax
	movl	%eax, i
.L14:
	movl	i, %eax
	cmpl	$4, %eax
	jle	.L15
	subl	$12, %esp
	pushl	$10
	call	putchar
	addl	$16, %esp
	movl	$0, %eax
	movl	-4(%ebp), %ecx
	leave
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 5.2.0"
