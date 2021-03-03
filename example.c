#include "JsonProcess.h"

int main(){
    single_component id = {"id", 1};
    single_component adr = {"adr", 1040};
    single_component cct = {"cct", 50};
    json_object *j1 = create_json_obj_from(add_single_component_to_obj, 3, &id, &adr, &cct);
    char *str1 = json_object_to_json_string(j1);

    array_component device = {"device", {1, 2, 3}, 3};
    array_component device2 = {"device2", {1, 2, 3}, 3};
    json_object *j2 = create_json_obj_from(add_array_component_to_obj, 2, &device, &device2);
    char *str2 = json_object_to_json_string(j2);

    printf("\n%s\n", str1);
    printf("\n%s\n", str2);
}

