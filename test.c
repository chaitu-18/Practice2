#include <stdio.h>
#include <json-c/json.h>

int main() {
    FILE *fp;
    char buffer[1024];

    struct json_object *parsed_json;
    struct json_object *name;
    struct json_object *Place;
    struct json_object *Numbers;

    size_t n_Numbers;
    size_t i;

    // Open the file for reading
    fp = fopen("file1.json", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the file content
    size_t bytesRead = fread(buffer, 1, sizeof(buffer) - 1, fp);
    buffer[bytesRead] = '\0'; // Null-terminate the buffer
    fclose(fp);

    // Parse the JSON data
    parsed_json = json_tokener_parse(buffer);
    if (parsed_json == NULL) {
        fprintf(stderr, "Error parsing JSON\n");
        return 1;
    }

    // Debug prints to verify the JSON data
    printf("Parsed JSON: %s\n", json_object_to_json_string(parsed_json));

    // Extract the data from the JSON object
    if (!json_object_object_get_ex(parsed_json, "name", &name) ||
        !json_object_object_get_ex(parsed_json, "Place", &Place) ||
        !json_object_object_get_ex(parsed_json, "Numbers", &Numbers)) {
        fprintf(stderr, "Error retrieving JSON fields\n");
        json_object_put(parsed_json);
        return 1;
    }

    // Print the name and place
    printf("Name: %s\n", json_object_get_string(name));
    printf("Place: %s\n", json_object_get_string(Place));

    // Get and print numbers
    n_Numbers = json_object_array_length(Numbers);
    printf("There are %zu numbers\n", n_Numbers);

    for (i = 0; i < n_Numbers; i++) {
        struct json_object *Number = json_object_array_get_idx(Numbers, i);
        printf("%zu. %s\n", i, json_object_get_string(Number));
    }

    // Clean up
    json_object_put(parsed_json);

    return 0;
}
