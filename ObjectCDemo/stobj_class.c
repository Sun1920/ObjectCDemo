//
//  stobj_class.c
//  ObjectCDemo
//
//  Created by 孫 濤 on 2017/10/20.
//  Copyright © 2017年 SunTao. All rights reserved.
//

#include "stobj_class.h"
#include <stdio.h>
#include <stdlib.h>

MetaClass initializeMetaClass(){
    static MetaClass p = NULL;
    if(NULL != p) return p;
    do {
        p = malloc(sizeof(Class));
    } while (p == NULL);
    return p;
}

Class initializeClass(){
    MetaClass metaClass = initializeMetaClass();
    static Class p = NULL;
    if(NULL != p) return p;
    do {
        p = malloc(sizeof(stobjc_class));
    } while (p == NULL);
    p->isa = *metaClass;
    return p;
}

void printMySelf() {
    printf("stobj_class\n");
}

idt newObject(Class cls) {
    struct Object *obj = malloc(sizeof(idt));
    cls->super_class = cls;
    cls->isa = cls;
    cls->obj_methods = malloc(sizeof(Method));
    IMPT func = &printMySelf;
    obj_imp *imp = malloc(sizeof(obj_imp));
    imp->selector = "printMyClass";
    imp->imp = func;
    Method method = imp;
    
    Method *methods = malloc(sizeof(Method));
    methods[0] = method;
    cls->obj_methods = methods;
    obj->isa = cls;
    return obj;
}
