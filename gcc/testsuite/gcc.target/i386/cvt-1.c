/* { dg-do compile { target i?86-*-* x86_64-*-* } } */
/* { dg-options "-O2 -march=k8 -mfpmath=sse" } */
/* { dg-final { scan-assembler "cvttsd2si" } } */
/* { dg-final { scan-assembler "cvttss2si" } } */
int a,a1;
double b;
float b1;
t()
{
	a=b;
	a1=b1;
}
