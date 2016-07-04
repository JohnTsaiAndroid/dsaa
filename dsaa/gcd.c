//
//  gcd.c
//  dsaa
//
//  Created by JohnTsai on 16/7/4.
//  Copyright © 2016年 JohnTsai. All rights reserved.
//

#include "gcd.h"

// 辗转相除法获得最大公约数
int gcd(int a,int b)
{
    int dividor = a>b?a:b;
    int dividend = a<=b?a:b;
    while(dividor%dividend!=0){
        int remainder = dividor%dividend;
        dividor = dividend;
        dividend = remainder;
    }
    return dividend;
}
