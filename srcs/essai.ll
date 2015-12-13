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
	%x2 = alloca i32

	%x3 = add i32 0, 3
	store i32 %x3, i32* %x2

	%x4 = load i32* %x2
	%x5 = add i32 0, 2


	%x6= add i32 %x4, %x5
	store i32 %x6, i32* %x1

	%x7 = load i32* %x1
	ret i32 %x7
}
	;int x;
	;int y;
  	;y=3;
  	;x=y+2;


define i32 @testParse(i32 %arg){

	%x1 = alloca i32


	%x2 = alloca float


	;%x3 = load float* %x2

	%x4 = fadd float 0.0, 3.500000
	store float %x4, float* %x2

	;%x5 = load i32* %x1

	%x6 = load float* %x2
	%x7 = add i32 0, 2
	%x8 = fadd float %x6, %x7
	store i32 %x8, i32* %x1


	%x9 = load i32* %x1
	ret i32 %x9

	;int x;
	;float y;
  	;y=3.5;
  	;x=y+2;


}

define i32 @main() {
	;%retval = call i32 @mafonction2(i32 42)
	%retval = call i32 @testParse(i32 42)

	; appelle printf avec le res renvoye par mafonction
	call i32 (i8*, ...)* @printf(i8* getelementptr ([7 x i8]* @str , i32 0, i32 0),i32 %retval)
	ret i32 0
}

