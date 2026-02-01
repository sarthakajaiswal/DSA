#
#    @GOAL:  study fast call calling convenction 
#    @DATE:  01 February 2026 
# 

void func(u64 a, u64 b, u64 c, u64 d, u64 e, u64 f) 

int main() 
{
    func(100, 200, 300, 400, 500, 600);  
} 


// fastcall calling convenction 
// 64 bit recent compilers 

// 6 params are given on registers -> forward order 
// if more then pushed on stack -> reverse order 
// and the parameters(if any) pushed on stack are to be cleared by caller 

main: 
    pushq   %rbp 
    movlq   %rsp, %rbp 

    movq    $100, %rdi 
    movq    $200, %rsi 
    movq    $300, %rdx 
    movq    $400, %rcx 
    movq    $500, %r8 
    movq    $600, %r9 
    call    func 



// ------------------- 

C calling convenction 
-> 
stack is cleared by caller 

Standard calling convenction 
-> 
stack is cleared by callee 