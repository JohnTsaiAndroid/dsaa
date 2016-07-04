//
//  main.c
//  dsaa
//
//  Created by JohnTsai on 16/7/4.
//  Copyright © 2016年 JohnTsai. All rights reserved.
//

#include <stdio.h>
#include "pow.h"
#include "gcd.h"

int main(int argc, const char * argv[]) {
    printf("%.0f的%d次方等于%.0f\n",5.0,3,pow_recursive(5.0,3));
    printf("%.0f的%d次方等于%.0f\n",5.0,3,pow_non_recursive(5.0,3));
    
    int a = 1989;
    int b = 867;
    int c = gcd(a,b);
    printf("%d和%d的最大公约数是%d\n",a,b,c);
    
    return 0;
}
