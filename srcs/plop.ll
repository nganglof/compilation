; un comm
; declare une const ici une chaine "=> %d"
@str = constant [7 x i8] c"=> %d\0A\00"
; declare une fonction, sans la definir (printf)
declare i32 @printf(i8*, ...)
; declare et defini la fonction mafonction
define i32 @mafonction(i32 %arg) {

	%x = mul i32 %arg, 2
	%y = add i32 %x , 32
	%z = sub i32 %y , %x
	%a = sdiv i32 %z, 4
	ret i32 %a
}

define i32 @mafonction2(i32 %arg) {

	%f = alloca float
	%x = fadd float 0.0, 3.500000
	store float %x, float* %f

	%x6 = load float* %f
	%conv = fptosi float %x6 to i32
	%x7 = add i32 %arg, %conv


	ret i32 %x7
}

define i32 @main() {
	%retval = call i32 @mafonction2(i32 42)
	; appelle printf avec le res renvoye par mafonction
	call i32 (i8*, ...)* @printf(i8* getelementptr ([7 x i8]* @str , i32 0, i32 0),i32 %retval)
	ret i32 0
}


;%conv = sitofp i32 %a to float
;%conv1 = fptosi float %add to i32