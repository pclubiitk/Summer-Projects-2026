def find_item(inventory, condition):
    for idx, item in enumerate(inventory):
        if condition(item):
            return item, idx
    return None, -1