//
//  stobj_class.h
//  ObjectCDemo
//
//  Created by 孫 濤 on 2017/10/20.
//  Copyright © 2017年 SunTao. All rights reserved.
//

#ifndef stobj_class_h
#define stobj_class_h

#include <stdio.h>

typedef struct stobjc_class *Class;

typedef char * SELE;
typedef void (*IMPT)(void);

typedef struct obj_imp
{
    SELE selector;
    IMPT imp;
} obj_imp;

typedef obj_imp * Method;

typedef struct stobjc_class{
    Class isa;
    Class super_class;
    Method *obj_methods;
} stobjc_class;

typedef struct Object {
    Class isa;
} *idt;

idt newObject(Class cls);

typedef Class * MetaClass;

Class initializeClass(void);

#endif /* stobj_class_h */
