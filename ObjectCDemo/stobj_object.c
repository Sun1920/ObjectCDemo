//
//  stobj_object.c
//  ObjectCDemo
//
//  Created by 孫 濤 on 2017/10/20.
//  Copyright © 2017年 SunTao. All rights reserved.
//

#include "stobj_object.h"
#include <string.h>

int msgSend(idt obj, SELE sel) {
    Class class = obj->isa;
    for (int i = 0; i < 1; i++) {
        if (strcmp((class->obj_methods)[i]->selector, sel) == 0) {
            if ((class->obj_methods)[i]->imp) {
                Method *methods = class->obj_methods;
                Method method = methods[0];
                method->imp();
                return 1;
            }
        }
    }
    return 0;
}
