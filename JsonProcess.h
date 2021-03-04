#ifndef __JSONPROCESS_H__
#define __JSONPROCESS_H__

#include <json-c/json.h>
#include <stdint.h>
#include <stdarg.h>

typedef struct single_component{
    uint8_t* key;
    uint16_t value;
}single_component;

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

#endif