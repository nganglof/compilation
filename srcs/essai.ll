; llvm-as essai.ll -f -o essai.bc
; lli essai.bc

; un comm
; declare une const ici une chaine "=> %d"
@str = constant [7 x i8] c"=> %d\0A\00"
; declare une fonction, sans la definir (printf)
declare i32 @printf(i8*, ...)
; declare et defini la fonction mafonction


define i32 @mafonction(i32 %arg) {

	;;alloca
	%x1 = alloca i32

	%x2 = add i32 0, 1
	%x3 = add i32 0, 2
	%x4= add i32 %x2, %x3
	store i32 %x4, i32* %x1

	;retour
	%x5 = load i32* %x1
	ret i32 %x5
}
	;int y;
	;x=1+2;

define i32 @mafonction2(i32 %arg) {


%x1 = alloca i32
%x2 = add i32 0, 5
store i32 %x2, i32* %x1

%x3 = load i32* %x1
%x4 = sub i32 %x3, 1
store i32 %x4, i32* %x1

%x7 = load i32* %x1
ret i32 %x7



}
	;int x;
	;int y;
  	;y=3;
  	;x=y+2;

define i32 @foo(i32 %x1){
%x2 = sub i32 %x1, 1
%x3 = add i32 0, %x2
ret i32 %x3


}
define i32 @plop(i32 %x1){
%x2 = alloca i32
%x3 = alloca i32

%x4 = alloca i32

%x5 = load i32* %x2
%x6 = add i32 0, 5
store i32 %x6, i32* %x2
%x7 = load i32* %x3
%x8 = add i32 0, 0
store i32 %x8, i32* %x3
br label %label0
label0:
%x9 = load i32* %x3
%x10 = load i32* %x2
%x11 = icmp slt i32 %x9, %x10
br i1 %x11, label %label1, label %label3
label1:
%x14 = load i32* %x4
%x15 = add i32 %x14, 1
store i32 %x15, i32* %x4

br label %label2
label2:
%x12 = load i32* %x3
%x13 = add i32 %x12, 1
store i32 %x13, i32* %x3

br label %label0
label3:
%x16 = load i32* %x4
ret i32 %x16

}





define i32 @main() {
	;%retval = call i32 @mafonction2(i32 42)
	%retval = call i32 @plop(i32 4)

	; appelle printf avec le res renvoye par mafonction
	call i32 (i8*, ...)* @printf(i8* getelementptr ([7 x i8]* @str , i32 0, i32 0),i32 %retval)
	ret i32 0
}
