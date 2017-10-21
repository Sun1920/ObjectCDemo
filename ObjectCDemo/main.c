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
    Class const class = initializeClass();
    idt obj = newObject(class);
    msgSend(obj, "printMyClass");
    free(obj);
    free(class);
    return 0;
}
