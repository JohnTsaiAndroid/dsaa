//
//  fibo.c
//  dsaa
//
//  Created by JohnTsai on 16/7/4.
//  Copyright © 2016年 JohnTsai. All rights reserved.
//

#include "fibo.h"
#include <math.h>

//获得斐波那契数列中的第n个数
//递归
int fibonacci_recursive(int n)
{
    if(n==0||n==1) return n;
    return fibonacci_recursive(n-1)+fibonacci_recursive(n-2);
}

int fibonacci_non_recursive(int n)
{
    double constant_a = (1+sqrt(5))/2;
    double constant_b = (1-sqrt(5))/2;
    double constant_c = sqrt(5)/5;
    double v1  = constant_c*(pow(constant_a,n)-pow(constant_b,n));
    return (int)v1;
}