;llvm-as essai.ll -f -o essai.bc
;lli essai.bc
define i32 @main() {

	%x = alloca i32

	store i32 123, i32* %x
	%val = load i32* %x

	ret i32 0
}