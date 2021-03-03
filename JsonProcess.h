#ifndef __JSONPROCESS_H__
#define __JSONPROCESS_H__

#include <json-c/json.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct json_single_component{
    uint8_t* key;
    uint16_t value;
}single_component;

typedef struct json_array_component{
    uint8_t* key;
    uint32_t value[10];
    uint8_t length;
}array_component;

/*
    @feature: create json_object from model
    @params:
        *add_smt_to_obj: point to callback function
        num_of: number of model
        ... : model
    @return: a point to json_object
*/
extern json_object* create_json_obj_from(void (*add_smt_to_obj)(json_object*, void*), int num_of, ...);

void add_single_component_to_obj(json_object *j, void* com);
void add_obj_to_obj(json_object *j, void* com);
void add_array_component_to_obj(json_object *j, void* com);

#endif