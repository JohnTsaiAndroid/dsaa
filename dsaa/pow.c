//
//  pow.c
//  dsaa
//
//  Created by JohnTsai on 16/7/4.
//  Copyright © 2016年 JohnTsai. All rights reserved.
//

#include <stdio.h>
double pow_recursive(double a,int n){
    if (n==0)
        return 1;
    if(n==1)
        return a;
    double t = pow_recursive(a,n/2);
    return t*t*pow_recursive(a,n%2);
}

double pow_non_recursive(double a,int n){
    double result = 1;
    while(n){
        if(n%2==1) result*=a;
        a*=a;
        n/=2;
    }
    return result;
}