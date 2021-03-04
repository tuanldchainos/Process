#include "JsonProcess.h"
#include <stdio.h>
#include <stdlib.h>

void add_single_component_to_obj(json_object *j, void* com){
    single_component *dt = (single_component*)com;
    json_object_object_add(j, dt->key, json_object_new_int(dt->value));
    return;
}


json_object* create_json_obj_from(void (*modelFunc)(json_object*, void*), int num_of, ...){
    va_list args_list;
    json_object *jobj = json_object_new_object();
    typedef void *com;

    va_start(args_list, num_of);

    for(int i = 0; i< num_of; i++){
        (*modelFunc)(jobj, va_arg(args_list, com));
    }

    va_end(args_list);
    return jobj;
}



