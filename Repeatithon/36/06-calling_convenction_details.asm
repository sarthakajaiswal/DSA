void func(u64 a, u64 b, u64 c, u64 d, u64 e, u64 f); 

int main() 
{
    func(100, 200, 300, 400, 500, 600); 
}  

main: 
    pushq   %rbp 
    movq    %rsp, &rbp 

    movq    $100, %rdi 
    movq    $200, %rsi 
    movq    $300, %rdx 
    movq    $400, %rdx 
    movq    $500, %r8 
    movq    %600, %r9 
    call    func 

    leave   
    ret 

#==================================== 

void func(u64 a, u64 b, u64 c, u64 d, u64 e, u64 f) 

int main() 
{
    func(100, 200, 300, 400, 500, 600); 
} 

main: 
    pushq   %rbp 
    movq    %rsp, &rbp 

    movq    $100, %rdi 
    movq    $200, %rsi 
    movq    $300, %rdx 
    movq    $400, %rcx 
    movq    $500, %r8 
    movq    $600, %r9 
    call    func 

#============================== 

void func(u64 a, u64 b, u64 c, u64 d, u64 e, u64 f); 

int main() 
{
    func(100, 200, 300, 400, 500, 600); 
}  

main: 
    pushq   %rbp 
    movq    %rsp, %rbp 

    movq    $100, %rdi 
    movq    $200, %rsi 
    movq    $300, %rdx 
    movq    $400, %rcx 
    movq    $500, %r8 
    movq    $600, %r9 
    call    func 

#================= 
void func(u64 a, u64 b, u64 c, u64 d, u64 e, u64 f); 

int main() 
{
    func(100, 200, 300, 400, 500, 600); 
} 

main: 
    pushq   %rbp 
    movq    %esp, %rbp 

    movq    $100, %rdi 
    movq    $200, %rsi 
    movq    $300, %rdx 
    movq    $400, %rcx 
    movq    $500, %r8 
    movq    $600, %r9 
    call    func 

#======================== 
void func(u64 a, u64 b, u64 , u64 d, u64 e, u64 f); 

int main(void) 
{
    func(100, 200, 300, 400, 500, 600); 
} 

main: 
    pushq   %rbp 
    movq    %rsp, %rbp 

    movq    $100, %rdi 
    movq    $200, %rsi 
    movq    $300, %rdx 
    movq    $400, %rcx 
    movq    $500, %r8 
    movq    $600, %r9 
    call    func 

    
