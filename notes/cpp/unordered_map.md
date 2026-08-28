> Referenced doc: [https://cplusplus.com/reference/unordered_map/unordered_map/](https://cplusplus.com/reference/unordered_map/unordered_map/)

# `std::unordered_map`

## const and varible behavior
- `operator[]` can be used to insert as well as fetch elements from the map


#### const
- `operator[]` is not available for constant maps as it can modify the value. use `find(key)` or `at(key)`