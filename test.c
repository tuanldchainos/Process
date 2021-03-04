#include "JsonProcess.h"

int main(){
    single_component id = {"id", 1};
    single_component adr = {"adr", 1040};
    single_component cct = {"cct", 50};
    json_object *j1 = create_json_obj_from(add_single_component_to_obj, 3, &id, &adr, &cct);
    char *str1 = json_object_to_json_string(j1);

    printf("\n%s\n", str1);
}

