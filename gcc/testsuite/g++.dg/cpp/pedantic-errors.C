/* { dg-do preprocess } */
/* { dg-options "-std=c++98" } */

#if 1   
#endif 1 /* { dg-error "error: extra tokens at end of #endif directive" } */
