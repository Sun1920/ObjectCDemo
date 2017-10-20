//
//  main.c
//  ObjectCDemo
//
//  Created by 孫 濤 on 2017/10/20.
//  Copyright © 2017年 SunTao. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "stobj_class.h"
#include "stobj_object.h"

int main(int argc, const char * argv[]) {
    
    Class myClass = malloc(sizeof(stobjc_class));
    idt obj = newObject(myClass);
    msgSend(obj, "printMyClass");
    free(obj);
    free(myClass);
    return 0;
}
